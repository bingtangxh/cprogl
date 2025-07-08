#include <iostream>
#include <unordered_set>
#include <limits>
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
// 删除非递减序单链表中值相同的多余结点
void removeDuplicates(ListNode*& head) {
    if (head == nullptr) return;

    ListNode dummy(0); // 创建一个哑节点来简化头节点处理
    dummy.next = head;
    ListNode* prev = &dummy;
    ListNode* current = head;
    std::unordered_set<int> seen; // 用于记录已经出现过的值

    while (current != nullptr) {
        if (seen.find(current->val) != seen.end()) {
            // 如果当前值已经在集合中出现过，删除当前节点
            ListNode* toDelete = current;
            prev->next = current->next;
            current = current->next;
            delete toDelete;
        }
        else {
            // 如果当前值未出现过，添加到集合中，并继续遍历
            seen.insert(current->val);
            prev = current;
            current = current->next;
        }
    }
    // 更新头指针
    head = dummy.next;
}
// 从用户输入创建非递减序链表
ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int val;
    std::cout << "Enter values for the list in non-decreasing order (enter a non-integer to stop): ";
    while (std::cin >> val) {
        ListNode* newNode = new ListNode(val);
        if (head == nullptr || head->val >= val) {
            newNode->next = head;
            head = newNode;
        }
        else {
            ListNode* current = head;
            while (current->next != nullptr && current->next->val < val) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
        // 由于我们保证输入是非递减的，所以不需要更新tail指针
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

    removeDuplicates(head);
    std::cout << "List after removing duplicates: ";
    printList(head);

    freeList(head);
    return 0;
}