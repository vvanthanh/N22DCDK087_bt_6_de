#include <iostream>
using namespace std;

class MayXucTac {
private:
    float congSuat; // Công suất lọc (m3/h)
    float thoiGian; // Thời gian hoạt động (h)
    float luongHoaChat; // Lượng hóa chất (g)

public:
    static const int DON_GIA_THUE = 80000; // Đơn giá thuê (đồng/h)
    static const int DON_GIA_HOA_CHAT = 10000; // Đơn giá hóa chất (đồng/g)

    MayXucTac() {
        congSuat = 0;
        thoiGian = 0;
        luongHoaChat = 0;
    }

    void nhap() {
        cout << "Nhap cong suat (m3/h): ";
        cin >> congSuat;
        cout << "Nhap thoi gian hoat dong (h): ";
        cin >> thoiGian;
        cout << "Nhap luong hoa chat (g): ";
        cin >> luongHoaChat;
    }

    float tinhLuongNuoc() {
        float congSuatThucTe;
        if (thoiGian < 10) {
            congSuatThucTe = congSuat * (luongHoaChat / 100);
        } else {
            congSuatThucTe = congSuat * (luongHoaChat / 100) / (thoiGian / 10);
        }

        return congSuatThucTe * thoiGian;
    }

    float tinhChiPhi() {
        float chiPhiThue = DON_GIA_THUE * thoiGian;
        float chiPhiHoaChat = DON_GIA_HOA_CHAT * luongHoaChat;

        return chiPhiThue + chiPhiHoaChat;
    }
};

int main() {
    cout << "Don gia hoa chat: " << MayXucTac::DON_GIA_HOA_CHAT << endl;
    MayXucTac m;
    m.nhap(); // Nhập thông tin sử dụng của máy xúc tác này
    cout << "Chi phi su dung may: " << m.tinhChiPhi() << endl;
    cout << "Luong nuoc loc duoc: " << m.tinhLuongNuoc() << endl;

    return 0;
}
