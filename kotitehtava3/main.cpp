#include <iostream>
#include <string>

using namespace std;

class Chef {

protected:
    string name;

public:

    Chef(string chefName) : name(chefName) {
        cout  << name << " konstruktori" << endl;
    }

    ~Chef() {
        cout  << name << " destruktori" << endl;
    }


    void makeSalad() {
        cout << name << " makes salad" << endl;

    }

    void makeSoup() {
        cout << name << " makes soup" << endl;
    }
};

class italianChef : public Chef {

private:
    int water;
    int flour;

public:
    italianChef(string chefName, int vesi, int jauhot) : Chef(chefName), water(vesi), flour(jauhot) {

    }

    ~italianChef() {

    }



    void makePasta(int vesi, int jauhot) {
        cout << name << " makes pasta with special recipe" << endl;
        cout << name << " uses jauhot = " << jauhot << endl;
        cout << name << " uses vesi = " << vesi << endl;
        water -= vesi;
        flour -= jauhot;

    }
};

int main()
{
    Chef chef1("Chef Gordon Ramsay");
    chef1.makeSalad();
    chef1.makeSoup();

    Chef chef2("Chef Anthony Bourdain");
    chef2.makeSalad();
    chef2.makeSoup();

    italianChef italianChef1("Chef Jyrki", 110, 260);
    italianChef italianChef2("Chef Mario", 120, 270);

    italianChef1.makeSalad();
    italianChef2.makePasta(100, 250);
    italianChef1.makeSoup();


    return 0;
}
