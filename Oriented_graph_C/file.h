/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE IMDS
 * Date: 02/06/2022
 * Conception préliminaire des files et pré/post-conditions + inclusions et structures
 */

#ifndef __FILE_H__

#define __FILE_H__

/* Importation des modules */
#include <stdio.h>

/* Constantes */
#define MAX 100

/*Definition de types */

typedef int t_element;

typedef struct{
	t_element elements[MAX];
	int nbElements;
	int debut;
	int fin;
} File;

/*Prototype des fonctions */

void File_creer(File *f);
/*Pré-condition : aucune*/
/*Post-condition : Une file est créée*/

int File_estVide(File f);
/*Pré-condition : aucune*/
/*Post-condition : renvoie 1 si la file f est vide, 0 sinon*/

int File_estPleine(File f);
/*Pré-condition : aucune*/
/*Post-condition : renvoie 1 si la file f est pleine, 0 sinon*/

int File_taille(File f);
/*Pré-condition : aucune*/
/*Post-condition : renvoie la taille de la file f*/

void File_enfiler(File *f, t_element elt);
/*Pré-condition : f non pleine*/
/*Post-condition : insère l'élément elt à la fin de la file f*/

void File_defiler(File *f);
/*Pré-condition : f non vide*/
/*Post-condition : supprime le premier élément de la file f (le premier inséré)*/

t_element File_premierElement(File f);
/*Pré-condition : f non vide*/
/*Post-condition : retourne le premier élément de la file f (le premier inséré)*/


#endif

