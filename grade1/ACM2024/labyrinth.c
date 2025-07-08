#include <stdio.h>

int fx,fy,isToken[7][7]={1};

int isDirected(int x,int y);

int main(void)
{
    int n,m,t,sx,sy,blockx[10]={0},blocky[10]={0};
    scanf("%d %d %d\n%d %d %d %d",&n,&m,&t,&sx,&sy,&fx,&fy);
    // puts("114514");

    for(int i1=0;i1<=6;i1++)
    {
        for(int i2=0;i2<=6;i2++)
        {
            if(1<=i1&&i1<=n&&1<=i2&&i2<=m) isToken[i1][i2]=0;
            else isToken[i1][i2]=1;
        }
    }
    
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&blockx[i],&blocky[i]);
        isToken[blockx[i]][blocky[i]]=1;
    }
    printf("%d",isDirected(sx,sy));

    return 0;
}

int isDirected(int x,int y)
{
    // printf("%d %d %d\n",x,y,isToken[x][y]);
    static int total=0;
    if(isToken[x][y]) return total;
    if(x==fx&&y==fy)
    {
        total++;
        return total;
    }
    else
    {
        for(int x1=x-1;x1<=x+1;x1+=2)
        {
            for(int y1=y-1;y1<=y+1;y1+=2)
            {
                if(isToken[x1][y1]==1) continue;

                else 
                {
                    isToken[x][y]=1;
                    isDirected(x1,y1);
                    isToken[x][y]=0;
                    continue;
                }
            }
        }
        return total;
    }
}

