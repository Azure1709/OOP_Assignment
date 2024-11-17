#include "bai2.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ll long long

ll calculateTotalRevenueByType(const std::vector<Room*>& rooms, const std::string& type) {
    ll total = 0;
    for (const auto& room : rooms) {
        if (room->getType() == type) {
            total += room->calculateRevenue();
        }
    }
    return total;
}
