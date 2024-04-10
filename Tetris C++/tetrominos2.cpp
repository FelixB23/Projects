#include "tetrominos2.h"

//Redefinition du constructeur par defaut
Tetrominos2::Tetrominos2():Tetrominos()
{
    m_type = 2;
    //construction du tetromino
    m_matrice = new bool *[m_ligne];
    for (int i=0;i<m_ligne;i++)
    {
        m_matrice[i]=new bool[m_colonne];
        for (int j=0;j<m_colonne;j++){
            if (i==1 || (i==0 && j==0))
                m_matrice[i][j] = true;
            else
                m_matrice[i][j] = false;
        }
    }
}

//Redefinition du constructeur de recopie
Tetrominos2::Tetrominos2(const Tetrominos2 &t):Tetrominos(t){}

//Redefinition du destructeur
Tetrominos2::~Tetrominos2(){}

//Redefinition de la methode afficher
void Tetrominos2::afficher(QPainter *p)
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
                p->fillRect(CPX + (m_x+j)*T + 1, CPY + (m_y+i)*T + 1, T-1, T-1, QBrush(Qt::yellow));
            }
        }
    }
}
