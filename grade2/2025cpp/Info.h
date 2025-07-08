#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Technician.h"
#include "Manager.h"
#include "Salesman.h"
#include "ManagerSales.h"
#include <sstream>

using namespace std;

class Info {
private:
    Employee* employees[100];
    // 上面这一行是存储所有员工（父类指针）
    int num;

public:
    Info() : num(0) {}

    // 添加自然信息（这里合并在 addInfo 里完成就够了）
    void addInfo() {
        int choice;
        system("cls");
        cout << "\n请选择员工类型(1/6)：\n\n";
        cout << "1. 技术人员\n";
        cout << "2. 经理\n";
        cout << "3. 销售员\n";
        cout << "4. 销售经理（多要求一个参数）\n\n";
        cout << "输入选项(1~4): ";
        cin >> choice;

        int id, age;
        double weight;
        string name;

        system("cls");
        cout << "\n输入编号(2/6): "; cin >> id;
        cout << "\n输入姓名(3/6): "; cin >> name;
        cout << "\n输入年龄(4/6): "; cin >> age;
        cout << "\n输入体重(5/6): "; cin >> weight;

        Employee* emp = nullptr;

        if (choice == 1) {
            int hours;
            cout << "\n输入工作小时(6/6): "; cin >> hours;
            emp = new Technician(id, name, age, weight, hours);
        } else if (choice == 2) {
            double salary;
            cout << "\n输入月薪(6/6): "; cin >> salary;
            emp = new Manager(id, name, age, weight, salary);
        } else if (choice == 3) {
            double sales;
            cout << "\n输入销售额(6/6): "; cin >> sales;
            emp = new Salesman(id, name, age, weight, sales);
        } else if (choice == 4) {
            double base, sales;
            cout << "\n输入月薪(6/7): "; cin >> base;
            cout << "\n输入销售额(7/7): "; cin >> sales;
            emp = new ManagerSales(id, name, age, weight, base, sales);
        }

        if (emp) {
            emp->pay();  
            // 上一行是自动计算工资
            employees[num++] = emp;
            cout << "✅ 添加成功！" << endl;
        }
    }

    // 显示所有员工信息
    void showInfo() const {
        cout << "\n—— 所有员工信息如下 ——\n";
        for (int i = 0; i < num; ++i) {
            employees[i]->display();
        }
    }

    // 写入文件
    void writeInfo() const {
        for (int i = 0; i < num; ++i) {
            employees[i]->writeFile();
        }
        cout << "✅ 已写入 employee.txt" << endl;
    }

    // 读取文件（这里只是简单读文本）
    void readInfo_old() const {
        ifstream fin("employee.txt");
        if (!fin.is_open()) {
            cout << "❌ 文件不存在或打不开\n";
            return;
        }
        cout << "\n—— 下面是 getline 读出来的文件内容 ——\n";
        string line;
        while (getline(fin, line)) {
            cout << line << endl;
        }
        fin.close();
    }

    void readInfo() {
        ifstream fin("employee.txt");
        if (!fin.is_open()) {
            cout << "❌ 无法打开文件 employee.txt\n";
            return;
        }

        string line;
        while (getline(fin, line)) {
            istringstream ss(line);
            string type;
            getline(ss, type, ',');

            int id, age;
            double weight;
            string name;

            getline(ss, line, ','); id = stoi(line);
            getline(ss, name, ',');
            getline(ss, line, ','); age = stoi(line);
            getline(ss, line, ','); weight = stod(line);

            Employee* emp = nullptr;

            if (type == "Technician") {
                int hour;
                double rate;
                getline(ss, line, ','); hour = stoi(line);
                getline(ss, line, ','); rate = stod(line);
                emp = new Technician(id, name, age, weight, hour, rate);
            } else if (type == "Manager") {
                double salary;
                getline(ss, line, ','); salary = stod(line);
                emp = new Manager(id, name, age, weight, salary);
            } else if (type == "Salesman") {
                double sales, rate;
                getline(ss, line, ','); sales = stod(line);
                getline(ss, line, ','); rate = stod(line);
                emp = new Salesman(id, name, age, weight, sales, rate);
            } else if (type == "ManagerSales") {
                double base, sales, rate;
                getline(ss, line, ','); base = stod(line);
                getline(ss, line, ','); sales = stod(line);
                getline(ss, line, ','); rate = stod(line);
                emp = new ManagerSales(id, name, age, weight, base, sales, rate);
            }

            if (emp) {
                emp->pay();
                employees[num++] = emp;
            }
        }

        fin.close();
        cout << "✅ 成功读取并恢复员工信息，共 " << num << " 条。\n";
    }


    ~Info() {
        for (int i = 0; i < num; ++i) {
            delete employees[i];
        }
    }
};

#endif
