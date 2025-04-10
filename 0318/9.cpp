#include <iostream>
using namespace std;

// 1. MAX_SIZE 的数值今后不能再更改
const int MAX_SIZE = 100;

// 2. 函数接收的 arr[] 数组内所有数据都不能由函数内部再进行更改
void printArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// 3. 表示返回的数值将不能更改。
// 但是这里没有起多大作用，因为返回的类型是 int 不是 int *，
// 本来就是右值，所以不需要 const。而是接收返回值的语句需要 const。
const int getFixedValue()
{
    return 42;
}
int main()
{
    // 5. 表示 main 函数内不能改这个值，如果当作参数给了别的函数则可以。
    // 如果给的是指针则也不能改。
    const double PI = 3.14159;
    cout << "全局常量 MAX_SIZE: " << MAX_SIZE << endl;
    cout << "局部常量 PI: " << PI << endl
         << endl;

    // 6. 数组的内容不能修改，但是用指针可以改。
    // nums[1] 不能赋值，但是 *(&nums+1) 可以。
    const int nums[] = {1, 2, 3};
    cout << "常量数组内容: ";
    printArray(nums, 3);

    // 7. value 的值将无法修改。
    // getFixedValue() 返回的是 const ，所以接收的也必须 const。
    const int value = getFixedValue();
    cout << "函数返回的常量值: " << value << endl
         << endl;

    int var = 10;
    const int *ptr1 = &var; // 8. var 可以直接改，ptr1 本身也可以改，不能顺着 ptr1 指针改东西
    int *const ptr2 = &var; // 9. var 可以直接改，也可以顺着 ptr2 改 var ，但 ptr2 本身不能改

    // ptr1 = nullptr;   // 10.允许，ptr1 可以改，const 修饰的是 (int *ptr1)
    // *ptr1 = 20;      //11. 错误：(int *ptr1)是固定的，不能顺着改
    *ptr2 = 20; // 12. 允许，const 修饰的是 ptr2 ，可以顺着改
    // ptr2 = nullptr;  //13. 错误：ptr2 是 const，不能改指向的地址

    cout << "var 修改后的值: " << var << endl
         << endl;
    return 0;
}
