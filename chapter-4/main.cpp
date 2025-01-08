#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QString>
#include <QSharedDataPointer>
#include "Employee.h"
#include <QPointer>
#include <QScopedPointer>
#include <QScopedArrayPointer>
#include <memory>

class MyObject {
public:
    MyObject() {
        qDebug() << "MyObject is created";
    }
    MyObject(QString a) :a(a) {
        qDebug() << "MyObject is created";
    }
    ~MyObject() {
        qDebug() << "MyObject is destroyed";
    }

    QString a;
};
void e1() {
    QSharedPointer<MyObject> ptr1(new MyObject);
    QSharedPointer<MyObject> ptr2 = ptr1;

    ptr1->a = "abc";
    qDebug() << ptr2->a;
}

class MySharedObject : public QSharedData {
public:
    MySharedObject() {
        qDebug() << "MySharedObject is created";
    }
    ~MySharedObject() {
        qDebug() << "MySharedObject is destroyed";
    }

    QString a;
};
void e2() { // copy on write = COW
    QSharedDataPointer<MySharedObject> ptr1(new MySharedObject);
    ptr1->a = "abc";
    QSharedDataPointer<MySharedObject> ptr2 = ptr1;
    QSharedDataPointer<MySharedObject> ptr3 = ptr2;

    ptr2->a = "qwe";
    qDebug() << ptr1->a;
    qDebug() << ptr2->a;
    qDebug() << ptr3->a;
}

void e3() {
    qDebug() << "Creating emp1";
    Employee e1(123, "John");

    qDebug() << "Coping emp1 to emp2";
    Employee e2 = e1;

    qDebug() << "Modify emp1";
    e1.setName("Bob");
}

class MyQObject : public QObject {
public:
    MyQObject(QString a) : a(a) {
        qDebug() << "MyQObject is created";
    }
    ~MyQObject() {
        qDebug() << "MyQObject is destroyed";
    }

    QString a;
};
void e4() {
    QPointer<MyQObject> obj(new MyQObject("abc"));
    QPointer<MyQObject> obj2 = obj;
    qDebug() << obj.get()->a;
    qDebug() << obj2.get()->a;

    obj.get()->a = "some text";
    qDebug() << obj.get()->a;
    qDebug() << obj2.get()->a;

    delete obj;

    if (obj.isNull()) qDebug() << "obj = nullptr";
    if (obj2.isNull()) qDebug() << "obj2 = nullptr";
}

void e5() {
    QSharedPointer<int> sharedPtr = QSharedPointer<int>::create(42);
    QWeakPointer<int> weakPtr = sharedPtr;

    if (!weakPtr.isNull()) {
        qDebug() << "The object is still alive";
    }

    sharedPtr.clear();

    if (weakPtr.isNull()) {
        qDebug() << "The object has beed deleted";
    }
}

void e6() {
    std::unique_ptr<MyObject> ptr(new MyObject("abc"));
    MyObject* ptr2 = ptr.release();

    qDebug() << ptr2->a;
    delete ptr2;
}
void e7() {
    std::unique_ptr<MyObject> arr(new MyObject[5]);
    for (int i = 0; i < 5 ; i++) {
        arr.get()[i].a = "obj #" + QString::number(i);
    }

    for (int i = 0; i < 5 ; i++) {
        qDebug() << arr.get()[i].a;
    }

    MyObject* rawArr = arr.release();

    for (int i = 0; i < 5 ; i++) {
        qDebug() << rawArr[i].a;
    }

    delete[] rawArr;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    e7();

    return a.exec();
}
