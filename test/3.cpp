#include<iostream>
using namespace std;
class AA {
public:
    AA() { cout << "A"; }
    ~AA() { cout << "a"; }
};
class BB: public AA {
    AA aa;
public:
    BB() { cout << "B"; }
    ~BB() { cout << "b"; }
};
int main() {
    BB bb;
    return 0;
}