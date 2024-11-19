#include "bai3.h"
#include <cstdlib> 
#include <ctime>   
#include <string>


Animal::Animal(std::string name, int count) : name(name), count(count) {}


int Animal::getCount() const {
    return count;
}

void Animal::addCount(int n) {
    count += n;
}

Cow::Cow(int count) : Animal("Cow", count) {}

std::string Cow::makeSound() const {
    return "Moo";
}

int Cow::produceMilk() const {
    return rand() % 21; 
}

int Cow::reproduce() const {
    return rand() % 4 + 1; 
}

Sheep::Sheep(int count) : Animal("Sheep", count) {}

std::string Sheep::makeSound() const {
    return "Baa";
}

int Sheep::produceMilk() const {
    return rand() % 6; 
}

int Sheep::reproduce() const {
    return rand() % 3 + 1; 
}

Goat::Goat(int count) : Animal("Goat", count) {}

std::string Goat::makeSound() const {
    return "Bleat";
}

int Goat::produceMilk() const {
    return rand() % 11; 
}

int Goat::reproduce() const {
    return rand() % 3 + 1; 
}
