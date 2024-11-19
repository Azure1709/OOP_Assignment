#include "Sheep.h"
#include <cstdlib>

Sheep::Sheep(int initialCount) : Animal(initialCount) {
    sound = "Baa"; // Tieng keu cua cuu
}

Sheep::~Sheep() {} // Destructor

std::string Sheep::getSound() const {
    return sound; // Tra ve tieng keu cua cuu
}

void Sheep::reproduce() {
    for (int i = 0; i < count; ++i) {
        count += rand() % 2; // Moi cuu co the sinh ngau nhien 0-1 con
    }
}

int Sheep::giveMilk() {
    int totalMilk = 0;
    for (int i = 0; i < count; ++i) {
        totalMilk += rand() % 6; // Moi cuu cho ngau nhien 0-5 lit sua
    }
    return totalMilk;
}
