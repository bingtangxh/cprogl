#ifndef SALESMAN_H
#define SALESMAN_H

#include "Employee.h"

class Salesman : virtual public Employee {
protected:
    double sales;
    double salesRate;

public:
    Salesman() : Employee(), sales(0.0), salesRate(0.04) {}

    Salesman(int _id, const string& _name, int _age, double _weight, double _sales, double _rate = 0.04)
        : Employee(_id, _name, _age, _weight), sales(_sales), salesRate(_rate) {}

    void setSales(double s) { sales = s; }
    void setSalesRate(double r) { salesRate = r; }

    void pay() override {
        money = sales * salesRate;
    }

    void showType() const override {
        cout << "[销售类员工] ";
    }

    string getTypeName() const override { return "Salesman"; }

    void display() const override {
        showType();
        Employee::display();
        cout << "销售额: " << sales << ", 提成率: " << salesRate << endl;
    }

    void writeFile() const override {
    ofstream fout("employee.txt", ios::app);
    fout << "Salesman," << id << "," << name << ","
         << info.getAge() << "," << info.getWeight() << ","
         << sales << ',' << salesRate << "\n";
    fout.close();
    }

};

#endif
