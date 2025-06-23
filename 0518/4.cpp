#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Vehicle
{
protected:
    string NO;//编号
public:
    Vehicle(string str){
    NO=str;
    }
    virtual void display()=0;//输出应收费用
    virtual ~Vehicle(){};
};

class Car:public Vehicle
{
    int n;
    double k;
public:
    Car(string str,int num,double kg):Vehicle(str)
    {
        n=num;
        k=kg;
    }
    virtual void display()
    {
        cout<<NO<<" "<<n*8+k*2<<endl;

    }
};

class Truck:public Vehicle
{
    double k;
public:
    Truck(string str,double kg):Vehicle(str)
    {
        k=kg;
    }
    virtual void display()
    {
        cout<<NO<<" "<<k*5<<endl;
    }
};
class Bus:public Vehicle
{
int n;
public:
    Bus(string str,int num):Vehicle(str){n=num;}
    virtual void display()
    {
        cout<<NO<<" "<<n*3<<endl;
    }
};
int main()
{
    Vehicle *pd[10];
    string str;
    int t,num,i=0;
    double kg;
    cin>>t;
    while(t){
        cin>>str;
        if(t==1){
            cin>>num>>kg;
            pd[i]=new Car(str,num,kg);
        }else if(t==2){
            cin>>kg;
            pd[i]=new Truck(str,kg);
        }else if(t==3){
            cin>>num;
            pd[i]=new Bus(str,num);
        }
        pd[i]->display();
        i++;
        cin>>t;
    }
    delete *pd;
    return 0;
}
