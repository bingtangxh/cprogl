#include <iostream>
using namespace std;
int main() //前面的 int 指定了 main()函数返回值的数据类型
{
    int a, b, c;
    cin >> a >> b;
    if (b == 0)
        return -1; // main()函数返回非0值表示程序遇到错误而结束
    c = a / b;
    cout << "c= " << c <<'\n';
    return 0; //程序正常结束，函数 main()返回值为0。
}
