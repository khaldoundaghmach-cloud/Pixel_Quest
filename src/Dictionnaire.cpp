#include <vector>
#include <fstream>
#include <sstream>

#include "personnage.h"
#include "Moteur.h"
#include "Image.h"
#include "Tuile.h"
#include "Dictionnaire.h"

using namespace std;


Dictionnaire::Dictionnaire(string nomFichier){
    ifstream fichier(nomFichier); //Ouverture du fichier
    if (!fichier.is_open()) {
            cerr << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
            return;
    }
    string nb;
    getline(fichier,nb);
    int nombreObjets = stoi(nb);

    string nom;
    int x;
    string strx;
    int y;
    string stry;
    string etat;


    for (int i=0; i<nombreObjets; i++){
        string ligne;
        if (getline(fichier,ligne)){
            istringstream ss(ligne);
            ss >> nom >> strx >> stry >> etat;
            x = stoi(strx);
            y = stoi(stry);
            _tuiles.push_back(Tuile(nom,x,y,etat));
        } else {
            cerr << "Erreur : Ligne manquante ou mal formatée à l'objet " << i + 1 << " !" << endl;
            break;
        }
    }
    fichier.close();
}

void Dictionnaire::afficher(){
    for (int i=0; i<_tuiles.size(); i++){
        _tuiles[i].afficher();
    }
}

bool Dictionnaire::recherche(string nomRecherche, Tuile& resultat){ //recherche dichotomique
    int debut = 0;
    int fin = _tuiles.size() - 1;

    while (debut <= fin) {
        int milieu = debut + (fin - debut) / 2; // Calcul du milieu pour éviter les dépassements d'entiers

        // Comparer le nom de l'objet Tuile avec nomRecherche
        if (_tuiles[milieu].GetNom() == nomRecherche) {
            resultat = _tuiles[milieu];
            return true; // L'objet a été trouvé
        } else if (_tuiles[milieu].GetNom() < nomRecherche) {
            debut = milieu + 1; // La recherche continue dans la moitié droite
        } else {
            fin = milieu - 1; // La recherche continue dans la moitié gauche
        }
    }

    return false; // L'objet n'a pas été trouvé
}
