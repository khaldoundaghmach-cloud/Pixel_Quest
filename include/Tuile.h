#ifndef TUILE_H_INCLUDED
#define TUILE_H_INCLUDED
#include "moteur.h"

using namespace std;

class Tuile{
  string _nom;
  int _x;
  int _y;
  string _propriete;

  public:

  Tuile(); //constructeur vide
  Tuile(string nom, int x, int y, string propriete); //constructeur de tuile

  void afficher(); //affiche le contenu d'une tuile
  string GetNom(); //Retourne le nom de la tuile
  int GetX(); //Retourne l'emplacement x de la tuile
  int GetY(); //Retourne l'emplacement y de la tuile
  string GetPropriete(); //Retourne la propriete de la tuile
};


#endif // TUILE_H_INCLUDED
