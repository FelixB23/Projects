#ifndef TETROMINOS_H
#define TETROMINOS_H

#include <QPainter>

#include "case.h" //pour avoir acces aux constantes

class Tetrominos
{
protected:
    int m_x; //coordonnee x dans le puits
    int m_y; //coordonnee y dans le puits
    int m_type;
    int m_angleRotation; //1 pour 0°, 2 pour 90°, 3 pour 180° et 4 pour 270°
    bool m_estBloque;
    bool **m_matrice; //matrice ou chaque case vaut true si pleine, false sinon
    int m_ligne; //nombre de lignes de la matrice
    int m_colonne; //nombre de colonnes de la matrice

public:
    //Constructeur par defaut, de recopie et destructeur
    Tetrominos();
    Tetrominos(Tetrominos const &t);
    virtual ~Tetrominos();
    //accesseurs et mutateurs
    int getType();
    int getAngleRotation();
    int getx();
    int gety();
    int getLigne();
    int getCol();
    bool getEstBloque();
    bool getMat(int i, int j);
    void setx(int x);
    void sety(int y);
    void setEstBloque(bool b);
    //Autres methodes
    void translater(int x, int y); //translate le tetromino de x cases vers la droite et y vers le bas
    virtual void pivoter(); //methode virtuelle
    virtual void afficher(QPainter *p)=0; //methode abstraite
};

#endif // TETROMINOS_H
