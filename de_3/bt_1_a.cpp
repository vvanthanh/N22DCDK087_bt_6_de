#include <iostream>

using namespace std;

class A_B_Sqrt_X {
private:
    int _a;
    int _b;
    int _SO_DUOI_DAU_CAN;

public:
    A_B_Sqrt_X operator+(const A_B_Sqrt_X&);
    A_B_Sqrt_X operator-(const A_B_Sqrt_X&);
    A_B_Sqrt_X operator-();
    A_B_Sqrt_X operator*(const A_B_Sqrt_X&);
    friend ostream& operator<<(ostream&, const A_B_Sqrt_X&);
    friend istream& operator>>(istream&, A_B_Sqrt_X&);
};

A_B_Sqrt_X A_B_Sqrt_X::operator+(const A_B_Sqrt_X& other) {
    // Định nghĩa phép cộng
}

A_B_Sqrt_X A_B_Sqrt_X::operator-(const A_B_Sqrt_X& other) {
    // Định nghĩa phép trừ
}

A_B_Sqrt_X A_B_Sqrt_X::operator-() {
    // Định nghĩa phép đổi dấu
}

A_B_Sqrt_X A_B_Sqrt_X::operator*(const A_B_Sqrt_X& other) {
    // Định nghĩa phép nhân
}

ostream& operator<<(ostream& out, const A_B_Sqrt_X& number) {
    // Định nghĩa phép xuất
    return out;
}

istream& operator>>(istream& in, A_B_Sqrt_X& number) {
    // Định nghĩa phép nhập
    return in;
}

int main() {
    // Thêm code chương trình chính nếu cần
    return 0;
}
