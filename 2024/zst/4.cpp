#include <iostream>
using namespace std;
struct Node { int data; Node* next; }; 
class CircularQueue { 
private: 
	Node* rear;
	   // 指向队尾的指针
	   public:
		   CircularQueue() : rear(nullptr) {}
			 ~CircularQueue() { 
				 while (rear != nullptr)
				 { dequeue();
				 } 
			 } 
			 void enqueue(int value) { Node* temp = new Node{value, nullptr};
			 if (rear == nullptr) { temp->next = temp;
			 rear = temp;
			 } 
			 else { temp->next = rear->next;
			 rear->next = temp; 
			 rear = temp; 
			 }
			 }
			 int dequeue() { if (rear == nullptr) 
			 { std::cerr << "Queue Underflow" << std::endl;
			 return -1; 
			 } 
			 Node* temp = rear->next;
			 int value = temp->data;
			 if (rear == temp) { rear = nullptr;
			 }
			 else { rear->next = temp->next;
			 } 
			 delete temp;
			 return value; 
			 } 
			 bool isEmpty()
				 const { return rear == nullptr;
			 }
}; 
int main() { 
	CircularQueue queue;
	int value; 
	std::cout << "Enter numbers to enqueue (use -1 to dequeue):" << std::endl;
	while (std::cin >> value && value != 0) 
	{ if (value == -1) 
	{ if (!queue.isEmpty()) 
	{ std::cout << "Dequeued: " << queue.dequeue() << std::endl; 
	}
	else { std::cout << "Queue is empty, cannot dequeue." << std::endl; 
	}
	}
	else { queue.enqueue(value);
	} 
	}
	return 0; 
}