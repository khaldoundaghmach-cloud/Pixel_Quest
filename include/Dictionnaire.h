#ifndef DICTIONNAIRE_H_INCLUDED
#define DICTIONNAIRE_H_INCLUDED
#include <vector>
#include "Moteur.h"
#include "Tuile.h"
#include <fstream>

using namespace std;

class Dictionnaire{
    vector<Tuile> _tuiles;
    string _nomFichier;

public:
    Dictionnaire(string nomFichier); //constructeur de la classe Dictionnaire

    void afficher(); //affiche tout les éléments du vecteur _tuiles
    bool recherche(string nomRecherche, Tuile& resultat); //recherche dichotomique dans le vecteur _tuiles. Renvoie true si présent, false si non-présent. La tuile passée en parametre sera modifiée.
};

#endif // DICTIONNAIRE_H_INCLUDED
