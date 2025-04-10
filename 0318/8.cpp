#include <iostream>
#include <cstring>

int main()
{
    const char name[]="DKR";
    char* memSpace=new char[1+strlen(name)];
    strncpy_s(memSpace,strlen(name)+1,name,strlen(name));
    std::cout<<memSpace<<std::endl;
    delete[] memSpace;
    memSpace=0;
    return 0;
}