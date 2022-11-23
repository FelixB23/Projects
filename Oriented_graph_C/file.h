/*
 * Auteurs: Baubriaud F�lix, Dehondt Maxime
 * ALGO AVANCEE IMDS
 * Date: 02/06/2022
 * Conception pr�liminaire des files et pr�/post-conditions + inclusions et structures
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
/*Pr�-condition : aucune*/
/*Post-condition : Une file est cr��e*/

int File_estVide(File f);
/*Pr�-condition : aucune*/
/*Post-condition : renvoie 1 si la file f est vide, 0 sinon*/

int File_estPleine(File f);
/*Pr�-condition : aucune*/
/*Post-condition : renvoie 1 si la file f est pleine, 0 sinon*/

int File_taille(File f);
/*Pr�-condition : aucune*/
/*Post-condition : renvoie la taille de la file f*/

void File_enfiler(File *f, t_element elt);
/*Pr�-condition : f non pleine*/
/*Post-condition : ins�re l'�l�ment elt � la fin de la file f*/

void File_defiler(File *f);
/*Pr�-condition : f non vide*/
/*Post-condition : supprime le premier �l�ment de la file f (le premier ins�r�)*/

t_element File_premierElement(File f);
/*Pr�-condition : f non vide*/
/*Post-condition : retourne le premier �l�ment de la file f (le premier ins�r�)*/


#endif

