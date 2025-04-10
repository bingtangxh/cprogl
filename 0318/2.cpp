#include "iostream"

int max(int x, int y); //函数声明

int main()
{
    int a, b, c;
    std::cin >> a >> b;
    c = max(a, b);
    std::cout << "max= " << c << '\n';
}

int max(int x, int y) //函数定义
{
    int z;
    if (x > y)
        z = x;
    else
        z = y;
    return (z);
}
