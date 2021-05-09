#include <stdio.h>
#include "cryptage.h"

// var globales :
#define ZERO 0
#define l_carre 26

// valeur des caractères en MAJ :
char T[26] = {0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A,
		 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54,
		 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A};
		 
// Tableau de substitution du carre de Polybe :
int S[26] = {11, 12, 13, 14, 15, 21, 22, 23, 24, 25, 31, 32, 33, 34, 35,
	     41, 42, 43, 44, 45, 51, 52, 52, 53, 54, 55};


//
int recherche_dichotomique(int val, int borne_inf, int borne_sup)
{
	int val_milieu;
	if(borne_inf > borne_sup)
	{
		printf("Erreur recherche \n");
		return -1;
	}
	else
	{
		val_milieu = (borne_inf+borne_sup)/2;
		if(val == T[val_milieu]) return val_milieu;
		else
		{
			if(val < T[val_milieu]) return recherche_dichotomique(val, borne_inf, val_milieu--);
			else return recherche_dichotomique(val, val_milieu++, borne_sup);
		}
	}
}

//
int* crypter(char * message)
{
	int * chiffree = malloc(sizeof(int) * strlen(message));
	int res = -1;
	for(int i=0; i<strlen(message); ++i)
	{
		res = recherche_dichotomique(message[i], ZERO, l_carre);
		chiffree[i] = S[res];
	}
	return chiffree;
}


