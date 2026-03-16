#include <vector>

#include "Moteur.h"
#include "Image.h"
#include "personnage.h"
#include "Dictionnaire.h"
#include "Niveau.h"

using namespace std;

int main(int, char**) // Version special du main, ne pas modifier
{
  // Initialisation du jeu
  Moteur moteur("Mon super jeu vidéo");
  /*bool etatcoffre = 0;
  int coffrex = 64;
  int coffrey = 16;*/

  // TODO: charger images, creer personnages, etc.
  Image gameover;
  try {
     gameover = Image(moteur, "assets/gameover.png");
  }
  catch (const invalid_argument& e) {
   cerr << "Erreur : "<< e.what() << endl;
  }

Image bravo;
  try {
     bravo = Image(moteur, "assets/bravo.png");
  }
  catch (const invalid_argument& e) {
   cerr << "Erreur : "<< e.what() << endl;
  }

  Image fond; //charger le fond
  try {
     fond = Image(moteur, "assets/fond.png");
  }
  catch (const invalid_argument& e) {
   cerr << "Erreur : "<< e.what() << endl;
  }
  /*
  Image coffreo; //charger le fond
  try {
    coffreo = Image(moteur, "assets/coffre_ouvert.png");
  }
  catch (const invalid_argument& e) {
    cerr << "Erreur : "<< e.what() << endl;
  }

  Image coffref; //charger le fond
  try {
    coffref = Image(moteur, "assets/coffre_ferme.png");
  }
  catch (const invalid_argument& e) {
    cerr << "Erreur : "<< e.what() << endl;
  }
  */
  Image player;
  try {
     player = Image(moteur, "assets/personnages.png");
  }
  catch (const invalid_argument& e) {
   cerr << "Erreur : "<< e.what() << endl;
  }


  Image sprite;
  try {
     sprite = Image(moteur, "assets/objets.png");
  }
  catch (const invalid_argument& e) {
   cerr << "Erreur : "<< e.what() << endl;
  }

  Dictionnaire dictionnaire("assets/dictionnaire.txt");

  Niveau niveau1(sprite,"assets/niveau1.txt",dictionnaire);

  Personnage player1(player,5*TAILLE_CASE,6*TAILLE_CASE,4,0,niveau1,1);
  Personnage ennemi1(player,TAILLE_CASE,5*TAILLE_CASE,10,0,niveau1,0);
  Personnage ennemi2(player,5*TAILLE_CASE,2*TAILLE_CASE,7,4,1,niveau1,0);



  bool quitter = false;

  // Boucle de jeu, appelee a chaque fois que l'ecran doit etre mis a jour
  // (en general, 60 fois par seconde)
  while (!quitter)
  {
    // I. Gestion des evenements
    Evenement evenement = moteur.evenementRecu();
    while (evenement != AUCUN)
    {
      switch (evenement)
      {
        // QUITTER = croix de la fenetre ou Echap
        case QUITTER_APPUYE:
          quitter = true;
          break;
        /*case ESPACE_APPUYE:
            if (etatcoffre){
                etatcoffre = 0;
            }
            else{
                etatcoffre = 1;
            }
            break;*/
        case DROITE_APPUYE :
            player1.allerDroite() ;
            break;
        case GAUCHE_APPUYE :
            player1.allerGauche();
            break;
        case BAS_APPUYE :
            player1.allerBas();
            break;
        case HAUT_APPUYE :
            player1.allerHaut();
            break;

        // TODO: gerer les autres evenements
        default:
          break;
      }

      evenement = moteur.evenementRecu();
    }

    // II. Mise à jour de l'état du jeu

    // TODO: faire bouger vos personnages, etc.

    // III. Generation de l'image à afficher

    moteur.initialiserRendu(); // efface ce qui avait ete affiche precedemment et reinitalise en ecran noir

    player1.mettreAJourDirection();
    fond.dessiner(0,0);
    if (moteur.animationsAmettreAjour()){
        ennemi1.avancer();
        ennemi2.avancer();
    }
    quitter = (ennemi1.touche(player1) || ennemi2.touche(player1) || niveau1.gagne());
    niveau1.dessiner();
    player1.dessiner();
    ennemi1.dessiner();
    ennemi2.dessiner();
    /*if (etatcoffre){
        coffreo.dessiner(coffrex,coffrey);
    }
    else{
        coffref.dessiner(coffrex,coffrey);
    }*/
    // TODO: afficher vos personnages, objets, etc.

    /*
      Affiche l'image en se cadencant sur la frequence de
      rafraichissement de l'ecran (donc va en general mettre le
      programme en pause jusqu'a ce que l'ecran soit rafraichi). En
      general, 60 images fois par seconde, mais ca peut dependre du
      materiel
    */
    moteur.finaliserRendu();
    if (quitter){
        if (niveau1.gagne()){
            bravo.dessiner(2*TAILLE_CASE, 3*TAILLE_CASE);
        }
        else{
            gameover.dessiner(2*TAILLE_CASE, 3*TAILLE_CASE);
        }
        moteur.finaliserRendu();
        moteur.attendre(3);
    }
  }

  return 0;
}
