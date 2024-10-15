#include <iostream>
#include <iomanip>
#include "List.h"

List::List() : arr(nullptr), size(0) {}

List::~List() {
    delete[] arr; // Giai phong bo nho
}

void List::add(double x) {
    double* newArr = new double[size + 1]; // Tao mang moi lon hon
    for (unsigned int i = 0; i < size; ++i) {
        newArr[i] = arr[i]; // Sao chep du lieu cu
    }
    newArr[size] = x; // Them phan tu moi
    delete[] arr;     // Giai phong bo nho cu
    arr = newArr;     // Cap nhat con tro
    size++;           // Tang kich thuoc
}

void List::removeFirst(double x) {
    for (unsigned int i = 0; i < size; ++i) {
        if (arr[i] == x) {
            for (unsigned int j = i; j < size - 1; ++j) {
                arr[j] = arr[j + 1]; // Dich cac phan tu ben phai
            }
            size--; // Giam kich thuoc
            break; // Thoat sau khi da xoa
        }
    }
}

void List::removeAll(double x) {
    unsigned int i = 0;
    while (i < size) {
        if (arr[i] == x) {
            removeFirst(x); // Goi phuong thuc xoa phan tu dau tien
        } else {
            i++;
        }
    }
}

void List::update(int index, double y) {
    if (index >= 0 && index < size) {
        arr[index] = y; // Cap nhat phan tu
    }
}

void List::print() const {
    std::cout << "[";
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl; // Ket thuc in ra
}
