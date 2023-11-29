// Phương thức hủy
~linearList() {
    while (this) {
        linearList* temp = this;
        this = this->subLst;
        delete temp;
    }
}