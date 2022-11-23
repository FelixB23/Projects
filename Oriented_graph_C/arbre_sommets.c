/*
 * Auteurs: Baubriaud Félix, Dehondt Maxime
 * ALGO AVANCEE TP5 IMDS
 * Date: 02/06/2022
 * Conception détaillée des arbres pour les sommets
 */

/* Importation du fichier entête*/
#include "arbre_sommets.h"

/* Fonctions */

void ABRS_afficherElements(t_element_sommet e)
{
	printf("%d : %s",e.cle,e.valeur);  /*ligne à changer si on change le type t_element*/
}

int ABRS_compareElements(t_element_sommet e1,t_element_sommet e2)
{ /*à changer si on change le type t_element*/
	if (e1.cle > e2.cle)
		return 1;
	else
	{
		if (e1.cle == e2.cle)
			return 0;
		else
			return -1;
	}
}

void ABRS_creer(ArbreBRS *a)
{
	*a = NULL;
}

int ABRS_estVide(ArbreBRS a)
{
	return (a==NULL);
}

int ABRS_nbSommets(ArbreBRS a)
{
	if (ABRS_estVide(a))
		return 0;
	else
		return 1 + ABRS_nbSommets(ABRS_filsGauche(a)) + ABRS_nbSommets(ABRS_filsDroit(a));
}

t_element_sommet ABRS_racine(ArbreBRS a)
{
	return a->element;
}

ArbreBRS ABRS_filsGauche(ArbreBRS a)
{
	return a->filsGauche;
}

ArbreBRS ABRS_filsDroit(ArbreBRS a)
{
	return a->filsDroit;
}

ArbreBRS* ABRS_adresseFilsGauche(ArbreBRS a)
{
	return &(a->filsGauche);
	/* pas de &ABR_filsGauche(a) car fourni l'addresse d'un pointeur
	 * temporaire qui pointe vers la même chose que le filsGauche
	 * de base*/
}

ArbreBRS* ABRS_adresseFilsDroit(ArbreBRS a)
{
	return &(a->filsDroit);
}

ArbreBRS ABRS_sousArbre(ArbreBRS a, t_element_sommet e)
{
	/*variable locale*/
	ArbreBRS res;

	if (ABRS_estVide(a))
		return NULL;
	else
	{
		if (ABRS_compareElements(ABRS_racine(a),e) == 0)
			return a;
		else
		{
			res = ABRS_sousArbre(ABRS_filsGauche(a),e);
			if (ABRS_estVide(res))
				res = ABRS_sousArbre(ABRS_filsDroit(a),e);
			return res;
		}
	}
}


void ABRS_ajouterRacine(ArbreBRS *a, t_element_sommet e)
{
	/*variable locale*/
	ArbreBRS nouv;

	nouv = (NoeudS*) malloc(sizeof(NoeudS));
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

void ABRS_ajouterFilsGauche(ArbreBRS *a, ArbreBRS fg)
{
	(*a)->filsGauche = fg;
}

void ABRS_ajouterFilsDroit(ArbreBRS *a, ArbreBRS fd)
{
	(*a)->filsDroit = fd;
}

void ABRS_afficherInfixe(ArbreBRS a)
{
	if (!ABRS_estVide(a))
	{
		ABRS_afficherInfixe(ABRS_filsGauche(a));
		ABRS_afficherElements(ABRS_racine(a));
		printf("\n");
		ABRS_afficherInfixe(ABRS_filsDroit(a));
	}
}

int ABRS_profondeur(ArbreBRS a)
{
	/*variable locale*/
	int hfg,hfd;

	if (ABRS_estVide(a))
		return -1;
	else
	{
		hfg = ABRS_profondeur(ABRS_filsGauche(a));
		hfd = ABRS_profondeur(ABRS_filsDroit(a));
		if (hfg > hfd)
			return 1+hfg;
		else
			return 1+hfd;
	}
}

void ABRS_faireSimpleRotationDroite(ArbreBRS *a)
{
	/* variable locale */
	ArbreBRS temp = *a;

	*a = (*a)->filsGauche;
	temp->filsGauche = (*a)->filsDroit;
	(*a)->filsDroit = temp;
}

void ABRS_faireSimpleRotationGauche(ArbreBRS *a)
{
	/* variable locale */
	ArbreBRS temp = *a;

	*a = (*a)->filsDroit;
	temp->filsDroit = (*a)->filsGauche;
	(*a)->filsGauche = temp;
}

void ABRS_faireDoubleRotationDroite(ArbreBRS *a)
{
	/* variable locale */
	ArbreBRS ancienneTete,ancienFilsGauche;

	ancienneTete = *a;
	ancienFilsGauche = (*a)->filsGauche;
	*a = ancienFilsGauche->filsDroit;
	ancienFilsGauche->filsDroit = (*a)->filsGauche;
	ancienneTete->filsGauche = (*a)->filsDroit;
	(*a)->filsGauche = ancienFilsGauche;
	(*a)->filsDroit = ancienneTete;
}

void ABRS_faireDoubleRotationGauche(ArbreBRS *a)
{
	/* variable locale */
	ArbreBRS ancienneTete,ancienFilsDroit;

	ancienneTete = *a;
	ancienFilsDroit = ABRS_filsDroit(*a);
	*a = ABRS_filsGauche(ancienFilsDroit);
	ancienFilsDroit->filsGauche = (*a)->filsDroit;
	ancienneTete->filsDroit = (*a)->filsGauche;
	(*a)->filsDroit = ancienFilsDroit;
	(*a)->filsGauche = ancienneTete;
}

void ABRS_insererEquilibre(ArbreBRS *a, t_element_sommet e)
{
	if (ABRS_estVide(*a))
		ABRS_ajouterRacine(a,e);
	else
	{
		if (ABRS_compareElements(e,(*a)->element)<0)
		{
			ABRS_insererEquilibre(ABRS_adresseFilsGauche(*a),e);
			if ((ABRS_profondeur(ABRS_filsGauche(*a)) - ABRS_profondeur(ABRS_filsDroit(*a))) == 2)
			{
				if (ABRS_profondeur(ABRS_filsGauche(ABRS_filsGauche(*a))) > ABRS_profondeur(ABRS_filsDroit(ABRS_filsGauche(*a))))
					ABRS_faireSimpleRotationDroite(a);
				else
					ABRS_faireDoubleRotationDroite(a);
			}
		}
		else
		{
			ABRS_insererEquilibre(ABRS_adresseFilsDroit(*a),e);
			if ((ABRS_profondeur(ABRS_filsDroit(*a)) - ABRS_profondeur(ABRS_filsGauche(*a))) == 2)
			{
				if (ABRS_profondeur(ABRS_filsGauche(ABRS_filsDroit(*a))) > ABRS_profondeur(ABRS_filsDroit(ABRS_filsDroit(*a))))
					ABRS_faireSimpleRotationGauche(a);
				else
					ABRS_faireDoubleRotationGauche(a);
			}
		}
	}
}

void ABRS_insererElement(ArbreBRS *a, t_element_sommet e)
{
	if (ABRS_estVide(*a))
		ABRS_ajouterRacine(a,e);
	else
	{
		if (ABRS_compareElements(e,ABRS_racine(*a))<0)
			ABRS_insererElement(ABRS_adresseFilsGauche(*a),e);
		else
			ABRS_insererElement(ABRS_adresseFilsDroit(*a),e);
	}
}


t_element_sommet ABRS_min(ArbreBRS a)
{
	/* variable locale */
	t_element_sommet m;

	do
	{
		m = ABRS_racine(a);
		a = ABRS_filsGauche(a);
	}
	while (a != NULL);
	return m;
}

void ABRS_supprimerElement(ArbreBRS *a, t_element_sommet e)
{
	/* variables locales */
	ArbreBRS tmp;
	t_element_sommet m;

	if (!ABRS_estVide(*a))
	{
		if (ABRS_compareElements(e,ABRS_racine(*a))==0)
		{
			if (ABRS_estVide(ABRS_filsGauche(*a)) && ABRS_estVide(ABRS_filsDroit(*a)))
				ABRS_vider(a); /* cas 1 : le noeud recherche est une feuille*/
			else
			{
				if (ABRS_estVide(ABRS_filsGauche(*a)) && !ABRS_estVide(ABRS_filsDroit(*a)))
				{
					/* cas 2.a : noeud rechercher a un seul fils (le droit)*/
					tmp = *a;
					*a = ABRS_filsDroit(*a);
					free(tmp);
				}
				else
				{
					if (!ABRS_estVide(ABRS_filsGauche(*a)) && ABRS_estVide(ABRS_filsDroit(*a)))
					 /*cas 2.b : noeud rechercher a un seul fils (le gauche)*/
					{
						tmp = *a;
						*a = ABRS_filsGauche(*a);
						free(tmp);
					}
                    else
                    {
                        /*cas 3 : le noeud recherché à deux fils, on le remplace par
                        son successeur puis on supprime le successeur*/
                        m = ABRS_min(ABRS_filsDroit(*a));
                        (*a)->element = m;
                        ABRS_supprimerElement(ABRS_adresseFilsDroit(*a),m);
                    }
				}
			}
		}
        else
        {
            if (ABRS_compareElements(e , ABRS_racine(*a))<0)
                ABRS_supprimerElement(ABRS_adresseFilsGauche(*a),e);
            else
            {
                if (ABRS_compareElements(e , ABRS_racine(*a))>0)
                    ABRS_supprimerElement(ABRS_adresseFilsDroit(*a),e);
            }
        }
    }
}


int ABRS_estPresent(ArbreBRS a, t_element_sommet e)
{
    if (ABRS_estVide(a))
        return 0;
    else
    {
        if (ABRS_compareElements(ABRS_racine(a) , e)==0)
            return 1;
        else
        {
            if (ABRS_compareElements(ABRS_racine(a) , e)>0)
                return ABRS_estPresent(ABRS_filsGauche(a),e);
            else
                return ABRS_estPresent(ABRS_filsDroit(a),e);
        }
    }
}

void ABRS_vider(ArbreBRS *a)
{
    if (ABRS_estVide(ABRS_filsGauche(*a)) && ABRS_estVide(ABRS_filsDroit(*a)))
    {
        free(*a);
        *a = NULL;
    }
    else
    {
        if (!ABRS_estVide(ABRS_filsGauche(*a)))
            ABRS_vider(ABRS_adresseFilsGauche(*a));
        if (!ABRS_estVide(ABRS_filsDroit(*a)))
            ABRS_vider(ABRS_adresseFilsDroit(*a));
        free(*a);
        *a = NULL;
    }
}



