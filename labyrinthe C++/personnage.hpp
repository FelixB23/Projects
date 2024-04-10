#ifndef __PERSONNAGE__HPP__
#define __PERSONNAGE__HPP__

    #include "objet_graphique_mobile.hpp"

    class Personnage : public objetGraphiqueMobile{
            public:
                Personnage(int i, int j);
                void afficher();
        };

#endif
