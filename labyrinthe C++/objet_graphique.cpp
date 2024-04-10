#include "objet_graphique.hpp"

//objet graphique
objetGraphique::objetGraphique(int i=0, int j=0){
    if (i>=0 && j>=0 && i<L && j<C) //Les coordonnees i et j doivent etre dans le plateau
    {
        m_i=i;
        m_j=j;
        m_type=1; //type couloir par defaut
    }
    else
        throw SaisieIncorrecte("Erreur : Les coordonnees sortent du plateauh");
}

int objetGraphique::getType(){
    return m_type;
}

int objetGraphique::geti(){
    return m_i;
}

int objetGraphique::getj(){
    return m_j;
}
