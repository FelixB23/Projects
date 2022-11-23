/*
 * Auteurs: Baubriaud F�lix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception pr�liminaire des gaphes orient�s et pr�/post-conditions + inclusions et structures
 */

#ifndef __GRAPHE_ORIENTE_H__
#define __GRAPHE_ORIENTE_H__

/* Importation des modules */
#include "dictionnaire_arcs.h"
#include "dictionnaire_sommets.h"
#include "file.h"
#include "pile.h"

/* D�finition de types */

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
/*Pr�-condition : aucune*/
/*Post-condition : Affiche le sommet s et son �tiquette e*/

void GrapheOriente_afficherArc(Sommet ei, Sommet ef, Valeur v);
/*Pr�-condition : aucune*/
/*Post-condition : Affiche l'arc s et sa valeur v*/

void GrapheOriente_creer(GrapheOriente *g, int M);
/*Pr�-condition : M>=1 */
/*Post-condition : g initialis�*/

int GrapheOriente_sommetPresent(GrapheOriente g, Sommet s);
/*Pr�-condition : aucune */
/*Post-condition : renvoie 1 si s est pr�sent dans g, 0 sinon*/

int GrapheOriente_arcPresent(GrapheOriente g, Sommet ei, Sommet ef);
/*Pr�-condition : aucune */
/*Post-condition : renvoie 1 si l'arc d'extremit� initiale ei et d'extremit� finale ef est pr�sent dans g, 0 sinon*/

void GrapheOriente_ajouterSommet(GrapheOriente *g, Sommet s, Etiquette e);
/*Pr�-condition : 0<=s<=M-1 */
/*Post-condition : ajoute le sommet s d'etiquette e au graphe orient� g si s n'est pas d�j� pr�sent*/

void GrapheOriente_ajouterArc(GrapheOriente *g, Sommet ei, Sommet ef, Valeur v);
/*Pr�-condition : aucune */
/*Post-condition : ajoute l'arc d'extremit� initiale ei et d'extremit� finale ef de valeur v au graphe orient� g*/
/*                 (si celui-ci n'existe pas d�j� et que les extr�mit�s existent)*/

void GrapheOriente_supprimerSommet(GrapheOriente *g, Sommet s);
/*Pr�-condition : aucune */
/*Post-condition : supprime le sommet s du graphe orient� g si celui-ci est pr�sent*/

void GrapheOriente_supprimerArc(GrapheOriente *g, Sommet ei, Sommet ef);
/*Pr�-condition : 0<=ei<=M-1 et 0<=ef<=M-1 */
/*Post-condition : supprime l'arc d'extr�mit� initiale ei et d'extremit� finale ef du graphe orient� g si celui-ci est dans le graphe*/

void GrapheOriente_afficher(GrapheOriente g);
/*Pr�-condition : aucune*/
/*Post-condition : affiche le graphe orient� g*/

void GrapheOriente_parcoursLargeur(GrapheOriente g, Sommet s);
/* Pr�-condition : 0<=s<=M-1 */
/* Post-condition : parcours le graphe orient� d en largeur*/

void GrapheOriente_parcoursProfondeur(GrapheOriente g, Sommet s);
/* Pr�-condition : 0<=s<=M-1 */
/* Post-condition : parcours le graphe orient� d en profondeur*/

void GrapheOriente_vider(GrapheOriente *g);
/* Pr�-condition : aucune */
/* Post-condition : Vide le graphe*/

#endif
