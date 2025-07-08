#include <iostream>
using namespace std;
const double PI=3.1415926;

class Shape
{
    double CHANGNINGGONG;
};

class Circle:public Shape
{
    public:
    double radius;
    double area(void) {return PI*radius*radius;}
};

class Rectangle:public Shape
{
    public:
    double height,width;
    double area(void) {return height*width;}
};

class Triangle:public Shape
{
    public:
    double height,width;
    double area(void) {return height*width/2.0;}
};

int main()
{
    Circle circle;
    Rectangle rectangle;
    Triangle triangle;
    cin>>circle.radius>>rectangle.height>>rectangle.width>>triangle.height>>triangle.width;
    printf("%.2lf\n%.2lf\n%.2lf\n",circle.area(),rectangle.area(),triangle.area());
    return 0;
}