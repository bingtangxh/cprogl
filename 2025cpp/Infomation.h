#ifndef INFORMATION_H
#define INFORMATION_H

#include <iostream>
#include <string>
using namespace std;

class Information {
private:
    int age;
    double weight;

public:
    // 这个是无参构造函数
    Information() : age(0), weight(0.0) {}

    // 这个则是有参构造函数，重载了
    Information(int _age, double _weight) : age(_age), weight(_weight) {}

    // 这些是访问函数（getters）
    int getAge() const { return age; }
    double getWeight() const { return weight; }

    // 这些是赋值函数（setters）
    void setAge(int _age) { age = _age; }
    void setWeight(double _weight) { weight = _weight; }

    // 显示信息
    void display() const {
        cout << "年龄: " << age << " 岁, 体重: " << weight << " kg";
    }
};

#endif
