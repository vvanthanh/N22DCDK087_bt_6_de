#include <math.h>
#include <stdio.h>

class Function {
public:
    virtual double Value(double x) = 0;
    virtual double Derive(double x) = 0;
};

class Sin : public Function {
public:
    double Value(double x) override {
        return sin(x);
    }

    double Derive(double x) override {
        return cos(x);
    }
};

double DeriveQuotient(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL && g->Value(x) != 0) {
        double numerator = f->Derive(x) * g->Value(x) - f->Value(x) * g->Derive(x);
        double denominator = g->Value(x) * g->Value(x);
        return numerator / denominator;
    }
    return 0;
}

double DeriveComposition(Function* f, Function* g, double x) {
    if (f != NULL && g != NULL) {
        return f->Derive(g->Value(x)) * g->Derive(x);
    }
    return 0;
}

int main() {
    double x = 3.14 / 6; // PI/6
    Sin* s = new Sin();

    double derivativeQuotient = DeriveQuotient(s, s, x);
    double derivativeComposition = DeriveComposition(s, s, x);

    printf("sin(x) = %f; sin'(x) = %f\n", s->Value(x), s->Derive(x));
    printf("Derivative of Quotient: %f\n", derivativeQuotient);
    printf("Derivative of Composition: %f\n", derivativeComposition);

    delete s;

    return 0;
}
