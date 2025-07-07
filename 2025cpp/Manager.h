#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : virtual public Employee {
protected:
    double monthlyPay;

public:
    Manager() : Employee(), monthlyPay(8000.0) {}

    Manager(int _id, const string& _name, int _age, double _weight, double _monthlyPay = 8000.0)
        : Employee(_id, _name, _age, _weight), monthlyPay(_monthlyPay) {}

    void setMonthlyPay(double pay) { monthlyPay = pay; }
    double getMonthlyPay() const { return monthlyPay; }

    void pay() override {
        money = monthlyPay;
    }

    void showType() const override {
        cout << "[经理类员工] ";
    }

    string getTypeName() const override { return "Manager"; }

    void display() const override {
        showType();
        Employee::display();
        cout << "月薪: " << monthlyPay << endl;
    }

    void writeFile() const override {
    ofstream fout("employee.txt", ios::app);
    fout << "Manager," << id << "," << name << ","
         << info.getAge() << "," << info.getWeight() << ","
         << monthlyPay << "\n";
    fout.close();
    }

};

#endif
