#ifndef EMPLOYEEDATA_H
#define EMPLOYEEDATA_H

#include <QSharedData>
#include <QString>
#include <QDebug>

class EmployeeData : public QSharedData {
public:
    EmployeeData() : id(-1) {
        qDebug() << "EmployeeData is created";
    }
    EmployeeData(const EmployeeData& other)
        : QSharedData(other), id(other.id), name(other.name) {
        qDebug() << "EmployeeData is copied";
    }

    ~EmployeeData() {
        qDebug() << "EmployeeData is destroyed";
    }

    int id;
    QString name;
};


#endif // EMPLOYEEDATA_H
