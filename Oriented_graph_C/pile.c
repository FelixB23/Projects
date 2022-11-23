/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des piles
 */

/* Importations des modules */
#include "pile.h"
#include <stdio.h>

/* Fonctions */
void Pile_creer(Pile *p)
{
	(*p).nbElements = 0;
}

int Pile_estVide(Pile p)
{
	return (p.nbElements == 0);
}

int Pile_estPleine(Pile p)
{
	return (p.nbElements == MAX);
}

int Pile_taille(Pile p)
{
	return p.nbElements;
}

void Pile_empiler(Pile *p, t_element elt)
{
	((*p).nbElements)++;
	(*p).elements[(*p).nbElements] = elt;
}

void Pile_depiler(Pile *p)
{
	((*p).nbElements)--;
}

t_element Pile_sommet(Pile p)
{
	return p.elements[p.nbElements];
}

