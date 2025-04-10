#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student
{
    char *name;
    int age;
};
void initializeStudent(struct Student *student,const char *name,int age)
{
    //上面*name不能改变，但是name指向的地址能变
    student->name=(char *)malloc(strlen(name)+1);
    strcpy(student->name,name);
    student->age=age;
}
int main(void)
{
    struct Student s1,s2;
    initializeStudent(&s1,"Tom",18);
    initializeStudent(&s2,"Jerry",28);
    s1=s2;
    printf("s1's name: %s age: %d\n",s1.name,s1.age);
    printf("s2's name: %s age: %d\n",s2.name,s2.age);
    free(s1.name);
    free(s2.name);
    /*
    直接运行会在free(s2.name)这里发生Unknown Signal，
    应该是s1=s2之后时候s1.name和s2.name已经是同一个地址了，后面free了两遍肯定会出问题。
    应该把s1=s2这个赋值的删了，把age单另赋一遍值，然后name改成用strcpy(s1.name,s2.name)就行了。
    */
    return 0;
}