#include <iostream>
using namespace std;

class absList { // Bắt đầu của lớp absList
protected:
    int dataId;

public:
    absList(int pId = 0) {
        dataId = pId;
    }

    virtual ~absList() {}

    int getData() {
        return dataId;
    }

    virtual absList* addFirst(int pId) = 0;
    virtual absList* getSubItem() = 0;
    virtual void showAll(ostream&) = 0;

    virtual int countAll() {
        return 0; // tạm thời 0 phần tử
    }
}; // Kết thức lớp absList

// Lớp linearList
class linearList : public absList {
    absList* subLst;

public:
    linearList(int pId) : absList(pId) {
        subLst = NULL;
    }

    virtual ~linearList() {
        if (subLst != NULL)
            delete subLst;
    }

    class simpleList : public absList {
    public:
        simpleList(int pId) : absList(pId) {
        }

        virtual absList* addFirst(int pId) {
            dataId = pId;
            return this;
        }

        virtual absList* getSubItem() {
            return NULL; // Không có thành phần con
        }

        virtual void showAll(ostream& outDev) {
            outDev << dataId << " ";
        }

        virtual int countAll() {
            return 1; // Chỉ có đúng một phần tử
        }
    };

    virtual absList* addFirst(int pId) {
        linearList* Lst = new linearList(pId);
        Lst->subLst = this;
        return Lst;
    }

    virtual absList* getSubItem() {
        return subLst;
    }

    virtual void showAll(ostream& outDev) {
        // Phương thức này chưa viết xong...
    }
}; // Kết thúc linearList

void main() {
    simpleList *sLst = new simpleList(-13); absList *lnkLst = new linearList(37);
    for (int i = 1; i <= 8; i++) { 
        lnkLst = lnkLst->addFirst(i * i - 7 * i);
    }
    delete lnkLst;
}
