#include <vector>
#include "personnage.h"
#include "Moteur.h"
#include "Objet.h"
#include "Image.h"

using namespace std;


Objet::Objet(Image img, string nom, Dictionnaire dico, int x, int y){
    Tuile temp;
    if (dico.recherche(nom,temp)){
        _x = x;
        _y = y;
        int coord_x = temp.GetX()*16;
        int coord_y = temp.GetY()*16;
        _Image = img;
        _Image.selectionnerRectangle(coord_x,coord_y,16,16);
        _propriete = temp.GetPropriete();
    }
    else{
        throw runtime_error("Objet non présent dans le dico.");
    }
}

void Objet::dessiner(){
     _Image.dessiner(_x,_y);
}

int Objet::GetX(){
    return _x;
}

int Objet::GetY(){
    return _y;
}

bool Objet::GetSolide(){
    return _propriete=="solide";
}

bool Objet::GetBonus(){
    return _propriete=="bonus";
}

void Objet::Cacher(){
    _propriete = "cache";
}

bool Objet::GetProp(string s){
    return _propriete==s;
}

void Objet::afficher(){
    cout << "x : " << _x << ", y : " << _y << ", propriete : " << _propriete << endl;
}
