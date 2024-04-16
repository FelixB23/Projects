#ifndef TETROMINOS3_H
#define TETROMINOS3_H


#include "tetrominos.h"

class Tetrominos3: public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos3();
    Tetrominos3(Tetrominos3 const &t);
    ~Tetrominos3();
    //redefinition de la methode afficher
    void afficher(QPainter *p);
};

#endif // TETROMINOS3_H
