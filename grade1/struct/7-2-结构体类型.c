#include<stdio.h>
#include<string.h>
struct stu{
    int num;
    char name[20];
    char sex;
    double score;
};
void p(struct stu t){
    printf("%d %s %c %lf\n",t.num,t.name,t.sex,t.score);
}
int main(){
    struct stu s1={1001,"XiaomiLi",'M',89.0},
               s2={1002,"XiaodiMa"},
               s3;
    s3.num=1003;
    strcpy(s3.name,"XiaohaiLiu");
    scanf("%c %lf",&s3.sex,&s3.score);
    s2=s1;
    p(s1);
    p(s2);
    p(s3);
    return 0;
}