#include "labyrinthe.hpp" //inclut tous les fichiers

int main(void)
{
    try //devrait toujours marcher a moins de modifier le constructeur de labyrinthe
    {
        Labyrinthe l(L,C);
        char choix;
        l.afficher();
        while (!l.fini()) //tant que le personnage n'est pas arrive a la sortie
        {
            cout << "Quel deplacement ? Bas(B), Haut(H), Gauche(G), Droite(D) :" << endl;
            cin >> choix; //on suppose que l'utilisateur ecrit un des caracteres ci-dessus
            try
            {
                switch (choix)
                {
                    case 'B': l.deplacerPersoBas();
                              break;
                    case 'H': l.deplacerPersoHaut();
                              break;
                    case 'G': l.deplacerPersoGauche();
                              break;
                    case 'D': l.deplacerPersoDroite();
                              break;
                }
            }
            catch(DeplacementImpossible& ex)
            {
                cerr << ex.m_message << endl;
            }
        l.afficher();
        }
        cout << "Gagne !" <<endl;
    }
    catch(SaisieIncorrecte& ex)
    {
        cerr << ex.m_message << endl;
    }






    return 0;
}
