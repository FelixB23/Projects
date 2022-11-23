/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des arbres pour les arcs
 */

/* Importation du fichier entête*/
#include "arbre_arcs.h"

/* Fonctions */

void ABRA_afficherElements(t_element_arc e)
{/*ligne à changer si on change le type t_element*/
	printf("extremite initiale : %d\n",e.cle.extremiteInitiale);
    printf("extremite finale : %d\n",e.cle.extremiteFinale);
    printf("valeur : %f\n",e.valeur);
}

int ABRA_compareElements(t_element_arc e1,t_element_arc e2)
{          /*ligne à changer si on change le type t_element*/
	if (e1.cle.extremiteInitiale > e2.cle.extremiteInitiale)
		return 1;
	else
	{
		if (e1.cle.extremiteInitiale == e2.cle.extremiteInitiale && e1.cle.extremiteFinale == e2.cle.extremiteFinale)
			return 0;
		else
			return -1;
	}
}

void ABRA_creer(ArbreBRA *a)
{
	*a = NULL;
}

int ABRA_estVide(ArbreBRA a)
{
	return (a==NULL);
}

int ABRA_nbSommets(ArbreBRA a)
{
	if (ABRA_estVide(a))
		return 0;
	else
		return 1 + ABRA_nbSommets(ABRA_filsGauche(a)) + ABRA_nbSommets(ABRA_filsDroit(a));
}

t_element_arc ABRA_racine(ArbreBRA a)
{
	return a->element;
}

ArbreBRA ABRA_filsGauche(ArbreBRA a)
{
	return a->filsGauche;
}

ArbreBRA ABRA_filsDroit(ArbreBRA a)
{
	return a->filsDroit;
}

ArbreBRA* ABRA_adresseFilsGauche(ArbreBRA a)
{
	return &(a->filsGauche);
	/* pas de &ABR_filsGauche(a) car fourni l'addresse d'un pointeur
	 * temporaire qui pointe vers la même chose que le filsGauche
	 * de base*/
}

ArbreBRA* ABRA_adresseFilsDroit(ArbreBRA a)
{
	return &(a->filsDroit);
}

ArbreBRA ABRA_sousArbre(ArbreBRA a, t_element_arc e)
{
	/*variable locale*/
	ArbreBRA res;

	if (ABRA_estVide(a))
		return NULL;
	else
	{
		if (ABRA_compareElements(ABRA_racine(a),e) == 0)
			return a;
		else
		{
			res = ABRA_sousArbre(ABRA_filsGauche(a),e);
			if (ABRA_estVide(res))
				res = ABRA_sousArbre(ABRA_filsDroit(a),e);
			return res;
		}
	}
}


void ABRA_ajouterRacine(ArbreBRA *a, t_element_arc e)
{
	/*variable locale*/
	ArbreBRA nouv;

	nouv = (NoeudA*) malloc(sizeof(NoeudA));
	if (nouv == NULL)
	{
		printf("Erreur allocation.\n");
		exit(-1);
	}
	nouv->element = e;
	nouv->filsGauche = NULL;
	nouv->filsDroit = NULL;
	*a = nouv;
}

void ABRA_ajouterFilsGauche(ArbreBRA *a, ArbreBRA fg)
{
	(*a)->filsGauche = fg;
}

void ABRA_ajouterFilsDroit(ArbreBRA *a, ArbreBRA fd)
{
	(*a)->filsDroit = fd;
}

void ABRA_afficherInfixe(ArbreBRA a)
{
	if (!ABRA_estVide(a))
	{
		ABRA_afficherInfixe(ABRA_filsGauche(a));
		ABRA_afficherElements(ABRA_racine(a));
		printf("\n");
		ABRA_afficherInfixe(ABRA_filsDroit(a));
	}
}

int ABRA_profondeur(ArbreBRA a)
{
	/*variable locale*/
	int hfg,hfd;

	if (ABRA_estVide(a))
		return -1;
	else
	{
		hfg = ABRA_profondeur(ABRA_filsGauche(a));
		hfd = ABRA_profondeur(ABRA_filsDroit(a));
		if (hfg > hfd)
			return 1+hfg;
		else
			return 1+hfd;
	}
}

void ABRA_faireSimpleRotationDroite(ArbreBRA *a)
{
	/* variable locale */
	ArbreBRA temp = *a;

	*a = (*a)->filsGauche;
	temp->filsGauche = (*a)->filsDroit;
	(*a)->filsDroit = temp;
}

void ABRA_faireSimpleRotationGauche(ArbreBRA *a)
{
	/* variable locale */
	ArbreBRA temp = *a;

	*a = (*a)->filsDroit;
	temp->filsDroit = (*a)->filsGauche;
	(*a)->filsGauche = temp;
}

void ABRA_faireDoubleRotationDroite(ArbreBRA *a)
{
	/* variable locale */
	ArbreBRA ancienneTete,ancienFilsGauche;

	ancienneTete = *a;
	ancienFilsGauche = (*a)->filsGauche;
	*a = ancienFilsGauche->filsDroit;
	ancienFilsGauche->filsDroit = (*a)->filsGauche;
	ancienneTete->filsGauche = (*a)->filsDroit;
	(*a)->filsGauche = ancienFilsGauche;
	(*a)->filsDroit = ancienneTete;
}

void ABRA_faireDoubleRotationGauche(ArbreBRA *a)
{
	/* variable locale */
	ArbreBRA ancienneTete,ancienFilsDroit;

	ancienneTete = *a;
	ancienFilsDroit = ABRA_filsDroit(*a);
	*a = ABRA_filsGauche(ancienFilsDroit);
	ancienFilsDroit->filsGauche = (*a)->filsDroit;
	ancienneTete->filsDroit = (*a)->filsGauche;
	(*a)->filsDroit = ancienFilsDroit;
	(*a)->filsGauche = ancienneTete;
}

void ABRA_insererEquilibre(ArbreBRA *a, t_element_arc e)
{
	if (ABRA_estVide(*a))
		ABRA_ajouterRacine(a,e);
	else
	{
		if (ABRA_compareElements(e,(*a)->element)<0)
		{
			ABRA_insererEquilibre(ABRA_adresseFilsGauche(*a),e);
			if ((ABRA_profondeur(ABRA_filsGauche(*a)) - ABRA_profondeur(ABRA_filsDroit(*a))) == 2)
			{
				if (ABRA_profondeur(ABRA_filsGauche(ABRA_filsGauche(*a))) > ABRA_profondeur(ABRA_filsDroit(ABRA_filsGauche(*a))))
					ABRA_faireSimpleRotationDroite(a);
				else
					ABRA_faireDoubleRotationDroite(a);
			}
		}
		else
		{
			ABRA_insererEquilibre(ABRA_adresseFilsDroit(*a),e);
			if ((ABRA_profondeur(ABRA_filsDroit(*a)) - ABRA_profondeur(ABRA_filsGauche(*a))) == 2)
			{
				if (ABRA_profondeur(ABRA_filsGauche(ABRA_filsDroit(*a))) > ABRA_profondeur(ABRA_filsDroit(ABRA_filsDroit(*a))))
					ABRA_faireSimpleRotationGauche(a);
				else
					ABRA_faireDoubleRotationGauche(a);
			}
		}
	}
}

void ABRA_insererElement(ArbreBRA *a, t_element_arc e)
{
	if (ABRA_estVide(*a))
		ABRA_ajouterRacine(a,e);
	else
	{
		if (ABRA_compareElements(e,ABRA_racine(*a))<0)
			ABRA_insererElement(ABRA_adresseFilsGauche(*a),e);
		else
			ABRA_insererElement(ABRA_adresseFilsDroit(*a),e);
	}
}


t_element_arc ABRA_min(ArbreBRA a)
{
	/* variable locale */
	t_element_arc m;

	do
	{
		m = ABRA_racine(a);
		a = ABRA_filsGauche(a);
	}
	while (a != NULL);
	return m;
}

void ABRA_supprimerElement(ArbreBRA *a, t_element_arc e)
{
	/* variables locales */
	ArbreBRA tmp;
	t_element_arc m;

	if (!ABRA_estVide(*a))
	{
		if (ABRA_compareElements(e,ABRA_racine(*a))==0)
		{
			if (ABRA_estVide(ABRA_filsGauche(*a)) && ABRA_estVide(ABRA_filsDroit(*a)))
				ABRA_vider(a); /* cas 1 : le noeud recherche est une feuille*/
			else
			{
				if (ABRA_estVide(ABRA_filsGauche(*a)) && !ABRA_estVide(ABRA_filsDroit(*a)))
				{
					/* cas 2.a : noeud rechercher a un seul fils (le droit)*/
					tmp = *a;
					*a = ABRA_filsDroit(*a);
					free(tmp);
				}
				else
				{
					if (!ABRA_estVide(ABRA_filsGauche(*a)) && ABRA_estVide(ABRA_filsDroit(*a)))
					 /*cas 2.b : noeud rechercher a un seul fils (le gauche)*/
					{
						tmp = *a;
						*a = ABRA_filsGauche(*a);
						free(tmp);
					}
                    else
                    {
                        /*cas 3 : le noeud recherché à deux fils, on le remplace par
                        son successeur puis on supprime le successeur*/
                        m = ABRA_min(ABRA_filsDroit(*a));
                        (*a)->element = m;
                        ABRA_supprimerElement(ABRA_adresseFilsDroit(*a),m);
                    }
				}
			}
		}
        else
        {
            if (ABRA_compareElements(e , ABRA_racine(*a))<0)
                ABRA_supprimerElement(ABRA_adresseFilsGauche(*a),e);
            else
            {
                if (ABRA_compareElements(e , ABRA_racine(*a))>0)
                    ABRA_supprimerElement(ABRA_adresseFilsDroit(*a),e);
            }
        }
    }
}


int ABRA_estPresent(ArbreBRA a, t_element_arc e)
{
    if (ABRA_estVide(a))
        return 0;
    else
    {
        if (ABRA_compareElements(ABRA_racine(a) , e)==0)
            return 1;
        else
        {
            if (ABRA_compareElements(ABRA_racine(a) , e)>0)
                return ABRA_estPresent(ABRA_filsGauche(a),e);

            else
                return ABRA_estPresent(ABRA_filsDroit(a),e);
        }
    }
}

void ABRA_vider(ArbreBRA *a)
{
    if (ABRA_estVide(ABRA_filsGauche(*a)) && ABRA_estVide(ABRA_filsDroit(*a)))
    {
        free(*a);
        *a = NULL;
    }
    else
    {
        if (!ABRA_estVide(ABRA_filsGauche(*a)))
            ABRA_vider(ABRA_adresseFilsGauche(*a));
        if (!ABRA_estVide(ABRA_filsDroit(*a)))
            ABRA_vider(ABRA_adresseFilsDroit(*a));
        free(*a);
        *a = NULL;
    }
}
