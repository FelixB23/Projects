#ifndef TETROMINOS2_H
#define TETROMINOS2_H

#include "tetrominos.h"

class Tetrominos2: public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos2();
    Tetrominos2(Tetrominos2 const &t);
    ~Tetrominos2();
    //redefinition de la methode afficher
    void afficher(QPainter *p);
};

#endif // TETROMINOS2_H
