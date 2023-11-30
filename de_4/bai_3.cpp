#include <iostream>
#include <vector>

using namespace std;

// Lớp định nghĩa cước điện thoại 
class CuocDT {
private:
    float thoiGian; // Số giờ gọi
public:
    static long G_DT; // Giá cước điện thoại

    long tinhCuoc() {
        return G_DT * static_cast<long>(thoiGian);
    }
};

long CuocDT::G_DT = 1000;

// Lớp định nghĩa cước internet 
class CuocNet {
private:
    long luongTruyCap; // Lượng truy cập internet
public:
    static long G_NET; // Giá cước internet

    long tinhCuoc() {
        return G_NET * luongTruyCap;
    }
};

long CuocNet::G_NET = 200;

// Lớp định nghĩa thông tin của khách hàng 
class KhachHang {
private:
    string HoTen;
    string CMND;
    string DiaChi;

public:
    // Hàm đăng ký thông tin của khách hàng
    void dangKy() {
        cout << "Nhap ho va ten:";
        cin.ignore();
        getline(cin, HoTen);
        cout << "Nhap so CMND:";
        cin >> CMND;
        cout << "Nhap dia chi:";
        cin.ignore();
        getline(cin, DiaChi);
    }

    // Hàm xuất thông tin của khách hàng
    void xuat() const {
        cout << "Ho va ten: " << HoTen << endl;
        cout << "So CMND: " << CMND << endl;
        cout << "Dia chi: " << DiaChi << endl;
    }
};

// Lớp định nghĩa cước (abstract class)
class Cuoc {
protected:
    CuocDT cuocDT; // Gồm cả cước điện thoại

public:
    static long VAT; // Thuế VAT
    virtual long tinhCuoc() = 0; // Phương thức ảo để tính cước
};

long Cuoc::VAT = 10;

// Lớp định nghĩa cước cơ bản 
class CoBan : public Cuoc {
private:
    CuocNet cuocNet; // Gồm cả cước internet

public:
    // Hàm tính cước cho gói cước cơ bản 
    long tinhCuoc() override {
        return cuocDT.tinhCuoc() + cuocNet.tinhCuoc() + cuocDT.tinhCuoc() * VAT / 100;
    }
};

// Lớp định nghĩa cước Data 
class CuocData : public Cuoc {
private:
    long luongTruyCap; // Lượng truy cập internet

public:
    static long NM_PHI; // Ngưỡng miễn phí
    static long CUOC_TB; // Cước thuê bao

    // Hàm tính cước cho gói cước Data
    long tinhCuoc() override {
        long cuocDT = this->cuocDT.tinhCuoc();
        long cuocNet = (luongTruyCap <= NM_PHI) ? CUOC_TB : CUOC_TB + cuocDT * (luongTruyCap - NM_PHI);
        return cuocDT + cuocNet;
    }
};

long CuocData::NM_PHI = 5;
long CuocData::CUOC_TB = 50000;

// Lớp định nghĩa cước cố định 
class CuocCoDinh : public Cuoc {
public:
    static long M_CD; // Mức cước cố định

    // Hàm tính cước cho gói cước cố định 
    long tinhCuoc() override {
        return 0.9 * cuocDT.tinhCuoc() + M_CD;
    }
};

long CuocCoDinh::M_CD = 1000000;

// Lớp định nghĩa hợp đồng 
class HopDong {
private:
    KhachHang khachHang;
    Cuoc* cuoc; // Con trỏ đến lớp cước

public:
    int lc;

    // Hàm đăng ký hợp đồng 
    void dangKy() {
        khachHang.dangKy();
        cout << "Chon goi cuoc: 1-Co Ban, 2-Cuoc Data, 3-Cuoc Co Dinh:\n";
        cin >> lc;

        switch (lc) {
            case 1:
                cuoc = new CoBan();
                break;
            case 2:
                cuoc = new CuocData();
                break;
            case 3:
                cuoc = new CuocCoDinh();
                break;
            default:
                cuoc = new CoBan();
                break;
        }
    }

    // Hàm thông báo thông tin hợp đồng 
    void thongBao() {
        cout << "Khach hang:\n";
        khachHang.xuat();
        cout << "Tien cuoc goi cuoc la:" << cuoc->tinhCuoc() << endl;
    }

    ~HopDong() {
        delete cuoc;
        cuoc = nullptr;
    }
};

// Lớp quản lý hợp đồng 
class QuanLyHD {
private:
    vector<HopDong*> dsHD;

public:
    // Hàm đăng ký nhiều hợp đồng 
    void dangKy() {
        int n;
        cout << "Nhap so luong hop dong:";
        cin >> n;

        for (int i = 0; i < n; i++) {
            HopDong* hd = new HopDong();
            hd->dangKy();
            dsHD.push_back(hd);
        }
    }

    // Hàm thông báo thông tin của tất cả hợp đồng 
    void thongBao() {
        for (int i = 0; i < dsHD.size(); i++) {
            dsHD[i]->thongBao();
        }
    }

    // Hủy tất cả hợp đồng và giải phóng bộ nhớ 
    ~QuanLyHD() {
        for (int i = 0; i < dsHD.size(); i++) {
            if (dsHD[i]) {
                delete dsHD[i];
                dsHD[i] = nullptr;
            }
        }
        dsHD.resize(0);
    }
};

int main() {
    QuanLyHD ql;
    ql.dangKy();
    ql.thongBao();
    return 0;
}

