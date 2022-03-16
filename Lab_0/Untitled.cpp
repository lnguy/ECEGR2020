#include <iostream>
using namespace std;
class Mammal {
public:
    virtual void eat() {
        cout << "Mammals eat...";
    }
};
class Cow: public Mammal {
public:
    void eat() {
        cout << "Cows eat grass...";
    }
};
int main(void) {
    Cow      c = Cow();
    Mammal*  m = &c;
    c.eat();
    m->eat();
}