#include "Niveau.h"
#include <fstream>
#include <sstream>

using namespace std;

Niveau::Niveau(Image img, string nomFichier, Dictionnaire dico){
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
    string sx;
    int y;
    string sy;

    for (int i=0; i<nombreObjets; i++){
        string ligne;
        if (getline(fichier,ligne)){
            istringstream ss(ligne);
            ss >> nom >> sx >> sy;
            x = stoi(sx);
            y = stoi(sy);
            _Objets.push_back(Objet(img,nom,dico,x*16,y*16));
        } else {
            cerr << "Erreur : Ligne manquante ou mal formatée à l'objet " << i + 1 << " !" << endl;
            break;
        }
    }
    fichier.close();
}

void Niveau::dessiner(){
    for (int i=0; i<_Objets.size();i++){
        if (!(_Objets[i].GetProp("cache")))
            _Objets[i].dessiner();
    }
}

bool Niveau::caseEstLibre(int x,int y){
    for (int i=0; i<_Objets.size();i++){
        if (_Objets[i].GetSolide()){
            if (_Objets[i].GetX()==x && _Objets[i].GetY()==y)
                return false;
        }
    }
    return true;
}

bool Niveau::testerBonusEtPrendre(int x,int y){
    for (int i=0; i<_Objets.size();i++){
        if (_Objets[i].GetBonus()){
            if (_Objets[i].GetX()==x && _Objets[i].GetY()==y){
                _nbBonus--;
                _Objets[i].Cacher();
                return true;
            }

        }
    }
    return false;
}

void Niveau::afficher(){
    for (int i=0; i<_Objets.size();i++){
        _Objets[i].afficher();
    }
}

bool Niveau::gagne(){
    return _nbBonus == 0;
}



