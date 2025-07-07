#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <fstream>
#include <string>
#include "Information.h"
using namespace std;

class Employee {
private:
    static string companyName;
    // 上面这个是静态成员，到哪都一样
protected:
    double money;

    int id;
    string name;
    Information info;

public:

    // 这是无参构造函数
    Employee() : id(0), name(""), info(), money(0.0) {}

    // 这是有参构造函数，重载了
    Employee(int _id, const string& _name, int age, double weight)
        : id(_id), name(_name), info(age, weight), money(0.0) {}

    // 设置静态成员公司名称
    static void setCompanyName(const string& cname) {
        companyName = cname;
    }

    virtual string getTypeName() const = 0;

    // 设置所有私有成员变量（除了公司名）
    void setAll(int _id, const string& _name, int age, double weight) {
        id = _id;
        name = _name;
        info.setAge(age);
        info.setWeight(weight);
    }

    // 显示职员信息
    virtual void display() const {
        cout << "公司: " << companyName << ", ID: " << id
             << ", 姓名: " << name << ", 工资: " << money << ", ";
        info.display();
        cout << endl;
    }

    // 这个函数虽然用来写进文件，但是应该用不到，因为每个派生类都写了 override 的 writeFile 函数
    virtual void writeFile() const {
        ofstream fout("employee.txt", ios::app);
        if (fout.is_open()) {
            fout << "公司: " << companyName << ", ID: " << id
                 << ", 姓名: " << name << ", 工资: " << money << ", 年龄: " << info.getAge()
                 << ", 体重: " << info.getWeight() << endl;
            fout.close();
        } else {
            cerr << "无法打开 employee.txt 文件" << endl;
        }
    }

    // 纯虚函数：发工资
    virtual void pay() = 0;

    // 纯虚函数：显示类型
    virtual void showType() const = 0;

    // 提供访问ID和姓名（可选）
    int getId() const { return id; }
    string getName() const { return name; }
};

// 静态成员初始化
string Employee::companyName = "下北泽轨道交通集团有限公司（误）";

#endif
