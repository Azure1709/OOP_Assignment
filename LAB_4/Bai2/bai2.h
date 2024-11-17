#ifndef BAI2_H
#define BAI2_H

#include <string>
#include <vector>
#include <iomanip> 
#define ll long long
using namespace std;


class Room {
protected:
    int nights;
    ll serviceFee;
    ll additionalFee;

public:
    Room(int nights, ll serviceFee = 0, ll additionalFee = 0)
        : nights(nights), serviceFee(serviceFee), additionalFee(additionalFee) {}

    virtual ~Room() {}

    virtual ll calculateRevenue() const = 0;
    virtual string getType() const = 0;
};

class Deluxe : public Room {
public:
    Deluxe(int nights, ll serviceFee, ll additionalFee)
        : Room(nights, serviceFee, additionalFee) {}

    ll calculateRevenue() const override {
        return nights * 750000 + serviceFee + additionalFee;
    }

    string getType() const override {
        return "Deluxe";
    }
};

class Premium : public Room {
public:
    Premium(int nights, ll serviceFee)
        : Room(nights, serviceFee) {}

    ll calculateRevenue() const override {
        return nights * 500000 + serviceFee;
    }

    string getType() const override {
        return "Premium";
    }
};

class Business : public Room {
public:
    Business(int nights)
        : Room(nights) {}

    ll calculateRevenue() const override {
        return nights * 300000;
    }

    string getType() const override {
        return "Business";
    }
};

#endif

