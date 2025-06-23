#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
class Group
{
public:
    virtual int add(int x, int y)=0;//输出加法的运算结果
    virtual int sub(int x, int y)=0;//输出减法的运算结果
};
 
class GroupA:public Group
{
public:
    int add(int x, int y) {return x+y;}
    int sub(int x, int y) {return x-y;}
};
 
class GroupB:public Group
{
public:
    int add(int x, int y){
        return x+y;
    }
    int sub(int x, int y){
        int num1[4]={0},num2[4]={0},i=0,j=0,n=i,tmp=1,sum=0;
        while(x||y)
        {
            num1[i++]=x%10;
            num2[j++]=y%10;
            x/=10;
            y/=10;
        }
        for(int k=0;k<n;k++)
        {
            if(num1[k]<num2[k])
            {
                sum=sum+tmp*(10+num1[k]-num2[k]);
            } else
            {
                sum=sum+tmp*(num1[k]-num2[k]);
            }
            tmp*=10;
        }
        return sum;
    }
};
        
class GroupC:public Group
{
public:
    int add(int x, int y){
        int num1[4]={0},num2[4]={0},i=0,j=0,n=i,tmp=1,sum=0;
        while(x||y){
            num1[i++]=x%10;
            num2[j++]=y%10;
            x/=10;
            y/=10;
        }
        for(int k=0;k<n;k++)
        {
            sum=sum+(num1[k]+num2[k])%10*tmp;
            tmp*=10;
        }
        return sum;
    }
    int sub(int x, int y){
        int num1[4]={0},num2[4]={0},i=0,j=0,n=i, tmp=1, sum=0;
        while(x||y){
            num1[i++]=x%10;
            num2[j++]=y%10;
            x/=10;
            y/=10;
        }
        for(int k=0;k<n;k++)
        {
            if(num1[k]<num2[k])
            {
                sum=sum+tmp*(10+num1[k]-num2[k]);
            }else
            {
                sum=sum+tmp*(num1[k]-num2[k]);
            }
            tmp*=10;
        }
        return sum;
    }
};

int main()
{
    int n,i=0, stu[22]={0}, temp,x,y;
    char ch;
    cin>>n;
    while(++i<=n&&cin>>stu[i]);
    while(cin>>temp&&temp!=0){
        cin>>x>>ch>>y;
        GroupA a;
        GroupB b;
        GroupC c;

        switch (stu[temp])
        {
        case 1:
            
            if(ch=='+'){
                cout<<a.add(x,y)<<endl;
            }else if(ch=='-'){
                cout<<a.sub(x,y)<<endl;
            }
            break;

        case 2:
            
            if(ch=='+'){
                cout<<b.add(x,y)<<endl;
            }else if(ch=='-'){
                cout<<b.sub(x,y)<<endl;
            }
            break;

        case 3:
            if(ch=='+'){
                cout<<c.add(x,y)<<endl;
            }else if(ch=='-'){
                cout<<c.sub(x,y)<<endl;
            }
            break;

        default:
            break;
        }
    }
    return 0;
}