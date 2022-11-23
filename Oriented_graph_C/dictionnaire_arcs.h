/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception préliminaire des dictionnaires pour les arcs et pré/post-conditions + inclusions et structures
 */

#ifndef __DICTIONNAIRE_ARCS_H__
#define __DICTIONNAIRE_ARCS_H__

/* Importation des modules */
#include "arbre_arcs.h"

/* Définition de types */

typedef struct{
	ArbreBRA couples;
	int nbCouples;
} Dictionnaire_Arcs;

/* Prototype des fonctions */
void Dictionnaire_Arcs_creer(Dictionnaire_Arcs *d);
/* Pré-condition : aucune */
/* Post-condition : le dictionnaire d est initialisé à null. */

int Dictionnaire_Arcs_estVide(Dictionnaire_Arcs d);
/* Pré-condition : aucune */
/* Post-condition : retourne 1 si le dictionnaire d est vide, 0 sinon */

int Dictionnaire_Arcs_taille(Dictionnaire_Arcs d);
/* Pré-condition : aucune */
/* Post-condition : renvoie le nombre de couples du dictionnaire d*/

void Dictionnaire_Arcs_ajouter(Dictionnaire_Arcs *d, t_cle_arc c, t_valeur_arc v);
/* Pré-condition: aucune */
/* Post-condition: rajoute le couple (c,v) à d */

void Dictionnaire_Arcs_retirer(Dictionnaire_Arcs *d, t_cle_arc c);
/* Pré-condition: aucune */
/* Post-condition: supprime le couple de clé c du dictionnaire d */

int Dictionnaire_Arcs_estPresent(Dictionnaire_Arcs d, t_cle_arc c);
/* Pré-condition: aucune */
/* Post-condition: retourne 1 si la clé c est présente dans d, 0 sinon*/

void Dictionnaire_Arcs_rechercher(Dictionnaire_Arcs d, t_cle_arc c, t_valeur_arc *v);
/* Pré-condition : Dictionnaire_Arcs_estPresent(d,c) */
/* Post-condition : si la clé c est présente dans d, v contient la valeur associée à c*/

void Dictionnaire_Arcs_afficher(Dictionnaire_Arcs d);
/* Pré-condition : aucune */
/* Post-condition : affiche le dictionnaire d de manière infixe*/

void Dictionnaire_Arcs_vider(Dictionnaire_Arcs *d);
/* Pré-condition : aucune */
/* Post-condition : vide le dictionnaire d*/

#endif

