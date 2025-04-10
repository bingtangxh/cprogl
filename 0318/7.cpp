#include <iostream>
int max(int a,int b)
{
    return a>b?a:b;
}
long max(long a,long b)
{
    return a>b?a:b;
}
double max(double a,double b)
{
    return a>b?a:b;
}
int main()
{
    int a,b;
    long c,d;
    double e,f;
    std::cin>>a>>b;
    std::cin>>c>>d;
    std::cin>>e>>f;
    std::cout<<max(a,b)<<std::endl<<max(c,d)<<std::endl<<max(e,f)<<std::endl;
    return 0;
}