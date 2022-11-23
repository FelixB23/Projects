/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Programme principale
 */

#include "graphe_oriente.h"

int main(void)
{
	/*Déclaration des variables*/
	GrapheOriente g;
	Etiquette e;
	int choix,ei,ef,M;
	Valeur v;
	Sommet s;

	/*Initialisation du graphe*/
	printf("Combien d'elements doit contenir le graphe (au maximum)?\n");
	scanf("%d",&M);
    GrapheOriente_creer(&g,M);
    printf("\n");

    /*Affichage du menu*/
	do{
		printf("0 : Quitter. \n");
		printf("1 : Ajouter un sommet\n");
		printf("2 : Ajouter un arc\n");
		printf("3 : Tester si un sommet est present\n");
		printf("4 : Tester si un arc est present\n");
		printf("5 : Supprimer un sommet\n");
		printf("6 : Supprimer un arc\n");
		printf("7 : Afficher un sommet\n");
		printf("8 : Afficher un arc\n");
		printf("9 : Afficher le graphe\n");
		printf("10 : Afficher le parcours en largeur\n");
		printf("11 : Afficher le parcours en profondeur\n");
		printf("12 : Vider le graphe\n");
		printf("\n");
		printf("Quel est votre choix ? ");
		scanf("%d",&choix);
        switch (choix) /*choix de l'opération*/
		{
			case 1 :
			    do
                {
                    printf("Quel sommet voulez-vous ajouter (entre 0 et %d inclus) ?\n",M-1);
                    scanf("%d",&s);
                }
                while (s<0 || s>=M);
                if (!GrapheOriente_sommetPresent(g,s)) /*on verifie que le sommet n'est pas déjà présent*/
                {
                    printf("Donner son etiquette :\n");
                    scanf("%s",e);
                    GrapheOriente_ajouterSommet(&g,s,e);
                    printf("Le sommet a ete ajoute.\n\n");
                }
                else
                    printf("Le sommet existe deja !\n\n");
				break;

			case 2 :
                printf("Donner l'extremite initiale de l'arc :\n");
                scanf("%d",&ei);
                printf("Donner l'extremite finale de l'arc :\n");
                scanf("%d",&ef);
                if (g.mAdjacence[ei][ef] == 0) /*On vérifie que l'arc n'est pas déjà présent*/
                {
                    printf("Quelle est sa valeur ?\n");
                    scanf("%f",&v);
                    GrapheOriente_ajouterArc(&g,ei,ef,v);
                    if (g.mAdjacence[ei][ef] == 1) /*On vérifie si l'arc a bien été ajouté*/
                        printf("L'arc a ete ajoute.\n\n");
                    else
                        printf("Erreur : veuillez verifier les extremites.\n\n");
                }
                else
                    printf("L'arc existe deja !\n\n");
				break;

			case 3 :
			    printf("Entrez un sommet (la cle) ?\n");
                scanf("%d",&s);
                if (GrapheOriente_sommetPresent(g,s))
                    printf("Le sommet %d est present dans le graphe.\n\n",s);
                else
                    printf("Le sommet %d n'est pas present dans le graphe.\n\n",s);
				break;

			case 4 :
			    printf("Entrez l'extremite initiale de l'arc :\n");
                scanf("%d",&ei);
                printf("Entrez l'extremite finale de l'arc :\n");
                scanf("%d",&ef);
                if (GrapheOriente_arcPresent(g,ei,ef))
                    printf("L'arc est present dans le graphe.\n\n");
                else
                    printf("L'arc n'est pas present dans le graphe.\n\n");
				break;

			case 5 :
			    printf("Quel est le sommet a supprimer ? (la cle)\n");
			    scanf("%d",&s);
			    if (GrapheOriente_sommetPresent(g,s))
                {
                    GrapheOriente_supprimerSommet(&g,s);
                    printf("Le sommet a ete supprime.\n\n");
                }
                else
                    printf("Le sommet n'a pas ete trouve.\n\n");
				break;

			case 6 :
			    printf("Entrez l'extremite initiale de l'arc a supprimer :\n");
			    scanf("%d",&ei);
			    printf("Entrez l'extremite finale de l'arc a supprimer :\n");
			    scanf("%d",&ef);
			    if (g.mAdjacence[ei][ef]==0)
                {
                    GrapheOriente_supprimerArc(&g,ei,ef);
                    printf("L'arc a ete supprime.\n\n");
                }
                else
                    printf("L'arc n'a pas ete trouve.\n\n");
                break;

			case 7 :
			    printf("Entrez un sommet (la cle) :\n");
                scanf("%d",&s);
                printf("Donner son etiquette :\n");
                scanf("%s",e);
                printf("Voici le sommet considere :\n");
                GrapheOriente_afficherSommet(s,e);
                printf("\n");
                break;

			case 8 :
			    printf("Entrez l'extremite initiale de l'arc :\n");
                scanf("%d",&ei);
                printf("Entrez l'extremite finale de l'arc :\n");
                scanf("%d",&ef);
                printf("Quelle est sa valeur ?\n");
                scanf("%f",&v);
                printf("Voici l'arc considere :\n");
                GrapheOriente_afficherArc(ei,ef,v);
                printf("\n");
                break;

			case 9 :
			    printf("Les differents champs du graphe :\n");
			    GrapheOriente_afficher(g);
			    printf("\n");
                break;

			case 10 :
			    printf("Entrez le point de depart pour le parcours en largeur (la cle d'un sommet) :\n");
                scanf("%d",&s);
			    printf("Parcours en largeur du graphe :\n");
			    GrapheOriente_parcoursLargeur(g,s);
			    printf("\n");
			    break;

			case 11 :
			    printf("Entrez le point de depart pour le parcours en profondeur (la cle d'un sommet) :\n");
                scanf("%d",&s);
                printf("Parcours en profondeur du graphe :\n");
			    GrapheOriente_parcoursProfondeur(g,s);
			    printf("\n");
			    break;

			case 12 :
                GrapheOriente_vider(&g);
                printf("Le graphe a ete vide.\n\n");
				break;

            default : break;
		}
	}
	while(choix!=0); /*critère d'arrêt : choix = 0*/
	return 0;
}
