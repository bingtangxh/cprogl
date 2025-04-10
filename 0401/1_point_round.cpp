#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Point{
    private:
        double x,y;
    public:
        Point();
        Point(double x_,double y_);
        double distance();
        double distance(const Point &p);
        double getX(){return x;}
        double getY(){return y;}
        void setX(double x_);
        void setY(double y_);
};

Point::Point(double x_,double y_):x(x_),y(y_){}
void Point::setX(double x_){x=x_;}
void Point::setY(double y_){y=y_;}
double Point::distance(){return sqrt(pow(x,2.0)+pow(y,2.0));}
double Point::distance(const Point &p)
{
    double deltaX=x-p.x;
    double deltaY=y-p.y;
    return sqrt(pow(deltaX,2.0)+pow(deltaY,2.0));
}

class Circle {
    private:
        Point centa;
        double rad;
    public:
        Circle(Point cta,double r):centa(cta),rad(r){}
        string judge(Point position)
        {
            double r2=centa.distance(position);
            if (r2<rad) return "inside";
            else if (r2==rad) return "on";
            else if (r2>rad) return "outside";
            else return "None of each";
        }
};


int main()
{
   double x1,y1,x2,y2,r; 
   cin>>x1>>y1>>x2>>y2>>r;
   Point p(x1,y1);
   Point ctr(x2,y2);
   Circle c(ctr,r);
   cout<<setprecision(3)<<p.distance()<<" "<<c.judge(p)<<endl;
} 