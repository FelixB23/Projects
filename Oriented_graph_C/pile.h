/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception préliminaire des piles et pré/post-conditions + inclusions et structures
 */

#ifndef __PILE_H__
#define __PILE_H__

/* Constantes */
#define MAX 100

/* Structures */
typedef int t_element;

typedef struct{
	t_element elements[MAX];
	int nbElements;
} Pile;

/* Prototypes des fonctions */

void Pile_creer(Pile *p);
/* Pré-condition: aucune */
/* Post-condition: p est initialisée */

int Pile_estVide(Pile p);
/* Pré-condition: aucune */
/* Post-condition: Renvoie 1 si p est vide, 0 sinon */

int Pile_estPleine(Pile p);
/* Pré-condition: aucune */
/* Post-condition: Renvoie 1 si p est pleine, 0 sinon */

int Pile_taille(Pile p);
/* Pré-condition: aucune */
/* Post-condition: Renvoie la taille de la pile */

void Pile_empiler(Pile *p, t_element elt);
/* Pré-condition: non Pile_estPleine(p) */
/* Post-condition: elt est empilé sur p */

void Pile_depiler(Pile *p);
/* Pré-condition: non Pile_estVide(p) */
/* Post-condition: p est dépilée */

t_element Pile_sommet(Pile p);
/* Pré-condition: non Pile_estVide(p) */
/* Post-condition: Renvoie le dernier élément empilé de p */

#endif

