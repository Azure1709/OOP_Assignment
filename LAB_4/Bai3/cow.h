#ifndef COW_H
#define COW_H

#include "Animal.h"

class Cow : public Animal {
public:
    Cow(int initialCount);  // Khoi tao voi so luong bo ban dau
    ~Cow();                 // Destructor

    std::string getSound() const override; // Lay tieng keu cua bo
    void reproduce() override;             // Bo sinh con
    int giveMilk() override;               // Bo cho sua
};

#endif
