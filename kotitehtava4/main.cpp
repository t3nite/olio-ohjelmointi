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
//public:
private:
    Asunto as1;
    Asunto as2;
    Asunto as3;
    Asunto as4;

public:
    // Kerroksen konstruktori
    Kerros () {
        cout << "Kerros luotu" << endl;
    }

    // Metodi kerroksen asuntojen määrittämiseksi
    virtual void maaritaAsunnot() {
        cout << "Maaritetaan 4 kpl kerroksen asuntoja" << endl;
        as1.maarita(2, 100);
        as2.maarita(2, 100);
        as3.maarita(2, 100);
        as4.maarita(2, 100);
    }

    // Metodi kerroksen kokonaiskulutuksen laskemiseksi
    virtual double laskeKulutus(double energiankulutus) {
        return (as1.laskeKulutus(energiankulutus) + as2.laskeKulutus(energiankulutus)
        + as3.laskeKulutus(energiankulutus) + as4.laskeKulutus(energiankulutus))*2;
    }
};

class Katutaso : public Kerros {
//public:
private:
    Asunto as1;
    Asunto as2;

public:
    // Katutason konstruktori
    Katutaso() {
        cout << "Katutaso luotu" << endl;
    }

    // Metodi katutason asuntojen määrittämiseksi
    void maaritaAsunnot() override {
        cout << "Maaritetaan 2 kpl katutason asuntoja" << endl;
        as1.maarita(2, 100);
        as2.maarita(2, 100);
    }

    // Metodi katutason kokonaiskulutuksen laskemiseksi
    double laskeKulutus(double energiankulutus) override {
        return (as1.laskeKulutus(energiankulutus) + as2.laskeKulutus(energiankulutus))*2;
    }
};

class Kerrostalo {
private:
    Katutaso eka;
    Kerros toka;
    Kerros kolmas;

public:

    // Kerrostalon konstruktori
    Kerrostalo() {
        cout << "Kerrostalo luotu" << endl;
        cout << "Maaritellaan koko kerrostalon kaikki asunnot" << endl;
    }

    // Metodi kerrostalon kaikkien asuntojen määrittämiseksi
    void maaritaAsunnot() {
        eka.maaritaAsunnot();
        cout << "Maaritetaan katutason kerrokselta perittyja asuntoja" << endl;
        toka.maaritaAsunnot();
        kolmas.maaritaAsunnot();
    }

    // Metodi kerrostalon kokonaiskulutuksen laskemiseksi
    double laskeKulutus(double energiankulutus) {
        return eka.laskeKulutus(energiankulutus) + toka.laskeKulutus(energiankulutus) + kolmas.laskeKulutus(energiankulutus);
    }
};

int main() {

    //Debug rivit

    /*Asunto asunto;
    asunto.maarita(2, 100);
    double kulutus = asunto.laskeKulutus(1);
    cout << "Asunnon kulutus, kun hinta=1 on " << kulutus * 2 << endl;

    Katutaso katutaso;
    //katutaso.maaritaAsunnot();
    double katutasoKulutus = katutaso.laskeKulutus(1);
    cout << "Katutason kokonaiskulutus: " << katutasoKulutus << endl;

    Kerros kerros;
    //kerros.maaritaAsunnot();
    double kerrosKulutus = kerros.laskeKulutus(1);
    cout << "Kerroksen kokonaiskulutus: " << kerrosKulutus << endl;

    double kerrosKatuKulutus= katutaso.laskeKulutus(1) + kerros.laskeKulutus(1);
    cout << "Katutason ja perityn kerroksen kulutus, kun hinta =1 on " << kerrosKatuKulutus << endl; */

    Kerrostalo talo;

    talo.maaritaAsunnot();

    double energiankulutus = 1.0;
    double kokonaiskulutus = talo.laskeKulutus(energiankulutus);

    cout << "Kerrostalon kulutus, = " << kokonaiskulutus << endl;

    return 0;
}
