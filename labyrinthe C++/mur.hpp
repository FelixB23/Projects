#ifndef __MUR__HPP__
#define __MUR__HPP__

    #include "objet_graphique_fixe.hpp"

    class Mur : public objetGraphiqueFixe{
            public:
                Mur(int i, int j);
                void afficher();
        };

#endif
