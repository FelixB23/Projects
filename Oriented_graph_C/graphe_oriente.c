/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des graphes orientés
 */

/* Importation du fichier entête*/
#include "graphe_oriente.h"

/* Déclaration des fonctions et procédures */
void GrapheOriente_afficherSommet(Sommet s, Etiquette e)
{
	printf("%d:\t%s\n",s,e);
}

void GrapheOriente_afficherArc(Sommet ei, Sommet ef, Valeur v)
{
	printf("Extremite initiale: %d\n",ei);
	printf("Extremite Finale: %d\n",ef);
	printf("Valeur: %f\n",v);
}

void GrapheOriente_creer(GrapheOriente *g, int M)
{
	/* Variables locales */
	int i,j;

	/* Allocation dynamique de la matrice d'adjacence */
	(*g).mAdjacence = (Sommet**) malloc(M*sizeof(Sommet*));

	/* Controle allocation */
	if ((*g).mAdjacence == NULL)
	{
		printf("Erreur d'allocation.\n");
		exit(-1);
	}
	for (i=0;i<M;i++)
	{
		(*g).mAdjacence[i] = (Sommet*) malloc(M*sizeof(Sommet));
		/* Controle allocation */
		if (((*g).mAdjacence[i]) == NULL)
		{
			printf("Erreur d'allocation.\n");
			exit(-1);
		}
	}
	/* Initialisation des termes de la matrice à 0 */
	for (i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			(*g).mAdjacence[i][j] = 0;
		}
	}

	(*g).M = M;

	/* Création des dictionnaires */
	Dictionnaire_Sommets_creer(&((*g).ds));
	Dictionnaire_Arcs_creer(&((*g).da));
}

int GrapheOriente_sommetPresent(GrapheOriente g, Sommet s)
{
	return Dictionnaire_Sommets_estPresent(g.ds,s);
}

int GrapheOriente_arcPresent(GrapheOriente g, Sommet ei, Sommet ef)
{
	if (g.mAdjacence[ei][ef]==1)
        return 1;
    else
        return 0;
}

void GrapheOriente_ajouterSommet(GrapheOriente *g, Sommet s, Etiquette e)
{
	Dictionnaire_Sommets_ajouter(&((*g).ds),s,e);
}

void GrapheOriente_ajouterArc(GrapheOriente *g, Sommet ei, Sommet ef, Valeur v)
{
	/*variable locale*/
	t_cle_arc cle;

	if ((*g).mAdjacence[ei][ef] == 0 && Dictionnaire_Sommets_estPresent((*g).ds,ei) && Dictionnaire_Sommets_estPresent((*g).ds,ef))
	{
		cle.extremiteInitiale = ei;
		cle.extremiteFinale = ef;
		Dictionnaire_Arcs_ajouter(&((*g).da),cle,v);
		(*g).mAdjacence[ei][ef] = 1;
	}
}

void GrapheOriente_supprimerSommet(GrapheOriente *g, Sommet s)
{
	/*variables locales*/
	int i,j;
	t_cle_arc cle;

	if (Dictionnaire_Sommets_estPresent((*g).ds,s))
	{
		/* Parcours en colonne, sur la ligne s */
		cle.extremiteInitiale = s;
		for (j=0;j<(*g).M;j++)
		{
			if ( (*g).mAdjacence[s][j]!=0 )
			{
				(*g).mAdjacence[s][j] = 0;
				cle.extremiteFinale = j;
				Dictionnaire_Arcs_retirer(&((*g).da),cle);
			}
		}

		/* Parcours en ligne, sur la colonne s */
		for (i=0;i<(*g).M;i++)
		{
			if ( (*g).mAdjacence[i][s]!=0 )
			{
				(*g).mAdjacence[i][s] = 0;
				cle.extremiteInitiale = i;
				cle.extremiteFinale = s;
				Dictionnaire_Arcs_retirer(&((*g).da),cle);
			}
		}
		Dictionnaire_Sommets_retirer(&((*g).ds),s);
	}
}

void GrapheOriente_supprimerArc(GrapheOriente *g, Sommet ei, Sommet ef)
{
	/*variable locale*/
	t_cle_arc cle;

	if ((*g).mAdjacence[ei][ef] != 0)
	{
		(*g).mAdjacence[ei][ef] = 0;
		cle.extremiteInitiale = ei;
		cle.extremiteFinale = ef;
		Dictionnaire_Arcs_retirer(&((*g).da),cle);
	}
}

void GrapheOriente_afficher(GrapheOriente g)
{
	/*variables locales*/
	int i,j;

	printf("Sommets : \n");
	Dictionnaire_Sommets_afficher(g.ds);
	printf("Arcs : \n");
	Dictionnaire_Arcs_afficher(g.da);
	printf("Matrice d'adjacence :\n");
	for (i=0;i<g.M;i++)
	{
		for (j=0;j<g.M;j++)
			printf("%d\t",g.mAdjacence[i][j]);
		printf("\n");
	}
}

void GrapheOriente_parcoursLargeur(GrapheOriente g, Sommet s)
{
	/*variables locales*/
	Sommet somk, somi;
	Etiquette etiquette;
	File fileSommetsGris;
	int couleurs[g.M];
	int i;

	File_creer(&fileSommetsGris);
	for (i=0;i<g.M;i++)
		couleurs[i] = 0;
	File_enfiler(&fileSommetsGris,s);
	couleurs[s] = 1;
	while (!File_estVide(fileSommetsGris))
	{
		somk = File_premierElement(fileSommetsGris);
		File_defiler(&fileSommetsGris);
		for (somi=0;somi<g.M;somi++)
		{
			if ((g.mAdjacence[somk][somi]!=0) && (couleurs[somi]==0))
			{
				File_enfiler(&fileSommetsGris,somi);
				couleurs[somi] = 1;
			}
		}
		couleurs[somk] = 2;
		Dictionnaire_Sommets_rechercher(g.ds,somk,&etiquette);
		printf("%s\t", etiquette);
	}
}

void GrapheOriente_parcoursProfondeur(GrapheOriente g, Sommet s)
{
    /*variables locales*/
    Sommet somk, somi;
    Etiquette etiquette;
    Pile pileSommetsGris;
    int couleurs[g.M];
    int siOK;
    int i;

    Pile_creer(&pileSommetsGris);
    for (i=0;i<g.M;i++)
        couleurs[i] = 0;
    Pile_empiler(&pileSommetsGris,s);
    couleurs[s] = 1;
    while (!Pile_estVide(pileSommetsGris))
    {
        somk = Pile_sommet(pileSommetsGris);
        siOK = 0;
        somi = 1;
        while ((somi<g.M) && (!siOK))
        {
            if ((g.mAdjacence[somk][somi] != 0) && (couleurs[somi] == 0))
            {
                Pile_empiler(&pileSommetsGris,somi);
                couleurs[somi] = 1;
                siOK = 1;
            }
            somi++;
        }
        if (!siOK)
        {
            Pile_depiler(&pileSommetsGris);
            couleurs[somk] = 2;
            Dictionnaire_Sommets_rechercher(g.ds, somk, &etiquette);
            printf("%s\t", etiquette);
        }
    }
}

void GrapheOriente_vider(GrapheOriente *g)
{
    /*variables locales*/
    int i,j;

    Dictionnaire_Arcs_vider(&((*g).da));
    Dictionnaire_Sommets_vider(&((*g).ds));
    for (i=0;i<(*g).M;i++)
    {
        for (j=0;j<(*g).M;j++)
        {
            (*g).mAdjacence[i][j] = 0;
        }
    }
}
