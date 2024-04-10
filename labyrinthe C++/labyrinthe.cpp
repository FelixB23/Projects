#include "labyrinthe.hpp"

//Labyrinthe

Labyrinthe::Labyrinthe(int nbl=L, int nbc=C)
{
    m_nbl = nbl;
    m_nbc = nbc;
    m_plateau = new Plateau(nbl,nbc);
    m_personnage = new Personnage(1,1); //on place le personnage en haut a gauche
    m_plateau->setCase(m_nbl-1,m_nbc-2,new Sortie(m_nbl-1,m_nbc-2)); //on place la sortie en bas a droite

    //Contour du labyrinthe
    for (int i=0;i<m_nbl;i++)
    {
        m_plateau->setCase(i,0,new Mur(i,0)); //contour gauche
        m_plateau->setCase(i,m_nbc-1,new Mur(i,m_nbc-1)); //contour droit
    }
    for (int j=1;j<m_nbc-2;j++)
    {
        m_plateau->setCase(0,j,new Mur(0,j)); //contour du haut
        m_plateau->setCase(m_nbl-1,j,new Mur(m_nbl-1,j)); //contour du bas
    }
    m_plateau->setCase(0,m_nbc-2,new Mur(0,m_nbc-2));

    //Reste du labyrinthe (ligne par ligne)
    for (int j=1;j<m_nbc-1;j++) //1ere ligne
    {
        if (j==11 || j==15 || j==27 || j==39 || j==43)
            m_plateau->setCase(1,j,new Mur(1,j));
        else
            m_plateau->setCase(1,j,new Couloir(1,j));
    }
    for (int j=1;j<m_nbc-1;j++) //2eme ligne...
    {
        if ((j>=2 && j<=4) || (j>=6 && j<=9) || j==11 || j==13 || j==15 || (j>=17 && j<=25) || j==27 || (j>=29 && j<=37) || j==39 || j==41 || j>=45)
            m_plateau->setCase(2,j,new Mur(2,j));
        else
            m_plateau->setCase(2,j,new Couloir(2,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==2 || j==6 || j==11 || j==13 || j==15 || j==19 || j==27 || j==32 || (j>=37 && j<=39) || j==41 || (j>=43 && j<=45))
            m_plateau->setCase(3,j,new Mur(3,j));
        else
            m_plateau->setCase(3,j,new Couloir(3,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if ((j>=2 && j<=6) || (j>=8 && j<=11) || j==13 || (j>=15 && j<=17) || j==19 || (j>=21 && j<=30) || j==32 || j==34 || j==35 || j==41 || j==43 || j==47)
            m_plateau->setCase(4,j,new Mur(4,j));
        else
            m_plateau->setCase(4,j,new Couloir(4,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==6 || j==13 || j==19 || j==21 || j==25 || j==32 || j==35 || (j>=37 && j<=41) || j==43 || (j>=45 && j<=47))
            m_plateau->setCase(5,j,new Mur(5,j));
        else
            m_plateau->setCase(5,j,new Couloir(5,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j<=4 || (j>=6 && j<=10) || (j>=12 && j<=17) || j==19 || j==21 || j==23 || (j>=28 && j<=33) || j==35 || j==37 || j==43 || j==47)
            m_plateau->setCase(6,j,new Mur(6,j));
        else
            m_plateau->setCase(6,j,new Couloir(6,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==4 || j==6 || j==12 || j==17 || j==19 || j==21 || (j>=23 && j<=26) || j==28 || j==33 || j==35 || (j>=37 && j<=45) || j==47)
            m_plateau->setCase(7,j,new Mur(7,j));
        else
            m_plateau->setCase(7,j,new Couloir(7,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==2 || j==4 || j==8 || (j>=10 && j<=12) || j==14 || j==15 || j==17 || j==19 || j==21 || j==26 || j==28 || j==30 || j==31 || j==35 || j==37 || j==47)
            m_plateau->setCase(8,j,new Mur(8,j));
        else
            m_plateau->setCase(8,j,new Couloir(8,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==2 || j==7 || j==8 || j==10 || j==14 || j==17 || (j>=21 && j<=24) || j==26 || j==28 || (j>=31 && j<=35) || j==37 || (j>=39 && j<=47))
            m_plateau->setCase(9,j,new Mur(9,j));
        else
            m_plateau->setCase(9,j,new Couloir(9,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if ((j>=2 && j<=7) || j==10 || (j>=12 && j<=14) || j==16 || j==17 || j==19 || j==28 || j==29 || j==31 || j==35 || j==39)
            m_plateau->setCase(10,j,new Mur(10,j));
        else
            m_plateau->setCase(10,j,new Couloir(10,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==6 || j==9 || j==10 || j==12 || j==16 || j==19 || (j>=22 && j<=28) || j==31 || j==33 || (j>=35 && j<=39) || (j>=41 && j<=47))
            m_plateau->setCase(11,j,new Mur(11,j));
        else
            m_plateau->setCase(11,j,new Couloir(11,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j<=4 || (j>=6 && j<=9) || j==12 || (j>=14 && j<=16) || j==18 || j==19 || j==22 || j==30 || j==31 || j==33 || j==37 || j==41 || j==47)
            m_plateau->setCase(12,j,new Mur(12,j));
        else
            m_plateau->setCase(12,j,new Couloir(12,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==11 || j==12 || j==16 || j==22 || (j>=24 && j<=30) || j==33 || j==35 || j==37|| (j>=39 && j<=41) || (j>=43 && j<=45) || j==47)
            m_plateau->setCase(13,j,new Mur(13,j));
        else
            m_plateau->setCase(13,j,new Couloir(13,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if ((j>=2 && j<=12) || j==14 || (j>=16 && j<=22) || j==24 || j==33 || j==35 || j==37 || j==39 || j==43 || j==45 || j==47)
            m_plateau->setCase(14,j,new Mur(14,j));
        else
            m_plateau->setCase(14,j,new Couloir(14,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==2 || j==6 || (j>=12 && j<=14) || j==24 || (j>=28 && j<=30) || j==33 || j==35 || j==37 || (j>=39 && j<=43) || j==45 || j==47)
            m_plateau->setCase(15,j,new Mur(15,j));
        else
            m_plateau->setCase(15,j,new Couloir(15,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==2 || j==4 || j==6 || (j>=8 && j<=10) || (j>=14 && j<=24) || j==26 || j==28 || j==32 || j==33 || j==35 || j==37 || j==45)
            m_plateau->setCase(16,j,new Mur(16,j));
        else
            m_plateau->setCase(16,j,new Couloir(16,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if (j==2 || j==4 || j==6 || j==8 || (j>=10 && j<=12) || j==14 || j==18 || j==22 || j==26 || (j>=28 && j<=32) || j==35 || (j>=37 && j<=43) || j>=45)
            m_plateau->setCase(17,j,new Mur(17,j));
        else
            m_plateau->setCase(17,j,new Couloir(17,j));
    }
    for (int j=1;j<m_nbc-1;j++)
    {
        if ( j==4 || j==8 || j==16 || j==20 || (j>=24 && j<=26) || j==34 || j==35 || j==43)
            m_plateau->setCase(18,j,new Mur(18,j));
        else
            m_plateau->setCase(18,j,new Couloir(18,j));
    }
}



Labyrinthe::Labyrinthe(Labyrinthe& l)
{
    m_nbl = l.m_nbl;
    m_nbc = l.m_nbc;
    m_plateau = new Plateau(m_nbl,m_nbc);
    m_personnage = new Personnage(1,1);
    m_personnage = l.m_personnage;

    for (int i=0;i<m_nbl;i++)
    {
        for (int j=0;j<m_nbl;i++)
        {
            m_plateau->setCase(i,j,l.m_plateau->getCase(i,j));
        }
    }
}

Labyrinthe::~Labyrinthe()
{
    delete[] m_plateau; //appel du destructeur de plateau
    delete[] m_personnage; //appel du destructeur de personnage
}

void Labyrinthe::afficher()
{
    m_plateau->afficher(*m_personnage);
}

void Labyrinthe::deplacerPersoDroite()
{
    //On verifie que la case sur laquelle on veut se deplacer existe et n'est pas un mur
    if (m_personnage->getj()+1<m_nbc && m_plateau->getCase(m_personnage->geti(),m_personnage->getj()+1)->getType()!=2)
        m_personnage->deplacerDroite();
    else
        throw DeplacementImpossible("Impossible de se deplacer ici");
}

void Labyrinthe::deplacerPersoGauche()
{
    //On verifie que la case sur laquelle on veut se deplacer existe et n'est pas un mur
    if (m_personnage->getj()-1>=0 && m_plateau->getCase(m_personnage->geti(),m_personnage->getj()-1)->getType()!=2)
        m_personnage->deplacerGauche();
    else
        throw DeplacementImpossible("Impossible de se deplacer ici");
}

void Labyrinthe::deplacerPersoHaut()
{
    //On verifie que la case sur laquelle on veut se deplacer existe et n'est pas un mur
    if (m_personnage->geti()-1>=0 && m_plateau->getCase(m_personnage->geti()-1,m_personnage->getj())->getType()!=2)
        m_personnage->deplacerHaut();
    else
        throw DeplacementImpossible("Impossible de se deplacer ici");
}

void Labyrinthe::deplacerPersoBas()
{
    //On verifie que la case sur laquelle on veut se deplacer existe et n'est pas un mur
    if (m_personnage->geti()+1<m_nbl && m_plateau->getCase(m_personnage->geti()+1,m_personnage->getj())->getType()!=2)
        m_personnage->deplacerBas();
    else
        throw DeplacementImpossible("Impossible de se deplacer ici");
}

bool Labyrinthe::fini()
{
     //On regarde si le type de la case sur laquelle est posé le personnage est sortie (3)
    if (m_plateau->getCase(m_personnage->geti(),m_personnage->getj())->getType()==3)
        return true;
    return false;
}
