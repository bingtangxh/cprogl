#include <iostream> 
using namespace std;
struct Node { int data;Node* next; }; 
class Stack { private: Node* top;
public: Stack() : top(nullptr) {} 
	  ~Stack() { while 
		  (!isEmpty()) 
	  { 
		  pop(); 
	  }
	  }
	  void push(int value) {
		  Node* newNode = new Node{value, top};
		  top = newNode; 
	  } 
	  int pop() {
		  if (isEmpty())
		  {
			  std::cerr << "Stack Underflow" << std::endl;
			  return -1;
		  }
		  Node* temp = top;
		  int poppedValue = top->data;
		  top = top->next;
		  delete temp;
		  return poppedValue;
	  }
		  int peek()
			  const { if (isEmpty()) 
		  { std::cerr << "Stack is empty" << std::endl; 
		  return -1;
		  }
		  return top->data; 
		  } 
		  bool isEmpty() 
			  const { return top == nullptr; 
		  }
          }; 
		  int main()
		  { Stack stack; 
		  int value; 
		  std::cout << "Enter numbers (use -1 to pop and output the top element):" << std::endl;
		  while (std::cin >> value && value != 0) 
		  { if (value == -1)
		  { if (!stack.isEmpty()) 
		  { std::cout << "Popped: " << stack.pop() << std::endl; 
		  } 
		  else { std::cout << "Stack is empty, cannot pop." << std::endl;
		  }
		  }
		  else { stack.push(value);
		  } 
		  }
		  return 0; }






































