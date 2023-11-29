#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

public:
    // Constructors
    PhanSo() {
        this->tu = 0;
        this->mau = 1;
    }

    PhanSo(const int& tu, const int& mau) {
        this->tu = tu;
        this->mau = mau;
        if (this->mau == 0) {
            cout << "Mau khong duoc bang 0\n";
            this->tu = 0;
            this->mau = 1;
        }
    }

    // Phép cộng
    PhanSo operator+(const PhanSo& ps) const {
        PhanSo newPhanSo(this->tu * ps.mau + this->mau * ps.tu, this->mau * ps.mau);// 
        return newPhanSo;
    }

    // Phép cộng dạng
    PhanSo& operator+=(const PhanSo& ps) {
        this->tu = this->tu * ps.mau + this->mau * ps.tu;
        this->mau *= ps.mau;
        return *this;
    }

    // Phép cộng với một số nguyên
    PhanSo operator+(const int& iNum) const {
        PhanSo newPhanSo(this->tu + iNum * this->mau, this->mau);
        return newPhanSo;
    }

    // Phép tự tăng
    PhanSo& operator++() {
        this->tu += this->mau;
        return *this;
    }

    // Hàm chuyển đổi sang int
    operator int() const {
        return this->tu / this->mau;
    }

    // Hàm xuất
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        os << ps.tu << "/" << ps.mau;
        return os;
    }

    // Destructor
    ~PhanSo() {
        this->tu = 0;
        this->mau = 1;
    }
};


    