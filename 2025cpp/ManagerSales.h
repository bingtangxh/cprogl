#ifndef MANAGERSALES_H
#define MANAGERSALES_H

#include "Manager.h"
#include "Salesman.h"

class ManagerSales : public Manager, public Salesman {
public:
    ManagerSales()
        : Employee(), Manager(), Salesman() {}

    ManagerSales(int _id, const string& _name, int _age, double _weight,
                 double _monthlyPay, double _sales, double _salesRate = 0.04)
        : Employee(_id, _name, _age, _weight),
          Manager(_id, _name, _age, _weight, _monthlyPay),
          Salesman(_id, _name, _age, _weight, _sales, _salesRate) {}

    void pay() override {
        money = monthlyPay + sales * salesRate;
    }

    void showType() const override {
        cout << "[销售经理类员工] ";
    }

    string getTypeName() const override { return "ManagerSales"; }

    void display() const override {
        showType();
        Employee::display();
        cout << "月薪: " << monthlyPay
             << ", 销售额: " << sales
             << ", 提成率: " << salesRate << endl;
    }

    void writeFile() const override {
    ofstream fout("employee.txt", ios::app);
    fout << "ManagerSales," << id << "," << name << ","
         << info.getAge() << "," << info.getWeight() << ","
         << monthlyPay << ',' << sales << ',' << salesRate << "\n";
    fout.close();
    }

};

#endif

/*
money 是从虚基类 Employee 那里来的，多继承不冲突。
只存在一份 Employee 成员数据。
所以我直接写 money = xxx，不会有二义性。

*/
