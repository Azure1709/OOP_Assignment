#ifndef bai3_H
#define bai3_H

#include <string>
#include <vector>

class Animal {
protected:
    std::string name;
    int count; 

public:
    Animal(std::string name, int count);
    virtual ~Animal() = default;

    virtual std::string makeSound() const = 0;
    virtual int produceMilk() const = 0;
    virtual int reproduce() const = 0;

    int getCount() const;
    void addCount(int n);
};

class Cow : public Animal {
public:
    Cow(int count);
    std::string makeSound() const override;
    int produceMilk() const override;
    int reproduce() const override;
};

class Sheep : public Animal {
public:
    Sheep(int count);
    std::string makeSound() const override;
    int produceMilk() const override;
    int reproduce() const override;
};

class Goat : public Animal {
public:
    Goat(int count);
    std::string makeSound() const override;
    int produceMilk() const override;
    int reproduce() const override;
};

#endif
