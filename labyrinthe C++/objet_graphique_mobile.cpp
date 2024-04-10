#include "objet_graphique_mobile.hpp"

//objet graphique Mobile
objetGraphiqueMobile::objetGraphiqueMobile(int i=0, int j=0):objetGraphique(i,j){}

// deplacement i ligne et j colonne donc gauche j-1, droite j+1, haut i-1, bas i+1
void objetGraphiqueMobile::deplacerGauche(){
    m_j -= 1;
}

void objetGraphiqueMobile::deplacerDroite(){
    m_j += 1;
}

void objetGraphiqueMobile::deplacerHaut(){
    m_i -= 1;
}

void objetGraphiqueMobile::deplacerBas(){
    m_i += 1;
}
