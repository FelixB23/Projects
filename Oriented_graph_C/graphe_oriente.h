/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception préliminaire des gaphes orientés et pré/post-conditions + inclusions et structures
 */

#ifndef __GRAPHE_ORIENTE_H__
#define __GRAPHE_ORIENTE_H__

/* Importation des modules */
#include "dictionnaire_arcs.h"
#include "dictionnaire_sommets.h"
#include "file.h"
#include "pile.h"

/* Définition de types */

typedef int Sommet;

typedef char Etiquette[21];

typedef float Valeur;

typedef struct{
    int M;
    Sommet** mAdjacence;
    Dictionnaire_Sommets ds;
    Dictionnaire_Arcs da;
} GrapheOriente;

/* Prototype des fonctions */
void GrapheOriente_afficherSommet(Sommet s, Etiquette e);
/*Pré-condition : aucune*/
/*Post-condition : Affiche le sommet s et son étiquette e*/

void GrapheOriente_afficherArc(Sommet ei, Sommet ef, Valeur v);
/*Pré-condition : aucune*/
/*Post-condition : Affiche l'arc s et sa valeur v*/

void GrapheOriente_creer(GrapheOriente *g, int M);
/*Pré-condition : M>=1 */
/*Post-condition : g initialisé*/

int GrapheOriente_sommetPresent(GrapheOriente g, Sommet s);
/*Pré-condition : aucune */
/*Post-condition : renvoie 1 si s est présent dans g, 0 sinon*/

int GrapheOriente_arcPresent(GrapheOriente g, Sommet ei, Sommet ef);
/*Pré-condition : aucune */
/*Post-condition : renvoie 1 si l'arc d'extremité initiale ei et d'extremité finale ef est présent dans g, 0 sinon*/

void GrapheOriente_ajouterSommet(GrapheOriente *g, Sommet s, Etiquette e);
/*Pré-condition : 0<=s<=M-1 */
/*Post-condition : ajoute le sommet s d'etiquette e au graphe orienté g si s n'est pas déjà présent*/

void GrapheOriente_ajouterArc(GrapheOriente *g, Sommet ei, Sommet ef, Valeur v);
/*Pré-condition : aucune */
/*Post-condition : ajoute l'arc d'extremité initiale ei et d'extremité finale ef de valeur v au graphe orienté g*/
/*                 (si celui-ci n'existe pas déjà et que les extrémités existent)*/

void GrapheOriente_supprimerSommet(GrapheOriente *g, Sommet s);
/*Pré-condition : aucune */
/*Post-condition : supprime le sommet s du graphe orienté g si celui-ci est présent*/

void GrapheOriente_supprimerArc(GrapheOriente *g, Sommet ei, Sommet ef);
/*Pré-condition : 0<=ei<=M-1 et 0<=ef<=M-1 */
/*Post-condition : supprime l'arc d'extrémité initiale ei et d'extremité finale ef du graphe orienté g si celui-ci est dans le graphe*/

void GrapheOriente_afficher(GrapheOriente g);
/*Pré-condition : aucune*/
/*Post-condition : affiche le graphe orienté g*/

void GrapheOriente_parcoursLargeur(GrapheOriente g, Sommet s);
/* Pré-condition : 0<=s<=M-1 */
/* Post-condition : parcours le graphe orienté d en largeur*/

void GrapheOriente_parcoursProfondeur(GrapheOriente g, Sommet s);
/* Pré-condition : 0<=s<=M-1 */
/* Post-condition : parcours le graphe orienté d en profondeur*/

void GrapheOriente_vider(GrapheOriente *g);
/* Pré-condition : aucune */
/* Post-condition : Vide le graphe*/

#endif
