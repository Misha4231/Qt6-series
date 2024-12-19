#include "Task.h"

Task::Task(QString description, QObject *parent)
    : QObject{parent}, m_description(description), m_completed(false)
{}

void Task::complete()
{
    if (!m_completed) {
        m_completed = true;

        qInfo() << "Task completed: " << m_description;
        emit taskCompleted(m_description);
    }
}

QString Task::description()
{
    return m_description;
}

bool Task::completed()
{
    return m_completed;
}
