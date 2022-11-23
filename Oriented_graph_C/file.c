/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des files
 */

/* Inclusion du fichier d'entête */
#include "file.h"

/* Declaration des fonctions et procédures*/

void File_creer(File *f)
{
	(*f).nbElements = 0;
	(*f).debut = 1;
	(*f).fin = 1;
}

int File_estVide(File f)
{
	return f.nbElements==0;
}

int File_estPleine(File f)
{
	return f.nbElements==MAX;
}

int File_taille(File f)
{
	return f.nbElements;
}

void File_enfiler(File *f, t_element elt)
{
	(*f).elements[(*f).fin] = elt;
	((*f).fin)++;
	if ((*f).fin > MAX)
		(*f).fin = 1;
	((*f).nbElements)++;
}

void File_defiler(File *f)
{
	((*f).debut)++;
	if ((*f).debut > MAX)
		(*f).debut = 1;
	((*f).nbElements)--;
}

t_element File_premierElement(File f)
{
	return f.elements[f.debut];
}
