#ifndef __OBJET_GRAPHIQUE__HPP__
#define __OBJET_GRAPHIQUE__HPP__

    #include <iostream>
    using namespace std;
    #include "saisieIncorrecte.hpp"

    const int L=20, C=50; //nombre de lignes et nombre de colonnes maximum et par défaut

    class objetGraphique{
        protected:
            int m_i;
            int m_j;
            int m_type;

        public:
            objetGraphique(int i, int j);
            int getType();
            int geti();
            int getj();
            virtual void afficher()=0;
    };

#endif
