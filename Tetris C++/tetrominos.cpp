#include "tetrominos.h"

//Constructeur par défaut
Tetrominos::Tetrominos()
{
    m_x = 5;
    m_y = 0;
    m_type = 1;
    m_angleRotation=1;
    m_estBloque=false;
    m_ligne = 3;
    m_colonne = 3;
}

//Constructeur de recopie
Tetrominos::Tetrominos(Tetrominos const &t)
{
    m_x = t.m_x;
    m_y = t.m_y;
    m_type = t.m_type;
    m_angleRotation = t.m_angleRotation;
    m_estBloque = t.m_estBloque;
    m_ligne = t.m_ligne;
    m_colonne = t.m_colonne;
    m_colonne = 3;
    m_matrice = new bool *[m_ligne];
    for (int i= 0;i<m_ligne;i++){
        m_matrice[i]=new bool[m_colonne];
        for (int j=0;i<m_colonne;j++)
                m_matrice[i][j] = t.m_matrice[i][j];
    }
}

//Destructeur
Tetrominos::~Tetrominos()
{
    for (int i=0;i<m_ligne;i++)
        delete[] m_matrice[i];
    delete[] m_matrice;
}

//accesseurs
int Tetrominos::getLigne()
{
    return m_ligne;
}

int Tetrominos::getCol()
{
    return m_colonne;
}

int Tetrominos::getx()
{
    return m_x;
}

int Tetrominos::gety()
{
    return m_y;
}

int Tetrominos::getType()
{
    return m_type;
}

bool Tetrominos::getEstBloque()
{
    return m_estBloque;
}

bool Tetrominos::getMat(int i, int j)
{
    return m_matrice[i][j];
}

//mutateurs
void Tetrominos::setEstBloque(bool b)
{
    this->m_estBloque = b;
}

void Tetrominos::setx(int x)
{
    this->m_x = x;
}

void Tetrominos::sety(int y)
{
    this->m_y = y;
}

void Tetrominos::translater(int x, int y) //translate le tetromino de x pixels vers la droite et y vers le bas
{
    m_x+=x;
    m_y+=y;
}

void Tetrominos::pivoter()
{
    m_angleRotation += 1;
    if (m_angleRotation==5)
        m_angleRotation = 1;

    //Copie de la matrice
    bool ** matrice = new bool * [m_ligne];
    for (int i=0;i<m_ligne;i++)
    {
        matrice[i]=new bool[m_colonne];
        for (int j=0;j<m_colonne;j++)
            matrice[i][j] = m_matrice[i][j];
    }

    //nouvelle matrice/
    for (int i=0;i<m_ligne;i++)
    {
        for (int j=0;j<m_colonne;j++)
            m_matrice[i][j] = matrice[m_colonne-j-1][i]; //chaque case est pivotee
    }

    //desallocation de la matrice temporaire
    for (int i=0;i<m_ligne;i++)
        delete[] matrice[i];
    delete[] matrice;
}
