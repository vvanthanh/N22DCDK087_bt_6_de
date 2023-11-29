#include <iostream>
using namespace std;
// Lớp cơ sở MayLoc
class MayLoc {
private:
    float m_tgian;
protected:
    // Phương thức ảo cho tính toán công suất
    virtual float congSuat();
    // Phương thức để thiết lập thời gian hoạt động
    void setTgian(float t);
public:
    // Constructor
    MayLoc();
    // Phương thức tính lượng nước lọc
    float tinhLuongNuoc();
};
// Constructor của lớp MayLoc
MayLoc::MayLoc() {
    this->m_tgian = 0;
}
// Thiết lập thời gian hoạt động
void MayLoc::setTgian(float t) {
    this->m_tgian = t;
}
// Phương thức tính lượng nước lọc (dựa trên công suất và thời gian)
float MayLoc::tinhLuongNuoc() {
    return congSuat() * m_tgian;
}
// Phương thức ảo tính toán công suất (giá trị mặc định là 0)
float MayLoc::congSuat() {
    return 0;
}
// Lớp kế thừa từ MayLoc - MayLyTam
class MayLyTam : public MayLoc {
private:
    float m_cs; // Công suất cho lớp MayLyTam
protected:
    // Override phương thức công suất từ lớp cơ sở
    float congSuat();
public:
    // Constructor của lớp MayLyTam
    MayLyTam(float cs, float t);
};

// Constructor của lớp MayLyTam
MayLyTam::MayLyTam(float cs, float t) {
    this->m_cs = cs;
    setTgian(t); // Sử dụng phương thức từ lớp cơ sở để thiết lập thời gian (LỖI SỬA LẠI)
}
// Override phương thức công suất
float MayLyTam::congSuat() {
    return m_cs; // (LỖI SỬA LẠI)
}
int main() { 
     MayLoc *pm = new MayLyTam(81.9, 10); // (LỖI SỬA LẠI)
    // In ra lượng nước lọc
    cout << "Luong nuoc = " << pm->tinhLuongNuoc() << endl;
    delete pm; // Xoá con trỏ khi không cần nữa
    return 0;
}
