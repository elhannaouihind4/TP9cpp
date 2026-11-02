
#include <iostream>
#include <string>

using namespace std;

// Classe de base
class Vehicule {
protected:
    string marque;
    string modele;

public:
    Vehicule(string ma, string mo)
        : marque(ma), modele(mo) {
    }
};

// Classe Thermique
class Thermique : virtual public Vehicule {
protected:
    double consommation;

public:
    Thermique(double c)
        : Vehicule("", ""), consommation(c) {
    }
};

// Classe Electrique
class Electrique : virtual public Vehicule {
protected:
    double autonomie;

public:
    Electrique(double a)
        : Vehicule("", ""), autonomie(a) {
    }
};

// Classe Hybride
class Hybride : public Thermique, public Electrique {
public:
    Hybride(string ma, string mo, double c, double a)
        : Vehicule(ma, mo),
          Thermique(c),
          Electrique(a) {
    }

    void afficherCaracteristiques() {
        cout << "Marque : " << marque << endl;
        cout << "Modele : " << modele << endl;
        cout << "Consommation carburant : "
             << consommation << " L/100 km" << endl;
        cout << "Autonomie batterie : "
             << autonomie << " km" << endl;
    }
};

int main() {
    Hybride voiture("Toyota", "Prius", 4.5, 60);

    voiture.afficherCaracteristiques();

    return 0;
}




