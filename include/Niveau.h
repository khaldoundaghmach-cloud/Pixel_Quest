#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Moteur.h"
#include <vector>
#include "Tuile.h"
#include "Objet.h"
#include <fstream>
#include "Image.h"

using namespace std;

class Niveau{
    std::vector<Objet> _Objets;
    int _nbBonus = 4;

public:
    Niveau(Image img, string nomFichier, Dictionnaire dico);

    void dessiner(); //Dessine toutes les tuiles du niveau (sauf si _propiete
    bool caseEstLibre(int x, int y); //Vérifie si un objet solide dans _Objets a les mêmes coordonées en paramètres. Si oui, renvoie faux. Sinon, renvoie vrai
    bool testerBonusEtPrendre(int x,int y); //Vérifie si un objet "bonus" dans _Objets a les mêmes coordonées en paramètres. Si oui,décrémente _nbBonus, cache le bonus trouvé et renvoie vrai.
    void afficher(); //affiche tous les objets dans le vecteur _Objets
    bool gagne(); //renvoie vrai si _nbBonus = 0 (donc tout les bonus sont pris)
};


#endif // NIVEAU_H_INCLUDED
