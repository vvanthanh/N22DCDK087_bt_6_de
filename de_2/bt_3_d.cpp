#include <cmath>
#include <iostream>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Sin : public Function {
private:
    static Sin* instance; // Đối tượng Singleton
    Sin() {} // Hạn chế khởi tạo từ bên ngoài

public:
    static Sin* getInstance() {
        if (instance == nullptr) {
            instance = new Sin();
        }
        return instance;
    }

    double Value(double x) override {
        return sin(x);
    }

    double Derive(double x) override {
        return cos(x);
    }
};

Sin* Sin::instance = nullptr;

double DeriveProduct(Function* f, Function* g, double x) {
    if (f != nullptr && g != nullptr) {
        return f->Derive(x) * g->Value(x) + f->Value(x) * g->Derive(x);
    }
    return 0;
}

int main() {
    double x = 3.14 / 6; // PI/6
    Sin* s = Sin::getInstance();

    double y = DeriveProduct(s, s, x);

    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("y = %f\n", y);

    return 0;
}

