#include <bits/stdc++.h>
using namespace std;

class animal
{
private:
    int num;
    string name;

public:
    animal(int nu,string na):num(nu),name(na) {}
    int getnum()
    {
        return num;
    }
    string getname()
    {
        return name;
    }
    virtual void eat()
    {
    }
};

class Dog:public animal
{
public:
    Dog(int nu,string na):animal(nu,na) {}
    virtual void eat()
    {
        cout<<animal::getnum()<<"号"<<animal::getname()<<"啃骨头"<<endl;
    }
};

class Cat:public animal
{
public:
    Cat(int nu,string na):animal(nu,na) {}
    virtual void eat()
    {
        cout<<animal::getnum()<<"号"<<animal::getname()<<"吃小鱼"<<endl;
    }
};

int main()
{
    int dogId,catId;
    string dogn,catn;
    cin>>dogId>>dogn>>catId>>catn;
    Dog d(dogId,dogn);
    Cat c(catId,catn);
    animal *p;
    p=&d;
    p->eat();
    p=&c;
    p->eat();
    return 0;
}