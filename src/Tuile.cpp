#include <vector>
#include "personnage.h"
#include "Moteur.h"
#include "Image.h"
#include "Tuile.h"

using namespace std;


Tuile::Tuile(){
    _nom = "default";
    _x = 0;
    _y = 0;
    _propriete = "defaut";
}

Tuile::Tuile(string nom, int x, int y, string propriete){
    _nom = nom;
    _x = x;
    _y = y;
    _propriete = propriete;
}

void Tuile::afficher(){
    cout << "nom=" << _nom << ", x=" <<_x << ", y=" << _y << ", propriete = " << _propriete << endl;
}

string Tuile::GetNom(){
    return _nom;
}

int Tuile::GetX(){
    return _x;
}

int Tuile::GetY(){
    return _y;
}

string Tuile::GetPropriete(){
    return _propriete;
}
