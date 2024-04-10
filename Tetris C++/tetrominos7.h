#ifndef TETROMINOS7_H
#define TETROMINOS7_H

#include "tetrominos.h"

class Tetrominos7 : public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos7();
    Tetrominos7(Tetrominos7 const &t);
    ~Tetrominos7();
    //redefinition de la methode afficher
    void afficher(QPainter *p);
};

#endif // TETROMINOS7_H
