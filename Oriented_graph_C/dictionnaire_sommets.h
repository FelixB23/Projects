/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception préliminaire des dictionnaires pour les sommets et pré/post-conditions + inclusions et structures
 */

#ifndef __DICTIONNAIRE_SOMMETS_H__
#define __DICTIONNAIRE_SOMMETS_H__

/* Importation des modules */
#include "arbre_sommets.h"
#include <string.h>

/* Définition de types */

typedef struct{
	ArbreBRS couples;
	int nbCouples;
} Dictionnaire_Sommets;

/* Prototype des fonctions */
void Dictionnaire_Sommets_creer(Dictionnaire_Sommets *d);
/* Pré-condition : aucune */
/* Post-condition : le dictionnaire d est initialisé à null. */

int Dictionnaire_Sommets_estVide(Dictionnaire_Sommets d);
/* Pré-condition : aucune */
/* Post-condition : retourne 1 si le dictionnaire d est vide, 0 sinon */

int Dictionnaire_Sommets_taille(Dictionnaire_Sommets d);
/* Pré-condition : aucune */
/* Post-condition : renvoie le nombre de couples du dictionnaire d*/

void Dictionnaire_Sommets_ajouter(Dictionnaire_Sommets *d, t_cle_sommet c, t_valeur_sommet v);
/* Pré-condition: aucune */
/* Post-condition: rajoute le couple (c,v) à d */

void Dictionnaire_Sommets_retirer(Dictionnaire_Sommets *d, t_cle_sommet c);
/* Pré-condition: aucune */
/* Post-condition: supprime le couple de clé c du dictionnaire d */

int Dictionnaire_Sommets_estPresent(Dictionnaire_Sommets d, t_cle_sommet c);
/* Pré-condition: aucune */
/* Post-condition: retourne 1 si la clé c est présente dans d, 0 sinon*/

void Dictionnaire_Sommets_rechercher(Dictionnaire_Sommets d, t_cle_sommet c, t_valeur_sommet *v);
/* Pré-condition : Dictionnaire_Sommets_estPresent(d,c) */
/* Post-condition : si la clé c est présente dans d, v contient la valeur associée à c*/

void Dictionnaire_Sommets_afficher(Dictionnaire_Sommets d);
/* Pré-condition : aucune */
/* Post-condition : affiche le dictionnaire d de manière infixe*/

void Dictionnaire_Sommets_vider(Dictionnaire_Sommets *d);
/* Pré-condition : aucune */
/* Post-condition : vide le dictionnaire d*/

#endif

