#ifndef SHEEP_H
#define SHEEP_H

#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(int initialCount);  // Khoi tao voi so luong cuu ban dau
    ~Sheep();                 // Destructor

    std::string getSound() const override; // Lay tieng keu cua cuu
    void reproduce() override;             // Cuu sinh con
    int giveMilk() override;               // Cuu cho sua
};

#endif
