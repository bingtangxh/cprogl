 #ifndef TECHNICIAN_H
#define TECHNICIAN_H

#include "Employee.h"

class Technician : public Employee {
private:
    int hour;
    double hourlyRate;

public:
    Technician() : Employee(), hour(0), hourlyRate(100.0) {}

    Technician(int _id, const string& _name, int _age, double _weight, int _hour, double _rate = 100.0)
        : Employee(_id, _name, _age, _weight), hour(_hour), hourlyRate(_rate) {}

    // 这四个是 set get 函数，设置小时数还有每小时的工钱
    void setHour(int h) { hour = h; }
    void setHourlyRate(double r) { hourlyRate = r; }
    int getHour() const { return hour; }
    double getHourlyRate() const { return hourlyRate; }

    void pay() override {
        money = hour * hourlyRate;
    }

    void showType() const override {
        cout << "[技术类员工] ";
    }

    string getTypeName() const override { return "Technician"; }

    void display() const override {
        showType();
        Employee::display();
        cout << "工作小时: " << hour << ", 时薪: " << hourlyRate << endl;
    }

    void writeFile() const override {
    ofstream fout("employee.txt", ios::app);
    fout << "Technician," << id << "," << name << ","
         << info.getAge() << "," << info.getWeight() << ","
         << hour << "," << hourlyRate << "\n";
    fout.close();
    }

};

#endif
