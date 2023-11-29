#include <cmath>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Cos : public Function {
public:
    double Value(double x) override {
        return cos(x);
    }

    double Derive(double x) override {
        return -sin(x);
    }
};

double DaoHamThuong(Function* f, Function* g, double x) {
    if (g != NULL) {
        return (f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x)) / (g->Value(x) * g->Value(x));// f(x)/g(x)=
    }
    return 0;
}

double DaoHamCuaHamHop(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
    return 0;
}

