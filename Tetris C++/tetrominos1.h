#ifndef TETROMINOS1_H
#define TETROMINOS1_H

#include "tetrominos.h"

class Tetrominos1: public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos1();
    Tetrominos1(Tetrominos1 const &t);
    ~Tetrominos1();
    //redefinition de la methode afficher
    void afficher(QPainter *p);
};

#endif // TETROMINOS1_H
