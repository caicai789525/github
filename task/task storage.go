package main

import (
	"fmt"
	"log"
	"time"

	"gorm.io/driver/mysql"
	"gorm.io/gorm"
)

const (
	DBUsername = "root"
	DBPassword = "123456"
	DBHost     = "localhost"
	DBPort     = "3306"
	DBName     = "theleader"
)

type Task struct {
	gorm.Model
	Description string
	Status      string
	Deadline    time.Time
}

type CompletedTask struct {
	gorm.Model
	Description string
	Status      string
}

type teamTask struct {
	gorm.Model
	Description string
	Status      string
	Deadline    time.Time
}

type combineTask struct {
	gorm.Model
	Description string
	Status      string
	Deadline    time.Time
}

func initDB() (*gorm.DB, error) {
	dsn := fmt.Sprintf("%s:%s@tcp(%s:%s)/%s?charset=utf8mb4&parseTime=True&loc=Local", DBUsername, DBPassword, DBHost, DBPort, DBName)
	db, err := gorm.Open(mysql.Open(dsn), &gorm.Config{})
	if err != nil {
		return nil, err
	}

	// 自动迁移表结构
	db.AutoMigrate(&Task{}, &CompletedTask{})

	return db, nil
}

func insertTask(db *gorm.DB, description string, deadline time.Time) {
	task := Task{
		Description: description,
		Status:      "Pending",
		Deadline:    deadline,
	}

	result := db.Create(&task)
	if result.Error != nil {
		log.Fatal(result.Error)
	}
	fmt.Printf("Task '%s' inserted with deadline %s.\n", description, deadline.Format("2006-01-02 15:04:05"))
}

func completeTask(db *gorm.DB, taskID uint) {
	var task Task
	result := db.First(&task, taskID)
	if result.Error != nil {
		log.Fatal(result.Error)
	}

	completedTask := CompletedTask{
		Description: task.Description,
	}

	// 插入已完成任务表
	result = db.Create(&completedTask)
	if result.Error != nil {
		log.Fatal(result.Error)
	}

	// 删除未完成任务
	result = db.Delete(&task)
	if result.Error != nil {
		log.Fatal(result.Error)
	}

	fmt.Printf("Task '%s' completed and moved to completed_tasks.\n", task.Description)
}

func displayTasks(db *gorm.DB) {
	var tasks []Task
	result := db.Find(&tasks)
	if result.Error != nil {
		log.Fatal(result.Error)
	}

	fmt.Println("Pending Tasks:")
	for _, task := range tasks {
		fmt.Printf("%d: %s (Deadline: %s)\n", task.ID, task.Description, task.Deadline.Format("2006-01-02 15:04:05"))
	}
	fmt.Println()
}

func displayCompletedTasks(db *gorm.DB) {
	var completedTasks []CompletedTask
	result := db.Find(&completedTasks)
	if result.Error != nil {
		log.Fatal(result.Error)
	}

	fmt.Println("Completed Tasks:")
	for _, task := range completedTasks {
		fmt.Printf("%d: %s\n", task.ID, task.Description)
	}
	fmt.Println()
}

func deleteCompletedTasks(db *gorm.DB) {
	// 删除已完成任务（完成超过七天后）
	result := db.Where("created_at < ?", time.Now().Add(-168*time.Hour)).Delete(&CompletedTask{})
	if result.Error != nil {
		log.Fatal(result.Error)
	}
	fmt.Println("Completed tasks older than 168 hours deleted.")
}

func main() {
	db, err := initDB()
	if err != nil {
		log.Fatal(err)
	}

	// 插入任务
	insertTask(db, "Task 1", time.Now().Add(48*time.Hour))
	insertTask(db, "Task 2", time.Now().Add(72*time.Hour))

	// 显示所有任务
	displayTasks(db)

	// 完成任务
	completeTask(db, 1)

	// 显示已完成任务和未完成任务
	displayCompletedTasks(db)
	displayTasks(db)

	// 删除已完成任务（完成超过七天后）
	deleteCompletedTasks(db)
}
