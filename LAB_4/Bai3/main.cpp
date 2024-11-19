#include <iostream>
#include <cstdlib> 
#include <ctime>   
#include "Cow.h"
#include "Sheep.h"
#include "Goat.h"
using namespace std;

int main() {
    srand(time(0)); 

    int initialCows, initialSheep, initialGoats;

    cout << "Enter the initial number of cows: ";
    cin >> initialCows;
    cout << "Enter the initial number of sheep: ";
    cin >> initialSheep;
    cout << "Enter the initial number of goats: ";
    cin >> initialGoats;

    // Tao doi tuong tung loai gia suc
    Cow cows(initialCows);
    Sheep sheep(initialSheep);
    Goat goats(initialGoats);

    // Su dung mang con tro de quan ly doi tuong dong vat
    Animal* animals[3] = {&cows, &sheep, &goats};

    // a) Tat ca gia suc doi va keu
    cout << "\nWhen hungry, the sounds heard on the farm are:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < animals[i]->getCount(); j++) {
            cout << animals[i]->getSound() << " ";
        }
    }
    cout << "\n";

    // b) Thong ke sau khi sinh con va cho sua
    int totalMilk = 0; // Tong sua san xuat
    for (int i = 0; i < 3; i++) {
        // Moi loai sinh con
        animals[i]->reproduce();

        // Tong sua cua tung loai
        totalMilk += animals[i]->giveMilk();
    }

    // Hien thi thong ke
    cout << "\nStatistics after reproduction and milk production:\n";
    cout << "Cows: " << cows.getCount() << "\n";
    cout << "Sheep: " << sheep.getCount() << "\n";
    cout << "Goats: " << goats.getCount() << "\n";
    cout << "Total milk produced: " << totalMilk << " liters\n";

    return 0;
}
