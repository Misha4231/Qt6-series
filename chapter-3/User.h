#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QString username, QObject *parent = nullptr);

    QString username() const;
signals:
    void messageSent(const QString& SenderUsername, const QString& message);
public slots:
    void sendMessage(const QString& message);
private:
    QString m_username;
};

#endif // USER_H
