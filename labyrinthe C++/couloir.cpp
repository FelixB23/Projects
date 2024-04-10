#include "couloir.hpp"

//Couloir
Couloir::Couloir(int i=0, int j=0):objetGraphiqueFixe(i,j)
{
    m_type = 1; //type couloir = 1
}

void Couloir::afficher()
{
    cout << "   ";
}
