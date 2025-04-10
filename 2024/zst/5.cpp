#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 打印链表
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// 逆置链表（就地）
void reverseList(ListNode*& head) {
    ListNode* prev = nullptr;
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextTemp = current->next;
        current->next = prev;
        prev = current;
        current = nextTemp;
    }
    head = prev;
}

// 从用户输入创建链表
ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int val;
    std::cout << "Enter values for the list (enter a non-integer to stop): ";
    while (std::cin >> val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    std::cin.clear(); // 清除错误标志
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 忽略输入缓冲区中的剩余内容
    return head;
}

// 释放链表内存
void freeList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

int main() {
    ListNode* head = createList();
    std::cout << "Original list: ";
    printList(head);

    reverseList(head);
    std::cout << "Reversed list: ";
    printList(head);

    freeList(head);
    return 0;
}