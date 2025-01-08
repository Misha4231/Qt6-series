#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "EmployeeData.h"

class Employee {
public:
    Employee() {
        d = new EmployeeData();
    }
    Employee(int id, const QString& name) {
        d = new EmployeeData();
        setId(id);
    }
    Employee(const Employee& other) : d(other.d) {}

    void setId(int id) {
        d.get()->id = id;

    }

    void setName(const QString& name) {
        d.get()->name = name;

    }
    int id() const {return d->id;}
    QString name() const {return d->name;}
private:
    QSharedDataPointer<EmployeeData> d;
};

#endif // EMPLOYEE_H
