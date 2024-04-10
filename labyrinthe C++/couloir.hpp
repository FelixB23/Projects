#ifndef __COULOIR__HPP__
#define __COULOIR__HPP__

    #include "objet_graphique_fixe.hpp"

    class Couloir : public objetGraphiqueFixe{

            public:
                Couloir(int i, int j);
                void afficher();
        };

#endif
