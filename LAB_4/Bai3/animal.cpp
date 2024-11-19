#include "Animal.h"

Animal::Animal(int initialCount) : count(initialCount) {} 

Animal::~Animal() {}

int Animal::getCount() const {
    return count; 
}
