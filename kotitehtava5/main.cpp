#include <iostream>

using namespace std;

class Asunto {
public:
    int asukasMaara;
    int neliot;

    // Asunnon konstruktori, asukasmääräksi 2 ja neliöiksi 100
    Asunto() : asukasMaara(2), neliot(100) {
        cout << "Asunto luotu" << endl;
    }

    // Metodi asunnon tietojen määrittämiseksi
    void maarita(int asukkaat, int pintaAla) {
        asukasMaara = asukkaat;
        neliot = pintaAla;
        cout << "Asunto maaritetty: asukkaita= " << asukasMaara << " nelioita= " << neliot << endl;
    }

    // Metodi asunnon kulutuksen laskemiseksi
    double laskeKulutus(double energiankulutus) {
        return energiankulutus * neliot;
    }
};

class Kerros {

private:
    Asunto* as1;
    Asunto* as2;
    Asunto* as3;
    Asunto* as4;

public:
    // Kerroksen konstruktori
    Kerros () {
        cout << "Kerros luotu" << endl;
        as1 = new Asunto();
        as2 = new Asunto();
        as3 = new Asunto();
        as4 = new Asunto();
    }

    // Metodi kerroksen asuntojen määrittämiseksi
    virtual void maaritaAsunnot() {
        cout << "Maaritetaan 4 kpl kerroksen asuntoja" << endl;
        as1->maarita(2, 100);
        as2->maarita(2, 100);
        as3->maarita(2, 100);
        as4->maarita(2, 100);
    }

    // Metodi kerroksen kokonaiskulutuksen laskemiseksi
    virtual double laskeKulutus(double energiankulutus) {
    return (as1->laskeKulutus(energiankulutus) + as2->laskeKulutus(energiankulutus)
    + as3->laskeKulutus(energiankulutus) + as4->laskeKulutus(energiankulutus)) * 2;
    }

    ~Kerros() {
        delete as1;
        delete as2;
        delete as3;
        delete as4;
    }
};

class Katutaso : public Kerros {

private:
    Asunto* as1;
    Asunto* as2;

public:
    // Katutason konstruktori
    Katutaso() {
        cout << "Katutaso luotu" << endl;
        as1 = new Asunto();
        as2 = new Asunto();
    }

    // Metodi katutason asuntojen määrittämiseksi
    void maaritaAsunnot() override {
        cout << "Maaritetaan 2 kpl katutason asuntoja" << endl;
        as1->maarita(2, 100);
        as2->maarita(2, 100);
    }

    // Metodi katutason kokonaiskulutuksen laskemiseksi
    double laskeKulutus(double energiankulutus) override {
        return (as1->laskeKulutus(energiankulutus) + as2->laskeKulutus(energiankulutus)) * 2;
    }

    ~Katutaso() {
        delete as1;
        delete as2;
    }
};

class Kerrostalo {
private:
    Katutaso* eka;
    Kerros* toka;
    Kerros* kolmas;

public:

    // Kerrostalon konstruktori
    Kerrostalo() {
        cout << "Kerrostalo luotu" << endl;
        eka = new Katutaso();
        toka = new Kerros();
        kolmas = new Kerros();
        cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;
    }

    // Metodi kerrostalon kaikkien asuntojen määrittämiseksi
    void maaritaAsunnot() {
        eka->maaritaAsunnot();
        cout << "Maaritetaan katutason kerrokselta perittyja asuntoja" << endl;
        toka->maaritaAsunnot();
        kolmas->maaritaAsunnot();
    }

    // Metodi kerrostalon kokonaiskulutuksen laskemiseksi
    double laskeKulutus(double energiankulutus) {
        return eka->laskeKulutus(energiankulutus) + toka->laskeKulutus(energiankulutus) + kolmas->laskeKulutus(energiankulutus);
    }

    ~Kerrostalo() {
        delete eka;
        delete toka;
        delete kolmas;
    }
};

int main() {

    Kerrostalo* talo = new Kerrostalo();

    talo->maaritaAsunnot();

    double energiankulutus = 1.0;
    double kokonaiskulutus = talo->laskeKulutus(energiankulutus);

    cout << "Kerrostalon kulutus, = " << kokonaiskulutus << endl;

    delete talo;

    return 0;
}
