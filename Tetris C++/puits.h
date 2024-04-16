#ifndef PUITS_H
#define PUITS_H

#include "tetrominos.h"
#include "case.h"

class Puits
{
private:
    int m_hauteur;
    int m_largeur;
    Case ***m_grille; //matrice de pointeurs de Case

public:
    //Constructeur par defaut, de recopie et destructeur
    Puits();
    Puits(const Puits &p);
    ~Puits();
    //accesseurs et mutateurs
    Case* getCase(int i, int j);
    int getHauteur();
    int getLargeur();
    //autres methodes
    void afficher(QPainter *p);
    int supprimerLignes(); //supprime les lignes pleines et renvoie le nombre de lignes supprimees
};

#endif // PUITS_H
