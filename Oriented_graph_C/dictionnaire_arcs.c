/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des dictionnaires pour les arcs
 */

/* Importation du fichier entête*/
#include "dictionnaire_arcs.h"

/* Déclaration des fonctions et procédures */

void Dictionnaire_Arcs_creer(Dictionnaire_Arcs *d)
{
	ABRA_creer(&((*d).couples));
	(*d).nbCouples = 0;
}

int Dictionnaire_Arcs_estVide(Dictionnaire_Arcs d)
{
	return d.nbCouples==0;
}

int Dictionnaire_Arcs_taille(Dictionnaire_Arcs d)
{
	return d.nbCouples;
}

void Dictionnaire_Arcs_ajouter(Dictionnaire_Arcs *d, t_cle_arc c, t_valeur_arc v)
{
	/* variable locale */
	t_element_arc e;
    /*à changer si on change le type t_element*/
	e.cle = c;
	e.valeur = v;
	if (!Dictionnaire_Arcs_estPresent(*d,c))
	{
		ABRA_insererElement(&((*d).couples), e);
		((*d).nbCouples)++;
	}
}

void Dictionnaire_Arcs_retirer(Dictionnaire_Arcs *d, t_cle_arc c)
{
	/* variable locale */
	t_element_arc e;
    /*à changer si on change le type t_element*/
	e.cle = c;
	if (Dictionnaire_Arcs_estPresent(*d,c))
	{
		ABRA_supprimerElement(&((*d).couples), e);
		((*d).nbCouples)--;
	}
}

int Dictionnaire_Arcs_estPresent(Dictionnaire_Arcs d, t_cle_arc c)
{
	/* variable locale */
	t_element_arc e;
    /*à changer si on change le type t_element*/
	e.cle = c;
	return ABRA_estPresent(d.couples,e);
}

void Dictionnaire_Arcs_rechercher(Dictionnaire_Arcs d, t_cle_arc c, t_valeur_arc *v)
{
	/* variables locales */
	t_element_arc e;
	ArbreBRA a;
	
	e.cle = c;
	if (Dictionnaire_Arcs_estPresent(d,c))
	{
		a = ABRA_sousArbre(d.couples,e);
		*v = a->element.valeur;
	}
}

void Dictionnaire_Arcs_afficher(Dictionnaire_Arcs d)
{
	ABRA_afficherInfixe(d.couples);
}

void Dictionnaire_Arcs_vider(Dictionnaire_Arcs *d)
{
	ABRA_vider(&((*d).couples));
	(*d).nbCouples = 0;
}

