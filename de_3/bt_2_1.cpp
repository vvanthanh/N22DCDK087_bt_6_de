#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Constructor of Base\n";
    }

    // Hàm hủy ảo
    virtual ~Base() {
        cout << "Destructor of Base\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Constructor of Derived\n";
    }

    ~Derived() override {
        cout << "Destructor of Derived\n";
    }
};

int main() {
    Base* ptr = new Derived(); // Con trỏ đa hình
    delete ptr; // Dùng delete cho con trỏ của lớp cơ sở

    return 0;
}
