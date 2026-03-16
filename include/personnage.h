#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED
#include "Image.h"
#include "Niveau.h"


class Personnage{
    Image _Image; //Image des sprites
    int _x; //coordonnée x du personnage
    int _y; //coordonnée y du personnage
    int _skin_x; //coordonnée x du sprite
    int _skin_y; //coordonnée y du sprite
    int _direction; //direction du personnage
    Niveau& _niveau; //Niveau dans lequel le personnage existe
    bool _player; //Booléen pour savoir si le personnage est un joueur ou un ennemi.

public:
    //Personnage(); //ancien constructeur vide
    Personnage(Image img, int x, int y, int skin_x, int skin_y, Niveau& niveau, bool player); //constructeur sans la définition de la direction (2 par défaut)
    Personnage(Image img, int x, int y, int skin_x, int skin_y, int direction, Niveau& niveau, bool player); //constructeur avec la définition de la direction

    void dessiner(); //dessine le personnage selon le skin_x et skin_y
    void allerDroite(); //ajoute TAILLE_CASE à X si il dépasse pas les limites et n'a pas d'objet dans le chemin
    void allerGauche(); //enleve TAILLE_CASE à X si il dépasse pas les limites et n'a pas d'objet dans le chemin
    void allerBas();    //ajoute TAILLE_CASE à Y si il dépasse pas les limites et n'a pas d'objet dans le chemin
    void allerHaut();   //enleve TAILLE_CASE à Y si il dépasse pas les limites et n'a pas d'objet dans le chemin
    void mettreAJourDirection(); //met a jour le sprite en fonction de la direction du personnage
    void avancer(); //Methode pour faire avancer des ennemis, et faire demi tout si l'ennemi ne peut pas avancer.
    int getX(); //retourne la coordonnée x du personnage
    int getY(); //retourne la coordonnée y du personnage
    bool touche(Personnage perso); //vérifie si le personnage passé en parametre a les mêmes coordonnees x et y. Retourne true si c'est le cas, sinon false.
    void prendrePiece(); //Si le personnage est un joueur, apelle la fonction testerBonusEtPrendre(); avec les coordonnées _x et _y.
};






#endif // PERSONNAGE_H_INCLUDED
