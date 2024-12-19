#include <QCoreApplication>
#include "Task.h"
#include "TaskManager.h"
#include <QDebug>

// void onTaskCompleted(const QString& description) {
//     qInfo() << "[slot] task completed: " << description;
// }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Task* task1 = new Task("buy groceries", &a);
    // Task* task2 = new Task("fix bug", &a);

    // QObject::connect(task1, &Task::taskCompleted, onTaskCompleted);
    // QObject::connect(task2, &Task::taskCompleted, onTaskCompleted);

    // task1->complete();
    // task2->complete();

    TaskManager* taskManager = new TaskManager(&a);

    Task* task1 = new Task("task 1");
    Task* task2 = new Task("task 2");
    Task* task3 = new Task("task 3");

    taskManager->addTask(task1);
    taskManager->addTask(task2);
    taskManager->addTask(task3);

    taskManager->completeAllTasks();

    return a.exec();
}
