class Bike {
private:
    char* brand; // hiệu xe

public:
    // Constructors
    Bike() {
        char s[5] = "Bike";
        this->brand = new char[5];
        for (int i = 0; i < 5; i++) {
            this->brand[i] = s[i];
        }
    }

    Bike(char s[]) {
        this->brand = new char[strlen(s) + 1];
        for (int i = 0; i < strlen(s); i++) {
            this->brand[i] = s[i];
        }
        this->brand[strlen(s)] = 0;
    }

    // Destructor
    ~Bike() {
        if (this->brand) {
            delete[] this->brand;
        }
    }

    // Getter for brand
    const char* getBrand() const {
        return brand;
    }

    virtual void move(int t1) {
        cout << brand << ":" << t1 * 12 << " ";
    }
};

class EBike : public Bike {
public:
    using Bike::Bike; // Inherit constructors

    EBike(char s[]) : Bike("EBike") {}
};
