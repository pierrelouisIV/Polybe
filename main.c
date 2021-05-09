#include <stdio.h>
#include "cryptage.h"
#include "decryptage.h"

int main(int argc, char **argv)
{
	//
	char m[100];
	printf("Veuillez saisir votre message a crypter en Majuscule : \n");
	scanf("%s", m);
	
	int * c = crypter(m);
	
	printf("Message chiffré : \n");
	for(int i=0; i<strlen(m); i++)
	{
		printf("%d ", c[i]);
	}
	printf("\n");
	
	//
	char chiffree[100];
	printf("Veuillez saisir un chiffree : \n");
	scanf("%s", chiffree);
	
	char * clair = decrypter(chiffree);
	printf("message décrypté : %s \n", clair);
	
	
	// libération mémoire :
	free(c);
	free(clair);
	return 0;
}
