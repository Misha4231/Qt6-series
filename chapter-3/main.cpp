#include <QCoreApplication>
#include "ChatRoom.h"
#include <QDebug>
#include <QObjectList>

void printUser(User* user) {
    qInfo() << "User info: \n\tObject name:"
            << user->objectName() << "\n\tUsername:"
            << user->username() << "\n\tParent:"
            << user->parent()->objectName();

    const QObjectList& c = user->children();
    for (int i = 0; i < c.length(); i++) {
        qInfo() << "\tChild #" << (i + 1) << ":" << c[i]->objectName();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // User user1 = User("user_1", &a);
    // User* user2 = new User("user_2", &user1);
    // User* user3 = new User("user_3", user2);

    // printUser(&user1);
    // printUser(user2);
    // printUser(user3);

    ChatRoom chatRoom;

    chatRoom.addUser("Alice");
    chatRoom.addUser("Bob");

    auto* Alice = chatRoom.findChild<User*>("Alice");
    auto* Bob = chatRoom.findChild<User*>("Bob");

    if (Alice) Alice->sendMessage("Hello");
    if (Bob) Bob->sendMessage("Hiii");

    chatRoom.removeUser("Alice");
    chatRoom.removeUser("abc");

    return a.exec();
}
