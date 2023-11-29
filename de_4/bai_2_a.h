class EyedFace : public IFace {
private:
    string shape;
    int eyes;

public:
    // Constructor nhận 2 tham số
    EyedFace(const string& sh, const int& e) : shape(sh), eyes(e) {
    }

    // Phương thức show() xuất ra màn hình giá trị của cả 2 thuộc tính
    virtual void show() {
        cout << "Shape: " << shape << ", Eyes: " << eyes << endl;
    }

    // Phương thức clone() trả về một đối tượng EyedFace mới là một bản sao của đối tượng này
    virtual IFace* clone() {
        return new EyedFace(shape, eyes);
    }

    // Hàm hủy
    virtual ~EyedFace() {
        this->shape = "";
        this->eyes = 0;
    }
};

