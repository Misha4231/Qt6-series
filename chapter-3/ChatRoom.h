#ifndef CHATROOM_H
#define CHATROOM_H

#include <QObject>
#include <QList>
#include <QString>
#include <QDebug>
#include "User.h"

class ChatRoom : public QObject
{
    Q_OBJECT
public:
    explicit ChatRoom(QObject *parent = nullptr);

    void addUser(const QString& username);
    void removeUser(const QString& username);

    ~ChatRoom();

private slots:
    void onMessageReceived(const QString& SenderUsername, const QString& message);

private:
    QList<User*> m_users;
};

#endif // CHATROOM_H
