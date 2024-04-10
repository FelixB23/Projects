#ifndef __PLATEAU__HPP__
#define __PLATEAU__HPP__

    #include "objet_graphique_mobile.hpp"
    #include "couloir.hpp"

    class Plateau {
            protected:
                int m_nbl;
                int m_nbc;
                objetGraphiqueFixe*** m_plateau;
            public:
                Plateau(int nbl, int nbc);
                Plateau(const Plateau& p);
                ~Plateau();
                void setCase (int i, int j, objetGraphiqueFixe* o);
                objetGraphiqueFixe* getCase(int i, int j);
                void afficher();
                void afficher(objetGraphiqueMobile& p);
        };

#endif
