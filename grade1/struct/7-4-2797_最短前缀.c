#include<stdio.h>
#include<string.h>


int main(){
    char words[1000][21];
    int n=0;
    while(fgets(words[n],21,stdin)!=NULL&&words[n][0]!='\n'){
        n++;
    }
    for(int i1=0,i4;i1<n;i1++){
        for(int i2=0,dupu;i2<strlen(words[i1]);i2++){
            dupu=0;
            i4=0;
            while(words[i1][i4]!='\n'&&words[i1][i4]!='\0')
            {
                i4++;
            }
            words[i1][i4]='\0';
            if(i2==(strlen(words[i1])-1)){
                printf("%s %s\n",words[i1],words[i1]);
                break;
            }
            else{
                for(int i3=0;i3<n;i3++){
                    if((strncmp(words[i1],words[i3],i2))==0&&i3!=i1){
                        dupu=1;
                        break;
                    }
                    else{continue;}
                }
            }
            if(dupu==1){continue;}
            else{
                fputs(words[i1],stdout);
                putchar(' ');
                for(i4=0;i4<i2;i4++){
                    putchar(words[i1][i4]);
                }
                putchar('\n');
                break;
            }
        }
    }
}