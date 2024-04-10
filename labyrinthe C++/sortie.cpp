#include "sortie.hpp"

//Sortie
Sortie::Sortie(int i=0, int j=0):objetGraphiqueFixe(i,j)
{
    m_type = 3; //type sortie = 3
}

void Sortie::afficher()
{
    cout << " S ";
}
