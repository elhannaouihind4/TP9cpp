
#include <iostream>
#include <string>

using namespace std;

// Classe de base
class Utilisateur {
protected:
    int identifiant;
    string login;

public:
    Utilisateur(int id, string l)
        : identifiant(id), login(l) {
    }

    void afficherUtilisateur() {
        cout << "Identifiant : " << identifiant << endl;
        cout << "Login : " << login << endl;
    }
};

// Classe Administrateur
class Administrateur : virtual public Utilisateur {
protected:
    string droitsAcces;

public:
    Administrateur(int id, string l, string droits)
        : Utilisateur(id, l), droitsAcces(droits) {
    }

    void gererSysteme() {
        cout << login << " gere le systeme." << endl;
        cout << "Droits d'acces : " << droitsAcces << endl;
    }
};

// Classe Moderateur
class Moderateur : virtual public Utilisateur {
protected:
    int niveauModeration;

public:
    Moderateur(int id, string l, int niveau)
        : Utilisateur(id, l), niveauModeration(niveau) {
    }

    void modererContenu() {
        cout << login << " modere le contenu." << endl;
        cout << "Niveau de moderation : "
             << niveauModeration << endl;
    }
};

// Classe SuperUtilisateur
class SuperUtilisateur : public Administrateur, public Moderateur {
public:
    SuperUtilisateur(int id, string l, string droits, int niveau)
        : Utilisateur(id, l),
          Administrateur(id, l, droits),
          Moderateur(id, l, niveau) {
    }

    void afficherInformations() {
        afficherUtilisateur();
        gererSysteme();
        modererContenu();
    }
};

int main() {
    int choix;

    cout << " MENU " << endl;
    cout << "1. Creer un SuperUtilisateur" << endl;
    cout << "2. Quitter" << endl;
    cout << "Votre choix : ";
    cin >> choix;

    if (choix == 1) {
        int id;
        string login;
        string droits;
        int niveau;

        cout << "Entrez l'identifiant : ";
        cin >> id;

        cout << "Entrez le login : ";
        cin >> login;

        cout << "Entrez les droits d'acces : ";
        cin >> droits;

        cout << "Entrez le niveau de moderation : ";
        cin >> niveau;

        SuperUtilisateur utilisateur(
            id, login, droits, niveau
        );

        cout << "\n INFORMATIONS " << endl;
        utilisateur.afficherInformations();
    }
    else if (choix == 2) {
        cout << "Au revoir !" << endl;
    }
    else {
        cout << "Choix invalide !" << endl;
    }

    return 0;
}
