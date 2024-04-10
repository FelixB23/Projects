#ifndef PARTIE_H
#define PARTIE_H

//inclusion de tous les fichiers
#include "puits.h"
#include "tetrominos1.h"
#include "tetrominos2.h"
#include "tetrominos3.h"
#include "tetrominos4.h"
#include "tetrominos5.h"
#include "tetrominos6.h"
#include "tetrominos7.h"

class Partie
{
private:
    int m_score;
    int m_niveau;
    int m_tempsDescente; //temps en centieme de seconde entre chaque descente du tetromino
    int m_nbLignesCompletees;
    bool m_finie;
    bool m_reserve;
    Puits *m_p;
    Tetrominos *m_t;
    Tetrominos *m_t2; //tetromino suivant
    Tetrominos *m_t3; //tetromino mis en reserve

public:
    //Constructeur par defaut
    Partie();
    //Constructeur de recopie
    Partie(const Partie& par);
    //Destructeur
    ~Partie();
    //accesseurs
    int getScore();
    int getNiveau();
    int getTempsDescente();
    int getNbLignesCompletees();
    bool getFinie();
    //Autres methodes
    bool possibTranslation(bool direction); //direction=true pour droite, false pour gauche
    void translater(bool direction); //direction=true pour droite, false pour gauche
    bool possibRotation();
    void pivoter();
    void afficher(QPainter *p);
    bool descentePossible();
    void accelerer(); //pre-condition : deplacementPossible()
    void poser(); //pre-condition : !deplacementPossible()
    void niveauSuivant();
    void calculerScore(); //pre-condition : !deplacementPossible()
    Tetrominos* pieceAleatoire();
    void pieceSuivante(); //pre-condition : !deplacementPossible()
    void tomber();
    bool possibReservation();
    void reserver();
    bool estFinie();
};

#endif // PARTIE_H
