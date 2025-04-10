#include<iostream>
using namespace std;
class A
{
  int num;
public:
  A（int i）{num=i;}
  A（A &a）{num=a.num++;}
  void print（）{cout<<num;}
};
void main（）
{
  A a （1）,b（a）;
  a.print（）;
  b.print（）;
}