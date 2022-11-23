/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception préliminaire des arbres pour les sommets et pré/post-conditions + inclusions et structures
 */

#ifndef __ARBRE_SOMMETS_H__

#define __ARBRE_SOMMETS_H__

/* Importation des modules */
#include <stdio.h>
#include <stdlib.h>

/* Structures */

typedef char t_valeur_sommet[21]; /* Etiquette */

typedef int t_cle_sommet;

typedef struct{
	t_cle_sommet cle;
	t_valeur_sommet valeur;
} t_element_sommet;

typedef struct t_NoeudS{
	t_element_sommet element;
	struct t_NoeudS* filsGauche;
	struct t_NoeudS* filsDroit;
} NoeudS;

typedef NoeudS* ArbreBRS ;

/* Prototypes des fonctions */

void ABRS_afficherElements(t_element_sommet e);
/*Precond : e de type t_element_sommet */
/*Postcond : affiche e */

int ABRS_compareElements(t_element_sommet e1,t_element_sommet e2);
/*Precond : e1 et e2 de type t_element_sommet */
/*Postcond : renvoie 1 si e1.cle > e2.cle, O si e1.cle=e2.cle, -1 sinon*/

void ABRS_creer(ArbreBRS *a);
/*Precond: aucune */
/*Postcond: a pointe vers un arbre vide*/

int ABRS_estVide(ArbreBRS a);
/*Precond: aucune */
/*Postcond: renvoie 1 si a est vide, 0 sinon*/

int ABRS_nbSommets(ArbreBRS a);
/*Precond: aucune */
/*Postcond: renvoie le nombre de sommets de l'arbre a*/

t_element_sommet ABRS_racine(ArbreBRS a);
/*Precond: non ABRS_estVide(a) */
/*Postcond: renvoie l'element au sommet de l'arbre*/

ArbreBRS ABRS_filsGauche(ArbreBRS a);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: retourne le fils gauche de a*/

ArbreBRS ABRS_filsDroit(ArbreBRS a);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: retourne le fils droit de a*/

ArbreBRS* ABRS_adresseFilsGauche(ArbreBRS a);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: retourne l'adresse du fils gauche de a*/

ArbreBRS* ABRS_adresseFilsDroit(ArbreBRS a);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: retourne l'adresse du fils droit de a*/

ArbreBRS ABRS_sousArbre(ArbreBRS a, t_element_sommet e);
/*Precond: aucune*/
/*Postcond: retourne le premier sous-arbre d'élément e en partant de gauche */

void ABRS_ajouterRacine(ArbreBRS *a, t_element_sommet e);
/*Precond: ABRS_estVide(a)*/
/*Postcond: a est un noeud de racine e*/

void ABRS_ajouterFilsGauche(ArbreBRS *a, ArbreBRS fg);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: ajoute le sous-arbre fg à gauche de a*/

void ABRS_ajouterFilsDroit(ArbreBRS *a, ArbreBRS fd);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: ajoute le sous-arbre fd à droite de a*/

void ABRS_afficherInfixe(ArbreBRS a);
/*Precond: aucune*/
/*Postcond: Affiche les éléments de l'arbre a de manière infixe*/

int ABRS_profondeur(ArbreBRS a);
/*Precond: aucune*/
/*Postcond: Renvoie la profondeur de l'arbre a*/

void ABRS_faireSimpleRotationDroite(ArbreBRS *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 1 fois vers la droite*/

void ABRS_faireSimpleRotationGauche(ArbreBRS *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 1 fois vers la gauche*/

void ABRS_faireDoubleRotationDroite(ArbreBRS *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 2 fois vers la droite*/

void ABRS_faireDoubleRotationGauche(ArbreBRS *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 2 fois vers la gauche*/

void ABRS_insererEquilibre(ArbreBRS *a, t_element_sommet e);
/*Precond: l'arbre a est déjà équilibré avant d'insérer l'élément e*/
/*Postcond: insère e de sorte que les profondeurs à gauche et à droite de a diffèrent au plus de 1*/

void ABRS_insererElement(ArbreBRS *a, t_element_sommet e);
/*Precond: aucune*/
/*Postcond: insere l'element e à la bonne place dans l'arbre a*/

t_element_sommet ABRS_min(ArbreBRS a);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: renvoie le min de a*/

void ABRS_supprimerElement(ArbreBRS *a, t_element_sommet e);
/*Precond: aucune*/
/*Postcond: supprime e de a*/

int ABRS_estPresent(ArbreBRS a, t_element_sommet e);
/*Precond: aucune*/
/*Postcond: renvoie 1 si a contient e, 0 sinon.*/

void ABRS_vider(ArbreBRS *a);
/*Precond: non ABRS_estVide(a)*/
/*Postcond: ABRS_estVide(a)*/
#endif

