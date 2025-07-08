#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
typedef struct node {
    char data;
    struct node *left;
    struct node *right;
}Node;
 
//前序遍历扩展二叉树
char extStr[114514]={'\0'};
 
void createBinTree(Node **T) {
    static int currentIndex=0;
    if (!strlen(extStr)||extStr[currentIndex]=='\n') return;
    else {
        if (extStr[currentIndex]=='#') {
            T=NULL;
            currentIndex++;
        }
        else {
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
 
void printNode(Node *T) {
    putchar(T->data);
    putchar(' ');
}
 
void expTree(Node *T) {
    if (!T) return;
    else {
        printNode(T);
        expTree(T->left);
        expTree(T->right);
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

int main(int argc, char *argv[]) {
    Node *T = NULL;
    fgets(extStr,114514,stdin);

    createBinTree(&T);
    printf("%d",height(T));
    return 0;
}