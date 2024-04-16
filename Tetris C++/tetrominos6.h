#ifndef TETROMINOS6_H
#define TETROMINOS6_H

#include "tetrominos.h"

class Tetrominos6 : public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos6();
    Tetrominos6(Tetrominos6 const &t);
    ~Tetrominos6();
    //redefinition de la methode afficher
    void afficher(QPainter *p);
};

#endif // TETROMINOS6_H
