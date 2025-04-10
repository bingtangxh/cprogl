#include<stdio.h>
#include<math.h>
struct studentInfo{
    int number[12];
    char name[10];
    float height;
    float weight;
    float BMI;
    int value;
}stu[20];
int main(){
    int n,i1,count_thin=0,count_norm=0,count_fat=0;
    scanf("%d",&n);
    char temp;
    for(int i=0;i<n;i++){
        i1=0;
        while(1){
            temp=getchar();
            if(temp==' '){
                stu[i].number[i1]=-1;
                break;
            }
            else{
                stu[i].number[i1]=temp;
                i1++;
            }
        }
        scanf("%s %f %f",&stu[i].name,&stu[i].height,&stu[i].weight);
        stu[i].BMI=stu[i].weight/pow(stu[i].height,2);
        if(stu[i].BMI<18.5){
            stu[i].value=-1;
            count_thin++;
            }else{
                if(stu[i].BMI<24.0){
                    stu[i].value=0;
                    count_norm++;
                }else{
                    stu[i].value=1;
                    count_fat++;
                }
            }
    }
    printf("BMI正常学生信息：\n");
    printf1(0,n,count_norm);
    printf("BMI偏瘦学生信息：\n");
    printf1(-1,n,count_thin);
    printf("BMI偏胖学生信息：\n");
    printf1(1,n,count_fat);
    return 0;
}

int printf1(int value_req,int n,int count){
    if(count==0){printf("无此类学生\n");}
    else{int i1;
    for(int i=0;i<n;i++){
            if(stu[i].value==value_req){
                i1=0;
                while(stu[i].number[i1]!=-1){
                    if(i1!=0){
                        putchar(stu[i].number[i1]);
                    }
                    else{n=n;}
                    i1++;
                }
                printf("\t%s\t%.2f\n",stu[i].name,stu[i].BMI);
            }
        }}
    return 0;
}