#include <iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
}; // 函数：删除非递减链表中的重复节点 
ListNode* deleteDuplicates(ListNode* head) {
	ListNode* current = head;
	while (current != NULL && current->next != NULL)
	{
		if (current->val == current->next->val)
		{
			ListNode* next_next = current->next->next;
			delete current->next; // 释放内存 
			current->next = next_next;
		}
		else { current = current->next; }
	}
	return head;
} // 辅助函数：打印链表
void printList(ListNode* head) {
	while (head != NULL) {
		std::cout << head->val << " "; head = head->next;
	}
	std::cout << std::endl;
} // 主函数 
int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	std::cout << "Original List: ";
	printList(head);
	head = deleteDuplicates(head);
	std::cout << "List after removing duplicates: ";
	printList(head);
	return 0;
}