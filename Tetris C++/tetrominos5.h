#ifndef TETROMINOS5_H
#define TETROMINOS5_H

#include "tetrominos.h"

class Tetrominos5 : public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos5();
    Tetrominos5(Tetrominos5 const &t);
    ~Tetrominos5();
    //redefinition de la methode afficher
    void afficher(QPainter *p);
};

#endif // TETROMINOS5_H
