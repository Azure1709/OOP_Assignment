#include "Goat.h"
#include <cstdlib>

Goat::Goat(int initialCount) : Animal(initialCount) {
    sound = "Meh"; // Tieng keu cua de
}

Goat::~Goat() {} // Destructor

std::string Goat::getSound() const {
    return sound; // Tra ve tieng keu cua de
}

void Goat::reproduce() {
    for (int i = 0; i < count; ++i) {
        count += rand() % 2; // Moi de co the sinh ngau nhien 0-1 con
    }
}

int Goat::giveMilk() {
    int totalMilk = 0;
    for (int i = 0; i < count; ++i) {
        totalMilk += rand() % 11; // Moi de cho ngau nhien 0-10 lit sua
    }
    return totalMilk;
}
