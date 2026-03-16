#include <vector>
#include "personnage.h"
#include "Moteur.h"
#include "Niveau.h"

using namespace std;


/*Personnage::Personnage(){
    //_Image = Image(moteur, "assets/personnage_simple.png");
    _x = 0;
    _y = 0;
    _skin_x = 4*16;
    _skin_y = 0*16;
    _Image.selectionnerRectangle(_skin_x,_skin_y,16,16);
    _direction = 0;
}
*/
Personnage::Personnage(Image img, int x, int y, int skin_x, int skin_y, Niveau& niveau, bool player)
    : _Image(img), _x(x), _y(y), _skin_x(skin_x * 16), _skin_y(skin_y * 16), _niveau(niveau), _player(player) {
    _Image.selectionnerRectangle(_skin_x, _skin_y, 16, 16);
    _direction = 2;
}

Personnage::Personnage(Image img, int x, int y, int skin_x, int skin_y, int direction, Niveau& niveau, bool player)
    : _Image(img), _x(x), _y(y), _skin_x(skin_x * 16), _skin_y(skin_y * 16), _direction(direction), _niveau(niveau), _player(player) {
    _Image.selectionnerRectangle(_skin_x, _skin_y, 16, 16);
}


void Personnage::dessiner(){
    _Image.dessiner(_x,_y);
}

void Personnage::allerDroite(){
    _direction = 3;
    if (_x<LARGEUR_FENETRE-TAILLE_CASE && _niveau.caseEstLibre(_x+TAILLE_CASE,_y)){
        _x += TAILLE_CASE;
    }
    prendrePiece();
}

void Personnage::allerGauche() {
    _direction = 1;
    if (_x>0 && _niveau.caseEstLibre(_x-TAILLE_CASE,_y)){
        _x -= 16;
    }
    prendrePiece();
}

void Personnage::allerBas(){
    _direction = 0;
    if (_y<HAUTEUR_FENETRE-TAILLE_CASE && _niveau.caseEstLibre(_x,_y+TAILLE_CASE)){
        _y += 16;
    }
    prendrePiece();
}

void Personnage::allerHaut(){
    _direction = 2;
    if (_y>0 && _niveau.caseEstLibre(_x,_y-TAILLE_CASE)){
        _y -= 16;
    }
    prendrePiece();
}

void Personnage::mettreAJourDirection(){
    if (_direction == 0){
        _Image.selectionnerRectangle(_skin_x,_skin_y,TAILLE_CASE,TAILLE_CASE);}
    else if (_direction == 1){
        _Image.selectionnerRectangle(_skin_x,_skin_y+16,TAILLE_CASE,TAILLE_CASE);}
    else if(_direction == 2){
        _Image.selectionnerRectangle(_skin_x,_skin_y+48,TAILLE_CASE,TAILLE_CASE);}
    else{
         _Image.selectionnerRectangle(_skin_x,_skin_y+32,TAILLE_CASE,TAILLE_CASE);}
}

void Personnage::avancer(){
    if (_direction == 0){
        if (_y<HAUTEUR_FENETRE-TAILLE_CASE && _niveau.caseEstLibre(_x,_y+TAILLE_CASE)){
            allerBas();}
        else{
        allerHaut();}}
    else if (_direction == 1){
        if (_x>0 && _niveau.caseEstLibre(_x-TAILLE_CASE,_y)){
            allerGauche();}
        else{
        allerDroite();}}
    else if(_direction == 2){
        if (_y>0 && _niveau.caseEstLibre(_x,_y-TAILLE_CASE)){
            allerHaut();}
        else{
        allerBas();}}
    else{
        if (_x<LARGEUR_FENETRE-TAILLE_CASE && _niveau.caseEstLibre(_x+TAILLE_CASE,_y)){
            allerDroite();}
        else{
            allerGauche();}}
}

int Personnage::getX(){
    return _x;
}

int Personnage::getY(){
    return _y;
}


bool Personnage::touche(Personnage perso){
    return (_x == perso.getX() && _y == perso.getY());
}

void Personnage::prendrePiece(){
    if (_player){
        _niveau.testerBonusEtPrendre(_x,_y);
    }
}
