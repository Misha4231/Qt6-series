#include <QCoreApplication>
#include <QString>
#include <QLatin1String>
#include <QDebug>

void latinStringExample() {
    QString type = "int";
    if (type == "auto" || type == "int") {
        qDebug() << "True";
    }

    if (type == QLatin1String("auto") || type == QLatin1String("int")) {
        qDebug() << "True";
    }
}

void latinStringExample2() {
    QString user = "John";
    QString action = "logged in";
    int sessionID = 42;

    // Using QString literals
    QString logMessage1 = "User " + user + " " + action + ", session ID: " + QString::number(sessionID);
    qDebug() << "Log 1:" << logMessage1;

    // Using QLatin1String
    QString logMessage2 = QLatin1String("User ") + user + QLatin1String(" ") + action + QLatin1String(", session ID: ") + QString::number(sessionID);
    qDebug() << "Log 2:" << logMessage2;
}
QString extractKey(const QString& str) {
    QString start = QStringLiteral("key=");
    if (str.startsWith(start)) {
        return str.mid(start.size());
    }

    return str;
}
QStringView extractKey2(QStringView str) {
    QStringView start = u"key=";
    if (str.startsWith(start)) {
        return str.mid(start.size());
    }

    return str;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << extractKey("key=12345");
    QString str = "key=abc";
    qDebug() << extractKey(str);

    const char16_t* str_c = new char16_t[6]{'k','e','y','=','1', '\0'};
    qDebug() << extractKey2(u"key=12345");
    QString str2 = "key=abc";
    qDebug() << extractKey2(str2);
    qDebug() << extractKey2(str_c);


    delete[] str_c;
    return a.exec();
}
