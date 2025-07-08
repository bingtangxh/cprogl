#include<iostream>
using namespace std;
struct ListNode { int val; ListNode* next; ListNode(int x) : val(x), next(NULL) {} }; // 函数：就地逆置单链表 
ListNode* reverseList(ListNode* head) { ListNode* prev = NULL;
ListNode* curr = head;
while (curr != NULL) { ListNode* next_temp = curr->next;
curr->next = prev;
prev = curr; 
curr = next_temp; }
return prev; } // 辅助函数：打印链表
void printList(ListNode* head)
{ while (head != NULL) 
{ std::cout << head->val << " "; 
head = head->next;
} 
std::cout << std::endl; 
} // 主函数 
int main() { 
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2); 
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	std::cout << "Original List: ";
	printList(head); 
	head = reverseList(head);
	std::cout << "Reversed List: "; 
	printList(head);
	return 0; }