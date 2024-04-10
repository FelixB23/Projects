#include "mur.hpp"

//Mur
Mur::Mur(int i=0, int j=0):objetGraphiqueFixe(i,j)
{
    m_type = 2; //type mur = 2
}

void Mur::afficher()
{
    cout << " * ";
}
