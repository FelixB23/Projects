#include "partie.h"

//Constructeur par defaut
Partie::Partie()
{
    m_score = 0;
    m_niveau = 0;
    m_tempsDescente = 100; //temps en centieme de seconde entre chaque descente du tetromino
    m_nbLignesCompletees = 0;
    m_finie = false;
    m_reserve = false;
    m_p = new Puits();

    srand(time(0)); //pour que le nombre soit bien aleatoire

    //Le premier tetromino est tire aleatoirement
    m_t = pieceAleatoire();

    //Le tetromino suivant est tire aleatoirement
    m_t2 = pieceAleatoire();
    m_t2->setx(m_p->getLargeur() + m_p->getLargeur()/8);
    m_t2->sety(m_p->getHauteur()/2); //place du tetromino suivant a droite du puits

    m_t3 = new Tetrominos1(); //tetromino en reserve : on ne l'affiche pas tout de suite
}

//Constructeur de recopie
Partie::Partie(const Partie& par)
{
    m_score = par.m_score;
    m_niveau = par.m_niveau;
    m_tempsDescente = par.m_tempsDescente;
    m_nbLignesCompletees = par.m_nbLignesCompletees;
    m_finie = par.m_finie;
    m_p = par.m_p;
    m_t = par.m_t;
}

//Destructeur
Partie::~Partie()
{
    delete m_p;
    delete m_t;
    delete m_t2;
    delete m_t3;
}

//accesseurs
int Partie::getScore()
{
    return m_score;
}

int Partie::getNiveau()
{
    return m_niveau;
}

int Partie::getTempsDescente()
{
    return m_tempsDescente;
}

int Partie::getNbLignesCompletees()
{
    return m_nbLignesCompletees;
}

bool Partie::getFinie()
{
    return m_finie;
}

//Autres methodes
bool Partie::possibTranslation(bool direction) //direction=true pour droite, false pour gauche
{
    if (direction==true)
    {
        for (int i=0;i<m_t->getLigne();i++)
        {
            for (int j=0;j<m_t->getCol();j++)
            {
               //on regarde pour chaque case pleine du tetromino si sa translation droite ne mène pas sur une case vide du puits
               if (m_t->getMat(i,j) && m_p->getCase(m_t->gety()+i,m_t->getx()+j+1)->getType()!=0)
                   return false;
            }
        }
    }
    else
    {
        for (int i=0;i<m_t->getLigne();i++)
        {
            for (int j=0;j<m_t->getCol();j++)
            {
               //on regarde pour chaque case pleine du tetromino si sa translation gauche ne mène pas sur une case vide du puits
               if (m_t->getMat(i,j) && m_p->getCase(m_t->gety()+i,m_t->getx()+j-1)->getType()!=0)
                   return false;
            }
        }
    }
    return true;
}

void Partie::translater(bool direction) //direction=true pour droite, false pour gauche
{
    if (direction)
        m_t->translater(1,0);
    else
        m_t->translater(-1,0);
}

bool Partie::possibRotation()
{
    for (int i=0;i<m_t->getLigne();i++){
        for (int j=0;j<m_t->getCol();j++)
        {
           //on regarde pour chaque case pleine si sa rotation ne mène pas sur une case vide du puits
           if (m_t->getMat(i,j) && m_p->getCase(m_t->gety()+j,m_t->getx()+m_t->getLigne()-1-i)->getType()!=0)
               return false;
        }
    }
    return true;
}

void Partie::pivoter()
{
    m_t->pivoter();
}

void Partie::afficher(QPainter *p)
{
    m_p->afficher(p); //affichage du puits
    m_t->afficher(p); //affichage du tetromino par dessus
    m_t2->afficher(p);
    if (m_reserve==true)
        m_t3->afficher(p);
}

bool Partie::descentePossible()
{
    for (int i=0;i<m_t->getLigne();i++)
    {
        for(int j=0;j<m_t->getCol();j++)
        {
           //on regarde pour chaque case pleine si sa translation vers le bas ne mène pas sur une case vide du puits
            if (m_t->getMat(i,j)==true && m_p->getCase(m_t->gety()+i+1,m_t->getx()+j)->getType()!=0)
                return false;
        }
    }
    return true;;
}

void Partie::accelerer() //pre-condition : deplacementPossible()
{
    m_t->translater(0,1); //tomber d'une case
}

void Partie::poser() //pre-condition : !descentePossible()
{
    m_t->setEstBloque(true);
    //On remplit alors dans les cases du puits placees sous les cases pleines du tetromino
    for (int i=0;i<m_t->getLigne();i++)
    {
        for (int j=0;j<m_t->getCol();j++)
        {
            if (m_t->getMat(i,j)==true) //la case prend le meme type que le tetromino
                m_p->getCase(m_t->gety()+i,m_t->getx()+j)->setType(m_t->getType());
        }
    }
}

void Partie::niveauSuivant() //un niveau toutes les 5 lignes completees
{
    if (m_niveau < 10) //niveau max = 10
    {
        m_niveau++;
        if (m_niveau<9)
            m_tempsDescente -= 10;
        else //2 derniers niveaux
            m_tempsDescente -= 5;
    }
}

void Partie::calculerScore() //pre-condition : !descentePossible()
{
    //on supprime eventuellement une ou plusieurs lignes pleines et on incremente le score
    //on gagne un niveau toutes les 5 lignes completees
    switch(m_p->supprimerLignes())
    {
        case 1: m_score += 40*(m_niveau+1);
                m_nbLignesCompletees += 1;
                if (m_nbLignesCompletees % 5 == 0)
                    niveauSuivant();
                break;
        case 2: m_score += 100*(m_niveau+1);
                m_nbLignesCompletees += 2;
                if (m_nbLignesCompletees % 5 == 0 || m_nbLignesCompletees % 5 == 1)
                    niveauSuivant();
                break;
        case 3: m_score += 300*(m_niveau+1);
                m_nbLignesCompletees += 3;
                if (m_nbLignesCompletees % 5 == 0 || m_nbLignesCompletees % 5 == 1 || m_nbLignesCompletees % 5 == 2)
                    niveauSuivant();
                break;
        case 4: m_score += 1200*(m_niveau+1);
                m_nbLignesCompletees += 4;
                if (m_nbLignesCompletees % 5 == 0 || m_nbLignesCompletees % 5 == 1 || m_nbLignesCompletees % 5 == 2 || m_nbLignesCompletees % 5 == 3)
                    niveauSuivant();
                break;
    }
}

Tetrominos* Partie::pieceAleatoire()
{
    Tetrominos *t;
    switch (rand() % 7 + 1) //renvoie un nombre aleatoire entre 1 et 7
    {
        case 1: t = new Tetrominos1();
                break;
        case 2: t = new Tetrominos2();
                break;
        case 3: t = new Tetrominos3();
                break;
        case 4: t = new Tetrominos4();
                break;
        case 5: t = new Tetrominos5();
                break;
        case 6: t = new Tetrominos6();
                break;
        case 7: t = new Tetrominos7();
                break;
        default: t = new Tetrominos1(); //pour eviter un warning
    }
    return t;
}

void Partie::pieceSuivante() //pre-condition : !descentePossible()
{
    delete m_t; //On supprime le  tetrominos
    m_t2->setx(5); //placement en haut du puits
    m_t2->sety(0);
    m_t = m_t2; //le suivant devient le courant
    if (estFinie()==false) //si on n'est pas arrive en haut du puits, le jeu continue avec le tetromino suivant
    {
        //on cree un nouveau tetromino suivant aleatoirement
        rand(); //contourne un problème de nombre aléatoire
        rand(); //contourne un problème de nombre aléatoire
        m_t2 = pieceAleatoire();
        m_t2->setx(9*m_p->getLargeur()/8);
        m_t2->sety(m_p->getHauteur()/2); //place de la piece suivante
    }
    else
        m_finie=true; //affiche l'ecran de fin
}

void Partie::tomber() //tomber directement au fond du puits
{
    int i,j;
    //Recherche de la ligne ou va tomber le tetromino
    bool trouve = false;
    m_t->setEstBloque(true);
    int k = m_t->gety(); //on cherche a partir de la ligne ou est situe le tetromino
    while (!trouve)
    {
        k++;
        i=0;
        while (i<m_t->getLigne() && !trouve)
        {
            j=0;
            while (j<m_t->getCol() && !trouve)
            {
                //On regarde la projection de chaque case pleine du tetromino sur la ligne k du puits
                if (m_t->getMat(i,j) && m_p->getCase(k+i,m_t->getx()+j)->getType()!=0)
                    trouve = true; //la projection sur cette ligne n'est pas possible
                j++;
            }
            i++;
        }
    }

    //Projection de chaque case pleine du tetromino sur la ligne k-1
    for (i=0;i<m_t->getLigne();i++)
    {
        for (j=0;j<m_t->getCol();j++)
        {
            if (m_t->getMat(i,j)) //changement du type de la case du puits sur laquelle est projete le tetromino
                m_p->getCase(k-1+i,m_t->getx()+j)->setType(m_t->getType());
        }
    }
}

bool Partie::possibReservation()
{
    bool ok = true;
    if (m_reserve == false) //cas ou le tetromino est remplace par le suivant
    {
        for (int i=0;i<m_t2->getLigne();i++)
        {
            for (int j=0;j<m_t2->getCol();j++)
            {
                //on verifie pour chaque case pleine du tetromino suivant, que lorsqu'on le place a
                //l'endroit de celui qui tombe, elle ne mene pas sur une case pleine du puits
                if (m_t2->getMat(i,j) && m_p->getCase(m_t->gety()+i,m_t->getx()+j)->getType()!=0)
                    ok = false;
            }
        }
    }
    else //cas ou le tetromino est remplace par celui en reserve
    {
        for (int i=0;i<m_t3->getLigne();i++)
        {
            for (int j=0;j<m_t3->getCol();j++)
            {
                //on verifie pour chaque case pleine du tetromino en reserve, que lorsqu'on le place a
                //l'endroit de celui qui tombe, elle ne mene pas sur une case pleine du puits
                if (m_t3->getMat(i,j) && m_p->getCase(m_t->gety()+i,m_t->getx()+j)->getType()!=0)
                    ok = false;
            }
        }
    }
    return ok;
}

void Partie::reserver()
{
    if (m_reserve == false)
    {
        m_t3 = m_t; //le tetromino qui tombait va dans la reserve
        m_t = m_t2; //il est remplace par le suivant
        m_t2 = pieceAleatoire(); //generation d'un nouveau tetromino suivant
        m_t2->setx(9*m_p->getLargeur()/8);
        m_t2->sety(m_p->getHauteur()/2); //place du tetromino suivant
        m_reserve = true; //la reserve devient pleine
    }
    else //si deja un tetromino en reserve
    {
        Tetrominos *t; //tetromino temporaire
        t = m_t;
        m_t = m_t3;
        m_t3 = t; //echange du tetromino qui tombe et de celui en reserve
    }
    m_t->setx(m_t3->getx());
    m_t->sety(m_t3->gety()); //il reprend ses anciennes coordonnees
    m_t3->setx(9*m_p->getLargeur()/8);
    m_t3->sety(3*m_p->getHauteur()/4); //place du tetromino en reserve
}

bool Partie::estFinie()
{
    bool plein = false;
    for (int i=0;i<m_t->getLigne();i++)
    {
        for (int j=0;j<m_t->getCol();j++)
        {
            if (m_t->getMat(i,j)==true && m_p->getCase(m_t->gety()+i,m_t->getx()+j)->getType()!=0)
                plein = true;
        }
    }
    return plein;
}
