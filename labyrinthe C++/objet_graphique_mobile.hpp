#ifndef __OBJET_GRAPHIQUE_MOBILE__HPP__
#define __OBJET_GRAPHIQUE_MOBILE__HPP__

    #include "objet_graphique.hpp"

    class objetGraphiqueMobile : public objetGraphique{

            public:
                objetGraphiqueMobile(int i, int j);
                void deplacerDroite();
                void deplacerGauche();
                void deplacerHaut();
                void deplacerBas();
        };

#endif
