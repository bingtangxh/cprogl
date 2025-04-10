#include<stdio.h>
struct reimbursementInfo{
    int number_current;
    int number_inital;
    char name[11];
    int sum;
}employee[20],bubble_temp;

int main(){
    //一分都没拿到
    int T,n,m,temp;
    scanf("%d",&T);
    for(int iT=0;iT<T;iT++){
        scanf("%d %d",&n,&m);
        for(int in=0;in<n;in++){
            employee[in].number_current=in;
            employee[in].number_inital=in;
            scanf("%s ",&employee[in].name);
            employee[in].sum=0;
            for(int im=0;im<m;im++){
                scanf("%d",&temp);
                employee[in].sum+=temp;
            }
        }
        for(int i1=0;i1<n;i1++){
            for(int i2=0;i2<n-i1;i2++){
                //printf("\n%d",i2);
                //putchar(employee[i2].name[0]);
                if(employee[i2].sum<employee[i2+1].sum||
                   (employee[i2].sum==employee[i2+1].sum&&
                    strcmp(employee[i2].name,employee[i2+1].name)>0)||
                  ((employee[i2].sum==employee[i2+1].sum)&&
                  (strcmp(employee[i2].name,employee[i2+1].name)==0)&&
                  employee[i2].number_inital>employee[i2+1].number_inital)){
                    bubble_temp=employee[i2];
                    employee[i2]=employee[i2+1];
                    employee[i2+1]=bubble_temp;
                }
            }
        }
        for(int in=0;in<n;in++){
            employee[in].number_current=in;
            if(in>1){
                while(employee[in].sum==employee[employee[in].number_current-1].sum){
                    employee[in].number_current--;
                }
            }
        }
        printf("Case %d:\n",iT+1);
        for(int in=0;in<n;in++){
            printf("%d %d %s %d\n",employee[in].number_current+1,employee[in].number_inital+1,employee[in].name,employee[in].sum);
        }
        if(iT<T-1){putchar('\n');}
        else{T+=0;}
    }
}
