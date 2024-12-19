#include "TaskManager.h"

TaskManager::TaskManager(QObject *parent)
    : QObject{parent}
{}

void TaskManager::addTask(Task *task)
{
    task->setParent(this);
    connect(task, &Task::taskCompleted, this, &TaskManager::onTaskCompleted);

    m_tasks.append(task);
}

void TaskManager::completeAllTasks()
{
    for (Task* task : m_tasks) {
        task->complete();
    }
}

void TaskManager::onTaskCompleted(const QString &description)
{
    qInfo() << "[TaskManager] task completed: " << description;
}
