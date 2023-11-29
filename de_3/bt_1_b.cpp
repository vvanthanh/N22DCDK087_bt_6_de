#include <iostream>
#include <cmath>

class A_B_Sqrt_X {
private:
    int _a;
    int _b;
    static const int _SO_DUOI_DAU_CAN = 7;

public:
    // Constructor
    A_B_Sqrt_X(const int& a, const int& b) : _a(a), _b(b) {}

    // Constructor mặc định
    A_B_Sqrt_X() : _a(0), _b(0) {}

    // Phép cộng
    A_B_Sqrt_X operator+(const A_B_Sqrt_X& a_b_Sq_x) const {
        return A_B_Sqrt_X(_a + a_b_Sq_x._a, _b + a_b_Sq_x._b);
    }

    // Phép trừ
    A_B_Sqrt_X operator-(const A_B_Sqrt_X& a_b_Sq_x) const {
        return A_B_Sqrt_X(_a - a_b_Sq_x._a, _b - a_b_Sq_x._b);
    }

    // Phép đổi dấu
    A_B_Sqrt_X operator-() const {
        return A_B_Sqrt_X(-_a, -_b);
    }

    // Phép nhân
    A_B_Sqrt_X operator*(const A_B_Sqrt_X& a_b_Sq_x) const {
        A_B_Sqrt_X result;
        result._a = _a * a_b_Sq_x._a + _b * a_b_Sq_x._b * _SO_DUOI_DAU_CAN;
        result._b = _a * a_b_Sq_x._b + _b * a_b_Sq_x._a;
        return result;
    }

    // Xuất số
    friend std::ostream& operator<<(std::ostream& os, const A_B_Sqrt_X& a_b_Sq_x) {
        os << a_b_Sq_x._a << " + (" << a_b_Sq_x._b << ")*sqrt(" << A_B_Sqrt_X::_SO_DUOI_DAU_CAN << ")";
        return os;
    }

    // Nhập số
    friend std::istream& operator>>(std::istream& is, A_B_Sqrt_X& a_b_Sq_x) {
        std::cout << "Nhap phan thuc a: ";
        is >> a_b_Sq_x._a;
        std::cout << "Nhap phan ao b: ";
        is >> a_b_Sq_x._b;
        return is;
    }
};

int main() {
    A_B_Sqrt_X so1(1, 2);
    A_B_Sqrt_X so2(3, -4);

    // Thực hiện các phép toán và in ra kết quả
    A_B_Sqrt_X tong = so1 + so2;
    A_B_Sqrt_X hieu = so1 - so2;
    A_B_Sqrt_X doiDau = -so1;
    A_B_Sqrt_X tich = so1 * so2;

    std::cout << "Tong: " << tong << std::endl;
    std::cout << "Hieu: " << hieu << std::endl;
    std::cout << "Dao dau cua so1: " << doiDau << std::endl;
    std::cout << "Tich: " << tich << std::endl;

    return 0;
}
