/*
 * Auteurs: Baubriaud F�lix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception pr�liminaire des piles et pr�/post-conditions + inclusions et structures
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
/* Pr�-condition: aucune */
/* Post-condition: p est initialis�e */

int Pile_estVide(Pile p);
/* Pr�-condition: aucune */
/* Post-condition: Renvoie 1 si p est vide, 0 sinon */

int Pile_estPleine(Pile p);
/* Pr�-condition: aucune */
/* Post-condition: Renvoie 1 si p est pleine, 0 sinon */

int Pile_taille(Pile p);
/* Pr�-condition: aucune */
/* Post-condition: Renvoie la taille de la pile */

void Pile_empiler(Pile *p, t_element elt);
/* Pr�-condition: non Pile_estPleine(p) */
/* Post-condition: elt est empil� sur p */

void Pile_depiler(Pile *p);
/* Pr�-condition: non Pile_estVide(p) */
/* Post-condition: p est d�pil�e */

t_element Pile_sommet(Pile p);
/* Pr�-condition: non Pile_estVide(p) */
/* Post-condition: Renvoie le dernier �l�ment empil� de p */

#endif

