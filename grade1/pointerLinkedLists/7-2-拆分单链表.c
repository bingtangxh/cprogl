#include<stdio.h>
#include<stdlib.h>
 
typedef struct node {       //定义链表结点
    int data;
    struct node* next;
}Node;
 
void insert(Node* head,int x)        //链表初始化
{
    Node* s, * p;
    p = head;
    int data;
    for (int i = 0; i < x; i++) {
        s = (Node*)malloc(sizeof(Node));
        scanf("%d", &data);
        s->data = data;
        p->next = s;
        p = s;
    }
    p->next = NULL;
}
 
void change1(Node* head, Node* head1)        //小于0的部分接到以head1为头结点的链表中
{
    Node* move = head->next;
    Node* s, * p;
    p = head1;
    while (move) {
        if (move->data < 0) {
            s = (Node*)malloc(sizeof(Node));
            s->data = move->data;
            p->next = s;
            p = s;
        }
        move = move->next;
    }
    p->next = NULL;
}
 
void change2(Node* head, Node* head2)        //大于0的部分接入到以head2为头结点的链表中
{
    Node* move = head->next;
    Node* s, * p;
    p = head2;
    while (move) {
        if (move->data > 0) {
            s = (Node*)malloc(sizeof(Node));
            s->data = move->data;
            p->next = s;
            p = s;
        }
        move = move->next;
    }
    p->next = NULL;
}
 
void output(Node* head)        //链表输出
{
    Node* move = head->next;
    while (move!=NULL) {
        printf("%d", move->data);
        if (move->next != NULL)
            printf(" ");
        move = move->next;
    }
}
 
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        Node* head = (Node*)malloc(sizeof(Node));
        head->next = NULL;
        int x;
        scanf("%d", &x);
        insert(head, x);
        Node* head1, * head2;
        head1 = (Node*)malloc(sizeof(Node));
        head1->next = NULL;
        head2 = (Node*)malloc(sizeof(Node));
        head2->next = NULL;
        change1(head, head1);
        change2(head, head2);
        output(head1);
        printf("\n");
        output(head2);
        printf("\n");
    }
    return 0;
}