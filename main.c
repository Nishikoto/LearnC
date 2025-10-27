#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
//#include "nishi.h"  
#include "main.h"  

void main(int argc, char* argv[]) // équivalent à main()  
{  
	Personne utilisateur[2] = {0};

	strcpy_s(utilisateur[0].prenom, sizeof(utilisateur[0].prenom), "Nishi");
	strcpy_s(utilisateur[0].nom, sizeof(utilisateur[0].nom), "Koto");
	utilisateur[0].age = 22;
	strcpy_s(utilisateur[0].adresse, sizeof(utilisateur[0].adresse), "123 Rue de la paix, Tokyo");
	utilisateur[0].etudiant = 0;

	strcpy_s(utilisateur[1].prenom, sizeof(utilisateur[0].prenom), "Evian");
	strcpy_s(utilisateur[1].nom, sizeof(utilisateur[0].nom), "Off");
	utilisateur[1].age = 18;
	strcpy_s(utilisateur[1].adresse, sizeof(utilisateur[0].adresse), "123 Rue de la cathedrale, Sfax");
	utilisateur[1].etudiant = 1;

	for (int i = 0; i < 2; i++)
	{
		printf("%s\n", utilisateur[i].nom);
		printf("%s\n", utilisateur[i].prenom);
		printf("%d\n", utilisateur[i].age);
		printf("%s\n", utilisateur[i].adresse);
		
		if (utilisateur[i].etudiant)
		{
			printf("L'utilisateur %s est étudiant.\n", utilisateur[i].prenom);
		}
		else
		{
			printf("L'utilisateur %s n'est pas étudiant!\n", utilisateur[i].prenom);
		}
	}

  return 0;  
}