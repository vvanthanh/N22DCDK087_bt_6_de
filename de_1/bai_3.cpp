#include <iostream>
#include <vector>
using namespace std;

// Lớp cơ sở MayLoc
class MayLoc {
protected:
    double tgian; // Thời gian hoạt động (h)

public:
    MayLoc(double t) : tgian(t) {}

    virtual double congSuat() const = 0; // Phương thức ảo thuần ảo
    virtual double tinhChiPhi() const = 0; // Phương thức ảo thuần ảo
    double getThoiGian() const { return tgian; } // Thêm phương thức lấy giá trị của tgian
    virtual ~MayLoc() {} // Hàm hủy ảo
};

// Lớp MayLyTam kế thừa từ MayLoc
class MayLyTam : public MayLoc {
private:
    double cs; // Công suất lọc (m3/h)

public:
    MayLyTam(double cs, double t) : MayLoc(t), cs(cs) {}

    double congSuat() const override {
        return cs;
    }

    double tinhChiPhi() const override {
        return 50000 * tgian; // Đơn giá thuê 50.000 đồng/h
    }
};

// Lớp MayXucTac kế thừa từ MayLoc
class MayXucTac : public MayLoc {
private:
    double cs; // Công suất lọc (m3/h)
    double luongHoaChat; // Lượng hóa chất (g)

public:
    MayXucTac(double cs, double lh, double t) : MayLoc(t), cs(cs), luongHoaChat(lh) {}

    double congSuat() const override {
        if (tgian < 10) {
            return cs * (luongHoaChat / 100);
        } else {
            return cs * (luongHoaChat / 100) / (tgian / 10);
        }
    }

    double tinhChiPhi() const override {
        // Đơn giá thuê 80.000 đồng/h, đơn giá hóa chất 10.000 đồng/g
        return 80000 * tgian + 10000 * luongHoaChat; 
    }
};

// Lớp quản lý MayLoc
class QuanLyMayLoc {
private:
    vector<MayLoc *> danhSachMayLoc; // Danh sách các máy lọc

public:
    ~QuanLyMayLoc() {
        for (MayLoc *mayLoc : danhSachMayLoc) {
            delete mayLoc; // Giải phóng bộ nhớ
        }
    }

    void themMayLoc(MayLoc *mayLoc) {
        danhSachMayLoc.push_back(mayLoc);
    }

    bool locHetNuoc(double luongNuocAo) const {
        double luongNuocLoc = 0;
        for (const MayLoc *mayLoc : danhSachMayLoc) {
            luongNuocLoc += mayLoc->congSuat() * mayLoc->getThoiGian();
        }
        return luongNuocLoc >= luongNuocAo;
    }

    double tinhTongChiPhi() const {
        double tongChiPhi = 0;
        for (const MayLoc *mayLoc : danhSachMayLoc) {
            tongChiPhi += mayLoc->tinhChiPhi();
        }
        return tongChiPhi;
    }
};

int main() {
    QuanLyMayLoc quanLyMayLoc;

    int N;
    cout << "Nhap so luong may loc (N): ";
    cin >> N;

    for (int i = 0; i < N; ++i) {
        int loaiMayLoc;
        cout << "Chon loai may loc (1 - MayLyTam, 2 - MayXucTac): ";
        cin >> loaiMayLoc;

        double cs, tgian, luongHoaChat;
        cout << "Nhap cong suat (m3/h): ";
        cin >> cs;
        cout << "Nhap thoi gian hoat dong (h): ";
        cin >> tgian;

        if (loaiMayLoc == 1) {
            quanLyMayLoc.themMayLoc(new MayLyTam(cs, tgian));
        } else if (loaiMayLoc == 2) {
            cout << "Nhap luong hoa chat (g): ";
            cin >> luongHoaChat;
            quanLyMayLoc.themMayLoc(new MayXucTac(cs, luongHoaChat, tgian));
        } else {
            cout << "Loai may loc khong hop le." << endl;
            return 1;
        }
    }

    double luongNuocAo;
    cout << "Nhap luong nuoc trong ao (m3): ";
    cin >> luongNuocAo;

    if (quanLyMayLoc.locHetNuoc(luongNuocAo)) {
        cout << "Ao co duoc loc het nuoc." << endl;
    } else {
        cout << "Ao khong duoc loc het nuoc." << endl;
    }

    cout << "Tong chi phi may loc: " << quanLyMayLoc.tinhTongChiPhi() << " dong." << endl;

    return 0;
}

