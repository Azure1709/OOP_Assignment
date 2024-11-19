#ifndef GOAT_H
#define GOAT_H

#include "Animal.h"

class Goat : public Animal {
public:
    Goat(int initialCount);  // Khoi tao voi so luong de ban dau
    ~Goat();                 // Destructor

    std::string getSound() const override; // Lay tieng keu cua de
    void reproduce() override;             // De sinh con
    int giveMilk() override;               // De cho sua
};

#endif
