#ifndef CASE_H
#define CASE_H

#include <QPainter>
#include <iostream>
using namespace std;

const int T=20; //taille des cases
const int CPX = 3*T; //Coordonnees x du coin en haut a gauche du puits
const int CPY = 3*T; //Coordonnees y du coin en haut a gauche du puits

class Case
{
private:
    int m_x;
    int m_y;
    int m_type; //0 case vide, 1 a 7 tetrominos, 8 case invisible

public:
    //Constructeur
    Case(int x, int y);
    //accesseurs et mutateurs
    int getx();
    int gety();
    int getType();
    void setx(int x);
    void sety(int y);
    void setType(int t);
    //autres methodes
    void afficher(QPainter *p);
};

#endif // CASE_H
