#include "puits.h"

//Constructeur par defaut
Puits::Puits()
{
   m_hauteur = 24; //22 + 2 lignes vides en bas du puits
   m_largeur = 14; //10 + 2 colonnes vides a droite et 2 autres a gauche
   m_grille = new Case**[m_hauteur];
   for (int i=0;i<m_hauteur;i++)
   {
       m_grille[i] = new Case*[m_largeur];
       for (int j=0;j<m_largeur;j++)
       {
           m_grille[i][j] = new Case(i,j);
           if (j==0 || j==1 || j==m_largeur-2 || j==m_largeur-1 || i==m_hauteur-2 || i==m_hauteur-1)
               m_grille[i][j]->setType(8); //type 8 pour les cases qui n'apparaitront pas
       }
   }
}

//Constructeur de recopie
Puits::Puits(const Puits& p)
{
    m_hauteur = p.m_hauteur;
    m_largeur = p.m_largeur;
    m_grille = new Case**[m_hauteur];
    for (int i=0;i<m_hauteur;i++)
    {
        m_grille[i] = new Case*[m_largeur];
        for (int j=0;j<m_largeur;j++)
        {
            m_grille[i][j] = new Case(i,j);
            m_grille[i][j] = p.m_grille[i][j];
        }
    }
}

//Destructeur
Puits::~Puits()
{
    for (int i=0;i<m_hauteur;i++)
    {
        for (int j=0;j<m_largeur;j++)
            delete[] m_grille[i][j];
        delete[] m_grille[i];
    }
    delete[] m_grille;
}

//accesseurs
Case* Puits::getCase(int i, int j)
{
    return m_grille[i][j];
}

int Puits::getHauteur()
{
    return m_hauteur;
}

int Puits::getLargeur()
{
    return m_largeur;
}

//autres methodes
void Puits::afficher(QPainter *p)
{
    p->setPen(QPen(Qt::black, 1));
    p->drawRect(CPX+2*T, CPY, m_largeur*T-4*T, m_hauteur*T-2*T);
    for (int i=0;i<m_hauteur;i++)
    {
        for (int j=0;j<m_largeur;j++)
            m_grille[i][j]->afficher(p);
    }
}

int Puits::supprimerLignes() //supprime les lignes pleines et renvoie le nombre de lignes supprimees
{
    bool pleine, vide;
    int i=1, k, nblPleine=0; //On considere que la 1ere ligne ne peut jamais etre pleine
    //Recherche de lignes pleines dans le puits : il peut y en avoir 4 au maximum
    while (i<m_hauteur-2 && nblPleine<4)
    {
        pleine = true;
        for (int j=2;j<m_largeur-2;j++)
        {
            if (m_grille[i][j]->getType()==0)
                pleine=false; //on a trouve une case vide sur la ligne
        }
        if (pleine) //ligne pleine : on decale tout vers le bas, a partir de la ligne au dessus de celle a supprimer
        {
            nblPleine++;
            k = i; //on parcourt la grille de maniere ascendante a partir de la ligne i
            vide = false; //permet d'indiquer si la ligne du dessus est vide
            while (k>0 && vide==false)
            {
                vide = true; //on peut sortir de la boucle s'il n'y a plus rien a decaler
                for (int j=2;j<m_largeur-2;j++)
                {
                    m_grille[k][j]->setType(m_grille[k-1][j]->getType()); //decalage des types
                    if (m_grille[k-1][j]->getType()!=0)
                        vide = false;
                }
                k--;
            }
        }
        i++;
    }
    return nblPleine;
}
