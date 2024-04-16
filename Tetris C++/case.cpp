#include "case.h"

//Constructeur
Case::Case(int x, int y)
{
    m_x = x;
    m_y = y;
    m_type = 0;
}

//accesseurs
int Case::getx()
{
    return m_x;
}

int Case::gety()
{
    return m_y;
}

int Case::getType()
{
    return m_type;
}

//mutateurs
void Case::setx(int x)
{
    this->m_x = x;
}

void Case::sety(int y)
{
    this->m_y = y;
}

void Case::setType(int t)
{
    this->m_type = t;
}

//autres methodes
void Case::afficher(QPainter *p)
{
    p->setPen(QPen(Qt::black, 1));
    switch (m_type) //coloration de la case differente selon le type
    {
        case 0:
            if (gety() % 2 == 0) //colonne paire
                p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QColor(100,100,255,50));
            else //colonne impaire
                p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QColor(0,0,50,50));
            break;
        case 1: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T,  QBrush(Qt::red));
                break;
        case 2: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QBrush(Qt::yellow));
                break;
        case 3: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QBrush(Qt::magenta));
                break;
        case 4: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QBrush(Qt::blue));
                break;
        case 5: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QBrush(Qt::green));
                break;
        case 6: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QBrush(QColor(255, 175, 0)));
                break;
        case 7: p->fillRect(CPX+T*m_y, CPY+T*m_x, T, T, QBrush(Qt::cyan));
                break;
    }
    if (m_type!=0 && m_type!=8) //case pleine -> bordure noire
        p->drawRect(CPX+T*m_y, CPY+T*m_x, T, T);
}
