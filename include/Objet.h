#ifndef OBJET_H_INCLUDED
#define OBJET_H_INCLUDED
#include "Dictionnaire.h"
#include "Image.h"

class Objet{
    Image _Image;
    int _x;
    int _y;
    string _propriete;


    public:
        Objet(Image img, string nom, Dictionnaire dico, int x, int y); //Constructeur d'Objet

        void dessiner(); //Affiche l'image avec les coordonnées _x et _y

        int GetX(); //Retourne la coordonnée x
        int GetY(); //Retourne la coordonnée y
        bool GetSolide(); //Retourne vrai si _propriete est solide
        bool GetBonus(); //Retourne vrai si _propriete est un bonus
        void Cacher(); //Transforme l'attribut _propriete en cache (afin de le cacher)
        bool GetProp(string s); //Retourne vrai si _propriete est égal au string passé en paramètre
        void afficher(); //Affiche les attributs de l'Objet (_x,_y,_propriete)
};

#endif // OBJET_H_INCLUDED
