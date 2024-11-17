#include "bai2.h"
#include <iostream>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;


int main() {
    vector<Room*> rooms;
    int n; 
    cout << "Nhap so luong phong: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int type;
        cout << "\nChon loai phong (1: Deluxe, 2: Premium, 3: Business): ";
        cin >> type;

        if (type == 1) {
            int nights;
            double serviceFee, additionalFee;
            cout << "Nhap so dem: ";
            cin >> nights;
            cout << "Nhap phi dich vu: ";
            cin >> serviceFee;
            cout << "Nhap phi phuc vu: ";
            cin >> additionalFee;
            rooms.push_back(new Deluxe(nights, serviceFee, additionalFee));
        } 
        else if (type == 2) {
            int nights;
            double serviceFee;
            cout << "Nhap so dem: ";
            cin >> nights;
            cout << "Nhap phi dich vu: ";
            cin >> serviceFee;
            rooms.push_back(new Premium(nights, serviceFee));
        } 
        else if (type == 3) {
            int nights;
            cout << "Nhap so dem: ";
            cin >> nights;
            rooms.push_back(new Business(nights));
        } 
        else {
            cout << "Loai phong khong hop le! Vui long chon lai.\n";
            --i; 
        }
    }
    
    // Tong doanh thu theo loai phong
    map<string, double> totalRevenue;
    for (const auto& room : rooms) {
        totalRevenue[room->getType()] += room->calculateRevenue();
    }

    // Loai phong co doanh thu cao nhat
    string bestType;
    double maxRevenue = 0;
    for (const auto& [type, revenue] : totalRevenue) {
        if (revenue > maxRevenue) {
            maxRevenue = revenue;
            bestType = type;
        }
    }
    // Doanh thu tung loai phong
    cout << fixed << setprecision(0);
    cout << "\nDoanh thu tung loai phong:\n";
    for (const auto& [type, revenue] : totalRevenue) {
        cout << " - " << type << ": " << revenue << " VND\n";
        
    }
    cout << fixed << setprecision(0); // Dinh dang so khong co chu 'e'
    cout << "\nLoai phong co doanh thu cao nhat: \n" << bestType 
          << " voi doanh thu: " << maxRevenue << " VND\n";

    // Don dep bo nho
    for (auto room : rooms) {
        delete room;
    }

    return 0;
}
