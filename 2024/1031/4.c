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
 
void expTree_depth(Node *T)
{
    //此函数会漏掉根节点，所以需要把根节点单独printNode一遍
    //This function will exclude root node
    //so it needs to dandu printNode its root
    if (T==NULL) return;
    else
    {
        printNode(T->left);
        printNode(T->right);
        expTree_depth(T->left);
        expTree_depth(T->right);
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
    putchar(T->data);
    expTree_depth(T);
    return 0;
}