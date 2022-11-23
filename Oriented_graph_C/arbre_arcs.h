/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception préliminaire des arbres pour les arcs et pré/post-conditions + inclusions et structures
 */

#ifndef __ARBRE_ARCS_H__
#define __ARBRE_ARCS_H__

/* Importation des modules */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structures */

typedef struct{
    int extremiteInitiale;
    int extremiteFinale;
} t_cle_arc;

typedef float t_valeur_arc;

typedef struct{
	t_cle_arc cle;
	t_valeur_arc valeur;
} t_element_arc;

typedef struct t_NoeudA{
	t_element_arc element;
	struct t_NoeudA* filsGauche;
	struct t_NoeudA* filsDroit;
} NoeudA;

typedef NoeudA* ArbreBRA ;

/* Prototypes des fonctions */

void ABRA_afficherElements(t_element_arc e);
/*Precond : e de type t_element_arc */
/*Postcond : affiche e */

int ABRA_compareElements(t_element_arc e1,t_element_arc e2);
/*Precond : e1 et e2 de type t_element_arc */
/*Postcond : renvoie 1 si e1.cle > e2.cle, O si e1.cle=e2.cle, -1 sinon*/

void ABRA_creer(ArbreBRA *a);
/*Precond: aucune */
/*Postcond: a pointe vers un arbre vide*/

int ABRA_estVide(ArbreBRA a);
/*Precond: aucune */
/*Postcond: renvoie 1 si a est vide, 0 sinon*/

int ABRA_nbSommets(ArbreBRA a);
/*Precond: aucune */
/*Postcond: renvoie le nombre de sommets de l'arbre a*/

t_element_arc ABRA_racine(ArbreBRA a);
/*Precond: non ABRA_estVide(a) */
/*Postcond: renvoie l'element au sommet de l'arbre*/

ArbreBRA ABRA_filsGauche(ArbreBRA a);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: retourne le fils gauche de a*/

ArbreBRA ABRA_filsDroit(ArbreBRA a);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: retourne le fils droit de a*/

ArbreBRA* ABRA_adresseFilsGauche(ArbreBRA a);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: retourne l'adresse du fils gauche de a*/

ArbreBRA* ABRA_adresseFilsDroit(ArbreBRA a);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: retourne l'adresse du fils droit de a*/

ArbreBRA ABRA_sousArbre(ArbreBRA a, t_element_arc e);
/*Precond: aucune*/
/*Postcond: retourne le premier sous-arbre d'élément e en partant de gauche */

void ABRA_ajouterRacine(ArbreBRA *a, t_element_arc e);
/*Precond: ABRA_estVide(a)*/
/*Postcond: a est un noeud de racine e*/

void ABRA_ajouterFilsGauche(ArbreBRA *a, ArbreBRA fg);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: ajoute le sous-arbre fg à gauche de a*/

void ABRA_ajouterFilsDroit(ArbreBRA *a, ArbreBRA fd);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: ajoute le sous-arbre fd à droite de a*/

void ABRA_afficherInfixe(ArbreBRA a);
/*Precond: aucune*/
/*Postcond: Affiche les éléments de l'arbre a de manière infixe*/

int ABRA_profondeur(ArbreBRA a);
/*Precond: aucune*/
/*Postcond: Renvoie la profondeur de l'arbre a*/

void ABRA_faireSimpleRotationDroite(ArbreBRA *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 1 fois vers la droite*/

void ABRA_faireSimpleRotationGauche(ArbreBRA *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 1 fois vers la gauche*/

void ABRA_faireDoubleRotationDroite(ArbreBRA *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 2 fois vers la droite*/

void ABRA_faireDoubleRotationGauche(ArbreBRA *a);
/*Precond: a est de la forme du modèle du cours*/
/*Postcond: a est pivoté 2 fois vers la gauche*/

void ABRA_insererEquilibre(ArbreBRA *a, t_element_arc e);
/*Precond: l'arbre a est déjà équilibré avant d'insérer l'élément e*/
/*Postcond: insère e de sorte que les profondeurs à gauche et à droite de a diffèrent au plus de 1*/

void ABRA_insererElement(ArbreBRA *a, t_element_arc e);
/*Precond: aucune*/
/*Postcond: insere l'element e à la bonne place dans l'arbre a*/

t_element_arc ABRA_min(ArbreBRA a);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: renvoie le min de a*/

void ABRA_supprimerElement(ArbreBRA *a, t_element_arc e);
/*Precond: aucune*/
/*Postcond: supprime e de a*/

int ABRA_estPresent(ArbreBRA a, t_element_arc e);
/*Precond: aucune*/
/*Postcond: renvoie 1 si a contient e, 0 sinon.*/

void ABRA_vider(ArbreBRA *a);
/*Precond: non ABRA_estVide(a)*/
/*Postcond: ABRA_estVide(a)*/
#endif

