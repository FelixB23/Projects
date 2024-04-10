#include "plateau.hpp"

//Plateau
Plateau::Plateau(int nbl=L, int nbc=C){
    if (nbl>0 && nbl<=L && nbc>0 && nbc<=C)
    {
        m_nbl=nbl;
        m_nbc=nbc;
        m_plateau = new objetGraphiqueFixe**[m_nbl];
        for (int i=0;i<m_nbl;i++)
        {
            m_plateau[i] = new objetGraphiqueFixe*[m_nbc];
            for (int j=0;j<m_nbl;j++)
                m_plateau[i][j] = new Couloir(i,j); //couloirs partout par defaut
        }
    }
    else
        throw SaisieIncorrecte("Erreur : le nombre de lignes ou de colonnes est incorrecte");
}

Plateau::Plateau(const Plateau& p)
{
    m_nbl = p.m_nbl;
    m_nbc = p.m_nbc;
    m_plateau = new objetGraphiqueFixe**[m_nbl];
    for (int i=0;i<m_nbl;i++)
    {
        m_plateau[i] = new objetGraphiqueFixe*[m_nbc];
        for (int j=0;j<m_nbc;j++)
            m_plateau[i][j] = p.m_plateau[i][j];
    }
}

Plateau::~Plateau()
{
    for (int i;i<m_nbl;i++)
    {
        for (int j=0;j<m_nbc;j++)
            delete[] m_plateau[i][j];
        delete[] m_plateau[i];
    }
    delete[] m_plateau;
}

void Plateau::setCase (int i, int j, objetGraphiqueFixe* o) //On vérifie que les coordonnees i et j sont dans le plateau dans le constructeur de objet graphique
{
    m_plateau[i][j] = o;
}

objetGraphiqueFixe* Plateau::getCase(int i, int j)
{
    if (i>=0 && j>=0 && i<L && j<C) //Les coordonnees i et j doivent etre dans le plateau
        return m_plateau[i][j];
    else
        throw SaisieIncorrecte("Erreur : Les coordonnees sortent du plateau");
}

void Plateau::afficher()
{
    for (int i=0;i<m_nbl;i++)
    {
        for (int j=0;j<m_nbc;j++)
            m_plateau[i][j]->afficher(); //Appel de la methode afficher de la classe Mur, Couloir ou Sortie selon le type de l'objet graphique fixe
        cout << endl;
    }
}

void Plateau::afficher(objetGraphiqueMobile& p)
{
    for (int i=0;i<m_nbl;i++)
    {
        for (int j=0;j<m_nbc;j++)
        {
            if (i==p.geti() && j==p.getj())
                p.afficher(); //Appel de la methode afficher de la classe Personnage
            else
                m_plateau[i][j]->afficher();
        }
        cout << endl;
    }
}
