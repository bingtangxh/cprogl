#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct node
{
    char data;
    struct node *left;
    struct node *right;
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
            T=NULL;
            currentIndex++;
        }
        else
        {
            *T=malloc(sizeof(**T));
            (*T)->data=extStr[currentIndex];
            (*T)->left=NULL;
            (*T)->right=NULL;
            currentIndex++;
            createBinTree(&(*T)->left);
            createBinTree(&(*T)->right);
        }
    }
}
 
void printNode(Node *T)
{
    if(T!=NULL)
    {
        putchar(T->data);
        //putchar(' ');
    }
}
 
void expTree(Node *T,int order)
{
    if (T==NULL) return;
    else
    {
        if(order==1) printNode(T);
        expTree(T->left,order);
        if(order==2) printNode(T);
        expTree(T->right,order);
        if(order==3) printNode(T);
    }
}

int height(Node *root)
{
    int height1,height2;
    if(root)
    {
        height1=height(root->left);
        height2=height(root->right);
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
    if(root->left)
    {
        leaf=leafNode(root->left,leafStr,amount,0);
        amount_c++;
    }
    if(root->right)
    {
        leaf=leafNode(root->right,leafStr,amount,0);
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