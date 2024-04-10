#include "tetrominos4.h"

//Redefinition du constructeur par defaut
Tetrominos4::Tetrominos4():Tetrominos()
{
    m_type = 4;
    m_colonne = 4; //nombre de colonnes pas le meme que par defaut
    //construction du tetromino
    m_matrice = new bool *[m_ligne];
    for (int i= 0;i<m_ligne;i++){
        m_matrice[i]=new bool[m_colonne];
        for (int j=0;j<m_colonne;j++)
        {
            if (j>=1 && j<=2 && i<=1)
                m_matrice[i][j] = true;
            else
                m_matrice[i][j] = false;
        }
    }
}

//Redefinition du constructeur de recopie
Tetrominos4::Tetrominos4(const Tetrominos4 &t):Tetrominos(t){}

//Redefinition du destructeur
Tetrominos4::~Tetrominos4(){}

//Redefinition de la methode afficher
void Tetrominos4::afficher(QPainter *p)
{
    p->setPen(QPen(Qt::black, 1));

    for (int i=0;i<m_ligne;i++)
    {
        for (int j=0;j<m_colonne;j++)
        {
            /*les lignes et les colonnes de la matrice sont inversees pour l'affichage
            car les coordonnees x sont les colonnes et y les lignes*/
            if (m_matrice[i][j])
            {
                p->drawRect(CPX + (m_x+j)*T, CPY + (m_y+i)*T, T, T);
                p->fillRect(CPX + (m_x+j)*T + 1, CPY + (m_y+i)*T + 1, T-1, T-1, QBrush(Qt::blue));
            }
        }
    }
}

//Polymorphisme de pivoter pour le carre car sa forme ne change pas
void Tetrominos4::pivoter()
{
    m_angleRotation += 1;
    if (m_angleRotation==5)
        m_angleRotation = 1;
}
