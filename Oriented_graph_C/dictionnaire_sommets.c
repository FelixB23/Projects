/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des dictionnaires pour les sommets
 */

/* Importation du fichier entête*/
#include "dictionnaire_sommets.h"

/* Déclaration des fonctions et procédures */

void Dictionnaire_Sommets_creer(Dictionnaire_Sommets *d)
{
	ABRS_creer(&((*d).couples));
	(*d).nbCouples = 0;
}

int Dictionnaire_Sommets_estVide(Dictionnaire_Sommets d)
{
	return d.nbCouples==0;
}

int Dictionnaire_Sommets_taille(Dictionnaire_Sommets d)
{
	return d.nbCouples;
}

void Dictionnaire_Sommets_ajouter(Dictionnaire_Sommets *d, t_cle_sommet c, t_valeur_sommet v)
{
	/* variable locale */
	t_element_sommet e;
/*lignes à changer si on change le type t_element*/
	e.cle = c;
	strcpy(e.valeur,v);
	if (!Dictionnaire_Sommets_estPresent(*d,c))
	{
		ABRS_insererElement(&((*d).couples), e);
		((*d).nbCouples)++;
	}
}

void Dictionnaire_Sommets_retirer(Dictionnaire_Sommets *d, t_cle_sommet c)
{
	/* variable locale */
	t_element_sommet e;
    /*ligne à changer si on change le type t_element*/
	e.cle = c;
	if (Dictionnaire_Sommets_estPresent(*d,c))
	{
		ABRS_supprimerElement(&((*d).couples), e);
		((*d).nbCouples)--;
	}
}

int Dictionnaire_Sommets_estPresent(Dictionnaire_Sommets d, t_cle_sommet c)
{
	/* variable locale */
	t_element_sommet e;
    /*ligne à changer si on change le type t_element*/
	e.cle = c;
	return ABRS_estPresent(d.couples,e);
}

void Dictionnaire_Sommets_rechercher(Dictionnaire_Sommets d, t_cle_sommet c, t_valeur_sommet *v)
{
	/* variables locales */
	t_element_sommet e;
	ArbreBRS a;
	
	e.cle = c;
	if (Dictionnaire_Sommets_estPresent(d,c))
	{
		a = ABRS_sousArbre(d.couples,e);
		strcpy(*v,a->element.valeur);
	}
}

void Dictionnaire_Sommets_afficher(Dictionnaire_Sommets d)
{
	ABRS_afficherInfixe(d.couples);
}

void Dictionnaire_Sommets_vider(Dictionnaire_Sommets *d)
{
	ABRS_vider(&((*d).couples));
	(*d).nbCouples = 0;
}

