
#include <iostream>
using namespace std;

// Classe Technicien
class Technicien {
protected:
    double salaire;

public:
    Technicien(double s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire du technicien : "
             << salaire << " DH" << endl;
    }
};

// Classe Comptable
class Comptable {
protected:
    double salaire;

public:
    Comptable(double s) {
        salaire = s;
    }

    void afficherSalaire() {
        cout << "Salaire du comptable : "
             << salaire << " DH" << endl;
    }
};

// Heritage
class EmployePolyvalent : public Technicien, public Comptable {
public:
    EmployePolyvalent(double salaireTech, double salaireComp)
        : Technicien(salaireTech), Comptable(salaireComp) {
    }

    void afficherTousSalaires() {
        Technicien::afficherSalaire();
        Comptable::afficherSalaire();
    }
};

int main() {
    EmployePolyvalent e(6000, 7500);

    e.afficherTousSalaires();

    return 0;
}
