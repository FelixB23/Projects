#ifndef TETROMINOS4_H
#define TETROMINOS4_H

#include "tetrominos.h"

class Tetrominos4 : public Tetrominos
{
public:
    //redefinition des constructeurs et destructeur
    Tetrominos4();
    Tetrominos4(Tetrominos4 const &t);
    ~Tetrominos4();
    //redefinition de la methode afficher et pivoter
    void afficher(QPainter *p);
    void pivoter(); //Polymorphisme pour le carre car sa forme ne change pas
};

#endif // TETROMINOS4_H
