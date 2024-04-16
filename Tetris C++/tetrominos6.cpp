#include "tetrominos6.h"

//Redefinition du constructeur par defaut
Tetrominos6::Tetrominos6():Tetrominos()
{
    m_type = 6;
    //construction du tetromino
    m_matrice = new bool *[m_ligne];
    for (int i= 0;i<m_ligne;i++){
        m_matrice[i]=new bool[m_colonne];
        for (int j=0;j<m_colonne;j++)
        {
            if ((i==0 && j==1) || i==1)
                m_matrice[i][j] = true;
            else
                m_matrice[i][j] = false;
        }
    }
}

//Redefinition du constructeur de recopie
Tetrominos6::Tetrominos6(const Tetrominos6 &t):Tetrominos(t){}

//Redefinition du destructeur
Tetrominos6::~Tetrominos6(){}

//Redefinition de la methode afficher
void Tetrominos6::afficher(QPainter *p)
{
    p->setPen(QPen(Qt::black, 1));

    for (int i=0;i<m_ligne;i++)
    {
        for (int j=0;j<m_colonne;j++)
        {
            /*les coordonnees x sont les colonnes (correspond a j) et y les lignes (correspond a i)*/
            if (m_matrice[i][j])
            {
                p->drawRect(CPX + (m_x+j)*T, CPY + (m_y+i)*T, T, T);
                p->fillRect(CPX + (m_x+j)*T+1, CPY + (m_y+i)*T+1, T-1, T-1, QBrush(QColor(255, 175, 0)));
            }
        }
    }
}
