#include "User.h"

User::User(QString username, QObject *parent)
    : m_username(username), QObject{parent}
{
    setObjectName(username);
}

QString User::username() const
{
    return m_username;
}

void User::sendMessage(const QString &message)
{
    emit messageSent(m_username, message);
}
