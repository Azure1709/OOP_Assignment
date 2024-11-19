#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
using namespace std;

class Animal {
protected:
    string sound; // Tieng keu cua dong vat
    int count;         // So luong dong vat

public:
    Animal(int initialCount); // Ham khoi tao voi so luong ban dau
    ~Animal();                // Destructor khong su dung virtual

    // Phuong thuc lay tieng keu cua dong vat (phai duoc ghi de trong lop con)
    virtual string getSound() const = 0;

    // Phuong thuc sinh con (phai duoc ghi de trong lop con)
    virtual void reproduce() = 0;

    // Phuong thuc cho sua (phai duoc ghi de trong lop con)
    virtual int giveMilk() = 0;

    int getCount() const; // Lay so luong dong vat hien tai
};

#endif
