 #include <iostream>
#include <string>

using namespace std;

class IFace {
public:
    virtual void show() = 0;
    virtual IFace* clone() = 0;
    virtual ~IFace() {
    }
};

class Face : public IFace {
private:
    string shape;

public:
    Face() : shape("") {
    }

    Face(string sh) : shape(sh) {
    }

    virtual void show() {
        cout << "Shape: " << shape << endl;
    }

    // Thêm hàm để lấy giá trị của shape
    string getShape() const {
        return shape;
    }

    virtual IFace* clone() {
        IFace* Clone = new Face();
        // Sử dụng hàm getShape() để lấy giá trị shape
        dynamic_cast<Face*>(Clone)->shape = this->getShape();
        return Clone;
    }
};

void testFace(IFace* fc) {
    IFace* a[3] = { fc, fc->clone(), fc->clone() };
    for (int i = 0; i < 3; i++) {
        a[i]->show();
    }
    cout << "The same 3 lines?";
}

int main() {
    Face fc("Rectangle");
    testFace(&fc);
    return 0;
}



		


