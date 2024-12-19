#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QList>
#include "Task.h"

class TaskManager : public QObject
{
    Q_OBJECT
public:
    explicit TaskManager(QObject *parent = nullptr);

    void addTask(Task* task);
    void completeAllTasks();

public slots:
    void onTaskCompleted(const QString& description);

private:
    QList<Task*> m_tasks;
};

#endif // TASKMANAGER_H
