#include<stdio.h>
#include<math.h>
struct Student
{
    char num[11];
    char name[11];
    int s1,s2,s3;
    int total; 
};
typedef struct Student Student1,temp_bubble;
int main(){
    //一分都没拿到
    int n,i1,count_thin=0,count_norm=0,count_fat=0;
    scanf("%d",&n);
    char temp;
    for(int i=0;i<n;i++){
        i1=0;
        while(1){
            temp=getchar();
            if(temp==' '){
                Student1[i].num[i1]=-1;
                break;
            }
            else{
                Student1[i].num[i1]=temp;
                i1++;
            }
        }
        scanf("%s %d %d %d",&Student1[i].name,&Student1[i].s1,&Student1[i].s2,&Student1[i].s3);
        Student1[i].total=Student1[i].s1+Student1[i].s2+Student1[i].s3;
        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<n-i1;i2++){
                if(Student1[i2].total<Student1[i2+1].total){
                    temp_bubble=Student1[i2];
                    Student1[i2]=Student1[i2+1];
                    Student1[i2+1]=temp_bubble;
                }
            }
        }
        for(int i=0;i<n;i++){
            while(Student1[i].number[i1]!=-1){
                    if(i1!=0){
                        putchar(Student1[i].number[i1]);
                    }
                    else{n=n;}
                    i1++;
                }
                printf(" %s %d\n",Student1[i].name,Student1[i].total);
        }
    }
    return 0;
}

