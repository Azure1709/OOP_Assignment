#include "Cow.h"
#include <cstdlib>

Cow::Cow(int initialCount) : Animal(initialCount) {
    sound = "Mo0o";
}

Cow::~Cow() {} 

std::string Cow::getSound() const {
    return sound; 
}

void Cow::reproduce() {
    for (int i = 0; i < count; ++i) {
        count += rand() % 2; 
    }
}

int Cow::giveMilk() {
    int totalMilk = 0;
    for (int i = 0; i < count; ++i) {
        totalMilk += rand() % 21; 
    }
    return totalMilk;
}
