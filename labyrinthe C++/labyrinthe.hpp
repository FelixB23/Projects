#ifndef __LABYRINTHE__HPP__
#define __LABYRINTHE__HPP__

    #include "plateau.hpp" //inclut en meme temps les fichiers objet_graphique_mobile.hpp objet_graphique.hpp, saisieIncorrecte.hpp couloir.hpp et objet_graphique_fixe.hpp
    #include "personnage.hpp"
    #include "deplacementImpossible.hpp"
    #include "mur.hpp"
    #include "sortie.hpp"

    class Labyrinthe {
            protected:
                int m_nbl;
                int m_nbc;
                Plateau* m_plateau;
                Personnage* m_personnage;
            public:
                Labyrinthe(int nbl, int nbc);
                Labyrinthe(Labyrinthe& l);
                ~Labyrinthe();
                void afficher();
                void deplacerPersoDroite();
                void deplacerPersoGauche();
                void deplacerPersoHaut();
                void deplacerPersoBas();
                bool fini();
        };

#endif
