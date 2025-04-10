#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}
Node;

char extStr[114514]={'\0'};

void createBinTree(Node **T)
{
    static int currentIndex=0;
    if (!strlen(extStr)||extStr[currentIndex]=='\n') return;
    else {
        if (extStr[currentIndex]=='#')
        {
            *T=NULL;
            currentIndex++;
        }
        else
        {
            *T=malloc(sizeof(**T));
            (*T)->data=extStr[currentIndex];
            (*T)->lchild=NULL;
            (*T)->rchild=NULL;
            currentIndex++;
            createBinTree(&(*T)->lchild);
            createBinTree(&(*T)->rchild);
        }
    }
}
 
 
void expTree(Node *T,int order)
{
    if (T==NULL) return;
    else
    {
        if(order==1) {
            if(T!=NULL) putchar(T->data);
        }
        expTree(T->lchild,order);
        if(order==2) {
            if(T!=NULL) putchar(T->data);
        }
        expTree(T->rchild,order);
        if(order==3) {
            if(T!=NULL) putchar(T->data);
        }
    }
}

int height(Node *root)
{
    int height1,height2;
    if(root)
    {
        height1=height(root->lchild);
        height2=height(root->rchild);
        return height1>height2?height1+1:height2+1;
    }
    else return 0;
}

int leafNode(Node *root,char leafStr[],int amount,int reset)
{
    int amount_c=0;
    static int leaf=0;
    if(reset)
    {
        leaf=0;
        strcpy(leafStr,"");
    }
    char currentStr[]={root->data,'\0'};
    if(root->lchild)
    {
        leaf=leafNode(root->lchild,leafStr,amount,0);
        amount_c++;
    }
    if(root->rchild)
    {
        leaf=leafNode(root->rchild,leafStr,amount,0);
        amount_c++;
    }
    if(amount_c==amount)
    {
        leaf++;
        strcat(leafStr,currentStr);
    }
    return leaf;
}

int main(int argc, char *argv[]) {
    Node *T = NULL;
    char leafStr[114514]={'\0'},child1Str[114514]={'\0'},child2Str[114514]={'\0'};
    fgets(extStr,114514,stdin);

    createBinTree(&T);
    //printf("%d %d %d\n",leafNode(T,leafStr,0,1),leafNode(T,leafStr,1,1),leafNode(T,leafStr,2,1));
    
    for(int i=0;i<3;i++)
    {
        expTree(T,i+1);
        putchar('\n');
    }
    return 0;
}