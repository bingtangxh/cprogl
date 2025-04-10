#include<stdio.h>
struct stu{ 
    int num;
    char name[20];
    char sex;
    double score;
}s[5]={     {101,"XiaoDi_Ma"    , 'M',  45},
            {102,"JuHao_Zhu"    , 'M',62.5},
            {103,"XinHao_Li"    , 'F',92.5},
            {104,"HongPeng_Yang", 'F',  87},
            {105,"YuHang_Gao"   , 'M',  58}
         };
int main(){
    struct stu *ps;
    for(ps=s;ps<s+5;ps++)
      printf("%d %-20s %c %lf\n",ps->num,ps->name,ps->sex,ps->score);
    return 0;
}