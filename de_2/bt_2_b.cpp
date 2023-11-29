#include <iostream>
using namespace std;

// Khai báo lớp trừu tượng
class Hinh {
public:
    // Phương thức trừu tượng
    virtual void ve() const = 0;
};
// Lớp con 1 triển khai lớp trừu tượng
class HinhTron : public Hinh {
public:
    void ve() const override {
        cout << "Ve mot hinh tron." << endl;
    }
};
// Lớp con 2 triển khai lớp trừu tượng
class HinhVuong : public Hinh {
public:
    void ve() const override {
        cout << "Ve mot hinh vuong." << endl;
    }
};

int main() {
    // Không thể tạo đối tượng từ lớp trừu tượng
    // Hinh h; // Lỗi
    // Tạo con trỏ từ lớp trừu tượng và tham chiếu đến các đối tượng con
    const Hinh* hinh1 = new HinhTron();
    const Hinh* hinh2 = new HinhVuong();
    // Gọi phương thức ve() tùy thuộc vào đối tượng thực sự
    hinh1->ve(); // Gọi phương thức ve() của HinhTron
    hinh2->ve(); // Gọi phương thức ve() của HinhVuong

    delete hinh1;
    delete hinh2;

    return 0;
}
