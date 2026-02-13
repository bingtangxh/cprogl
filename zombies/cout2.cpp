#include <iostream> 
using namespace std;     
class Person {
public:
    Person(int age): m_age(age) {
        cout << "create person: " << m_age << endl;
    }
    ~Person() {
        cout << "destroy person: " << m_age << endl;
    }
private:
    int m_age;
};
int main() {
    Person p1(18), p2(19);
    return 0;
}