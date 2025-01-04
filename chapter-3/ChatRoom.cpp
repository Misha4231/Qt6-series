#include "ChatRoom.h"

ChatRoom::ChatRoom(QObject *parent)
    : QObject{parent}
{}

void ChatRoom::addUser(const QString &username)
{
    User* newUser = new User(username, this);
    connect(newUser, &User::messageSent, this, &ChatRoom::onMessageReceived);

    m_users.append(newUser);
    qInfo() << username << "joined the chat room";
}

void ChatRoom::removeUser(const QString &username)
{
    for (User* user : m_users) {
        if (user->username() == username) {
            qInfo() << username << "left the chat room";
            m_users.removeOne(user);

            delete user;
            return;
        }
    }

    qInfo() << username << "is not found";
}

ChatRoom::~ChatRoom()
{
    qDeleteAll(m_users);
    m_users.clear();
}

void ChatRoom::onMessageReceived(const QString &SenderUsername, const QString &message)
{
    qInfo() << SenderUsername << ":" << message;
}
