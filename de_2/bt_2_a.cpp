#include <iostream>
using namespace std;

class Hinh {
public:
    virtual void ve() {
        cout << "Ve mot hinh dang." << endl;
    }
};

class HinhTron : public Hinh {
public:
    void ve() override {
        cout << "Ve mot hinh tron." << endl;
    }
};

class HinhVuong : public Hinh {
public:
    void ve() override {
        cout << "Ve mot hinh vuong." << endl;
    }
};

int main() {
    Hinh* hinh1 = new HinhTron();
    Hinh* hinh2 = new HinhVuong();

    hinh1->ve(); // Goi phuong thuc ve cua HinhTron
    hinh2->ve(); // Goi phuong thuc ve cua HinhVuong

    delete hinh1;
    delete hinh2;

    return 0;
}
