<h5 align="center">Learn C - Nishikoto - 24/10/2025</br>Cette page est tiré de mon apprentissage du site OpenClassrooms.com.</h5>

# Variables

```c
signed char un = 1; // compris entre -128 et .127
signed int deux = 2; // compris entre -32 768 et 32 767
signed long trois = 3; // compris entre -2 147 483 648 et 2 147 483 647

float pi = 3.14; // compris entre 1.17549 x 10^-38 et 3.40282 x 10^+38
double pi2 = 3.1415; // compris entre 2.22507 x 10^-308 et 1.79769 x 10+308^

unsigned char quatre = 4; // compris entre 0 et 255
unsigned int cinq = 5; // compris entre 0 et 65 535
unsigned long six = 6; // compris entre 0 et 4 294 967 295
```

`signed` et `unsigned` ne sont pas obligatoire.

En résumé, on utilisera le plus souvent `int` pour un nombre entier et `double` pour un nombre décimal.

### Variables static

- Dans un fichier: 
	La variable n'est disponible uniquement dans le fichier dans lequel elle est appelé.
- Dans une fonction:
	La variable n'est pas supprimé à la fin de la fonction, elle est donc gardé en mémoire et sera réécrite si la fonction est réutilisé.

# printf

La fonction ne fait pas de retour à la ligne automatiquement, il faut donc ajouter `\n` à la fin.

### Les nombres
Dans un printf on peut formater des nombres, voici les différents formats.

```c
// %d attend un type int
// %u attend un type unsigned int
// %ld attend un type long
// %f attend un type float et double
// %p attend un décimal et retourne la valeur héxadécimal de la variable (Ex: printf("%p", &maVariable))
// %c attend un caractère
// %s attend une string (chaîne de caractère)

// Exemple:
	printf("%f", 3.1415);
```

# scanf

On peu aussi utiliser `scanf_s` pour une utilisation sécuriser.

```c
int age = 0;
scanf("%d", &age);
```

Divergence entre le format printf et scanf. On utilise `%f` pour un float mais pour un double c'est `%lf`.

# Switch Case

```c
int choix = 0;

printf("---Menu---\n1. Macdonald\n2. Burger King\n3. Quick\n4. Popeyes\n\n");
scanf("%d", &choix);

switch (choix)
{
	case 1:
		printf("Vous avez choisi Macdonald!");
		break; // Obligatoire pour éviter de lire la suite des itérations
	case 2:
		printf("Vous avez choisi Burger King!");
		break;
	case 3:
		printf("Vous avez choisi Quick!");
		break;
	case 4:
		printf("Vous avez choisi Popeyes!");
		break;
	default: // Cette ligne est égal à un `else if`
		printf("Vous n'avez fait aucun choix!");
		break;
}
```

# Boucles

Différentes boucle existe;

1. while (condition) {}
     Boucle normal, s'éxecute uniquement si la condition est vraie

2. do {} while (condition);
     Boucle inversé, s'éxecute au moins une fois et boucle si la condition est vraie

3. for (initialisation; condition; incrémentation) {}
     Permet d'initialiser, de conditionner et d'incrémenter dans la même ligne. S'éxecute uniquement si la condition est vraie. 

```c
    for (int compteur = 0; compteur <= 10; compteur++)
    {
        printf("%d\n", compteur);
    }
```

# Fonctions

## Basique

Un fonction est composé de trois étapes, la première est de définir quel type la fonction va renvoyer. Si elle ne renvoie rien alors mettre `void` à la place du type. Ensuite le nom de votre fonction peut être celle que vous souhaitez tant qu'elle respecte les mêmes règles que les variables; c'est à dire, pas d'espaces, pas d'accents, pas de caractères spéciaux, etc...

```c
type nomDeMaFonction(paramètres)
{
	return 0;
}

Exemple:

int addition(int nombre1, int nombre2)
{
	return nombre1 + nombre2;
}
```

## Prototype

L'ajout d'un prototype permet à l'ordinateur de connaître une fonction peut importe ou elle se trouve dans le code. Autrement votre fonction doit toujours être appelé avant la fonction `main`.
Ne JAMAIS oublié de mettre un point-virgule à la fin d'un prototype, c'est ce qui permet à l'ordinateur de différencier une fonction d'un prototype.

```c
Exemple

#include <stdio.h>
#include <stdlib.h>

double aireRectangle(double largeur, double hauteur);

int main(int argc, char *argv[])
{
	printf("Rectangle de largeur 5 et hauteur 10. Aire = %f\n", aireRectangle(5, 10));
	return 0;
}

double aireRectangle(double largeur, double hauteur)
{
	return largeur * hauteur;
}
```

# Headers

Un header est un fichier `.h` qui permet d'enregistrer les prototypes. En général chaque header à son équivalent en `.c`.

```c
Exemple:

---Application
  📂 ↓ - sources
       🗎 - controller.c
       🗎 - main.c
  📂 ↓ - headers
       🗎 - constants.h
       🗎 - controller.h
```

Pour inclure un header dans un fichier en c, vous devez faire comme suit.

```c
#include <stdlib.h> // Lib contenu dans l'IDE
#include <stdio.h> // Lib contenu dans l'IDE
#include "controller.h" // Fichier contenant les prototypes contenu dans le repertoire du projet
```

Comme vous l'aurez compris on utilise des guillemets pour inclure une bibliothèque contenu dans le repertoire de l'app et des chevrons pour inclure une bibliothèque contenu dans notre IDE.

# Pointeurs

Créer un pointeur `int *monPointeur;`, en effet on ajoute simplement une étoile devant le nom de la variable. On peut aussi l'écrire comme ça `int* monPointeur;` mais si notre ligne contient plusieurs variable on utiliseras la première solution.

Un pointeur sert uniquement à stocker des adresses (de variable). Voici un petit exemple:

```c
int age = 10;
int* adresseDeLaVariableAge = &age;

printf("Valeur du pointeur: %p\n", adresseDeLaVariableAge);
printf("Adresse de mon pointeur: %p\n", &adresseDeLaVariableAge);
printf("Valeur de l'adresse stocker dans le pointeur: %d\n\n", *adresseDeLaVariableAge);

printf("Valeur de ma variable: %d\n", age);
printf("Adresse de ma variable: %p\n", &age);
```

# Tableaux

Créer un tableau est simple, il suffit de faire `int monTableau[4]`. Dans mon exemple mon tableau est de type `int` mais il peut être du type que l'on souhaite, après je nomme mon tableau comme je le souhaite ici ce sera `monTableau` et pour terminer je met entre les crochets le nombres de cases que je souhaite réservé pour ce tableau c'est à dire `4`.

A savoir, si vous créez un tableau de type `int`, toute les valeurs du tableau seront de type du même type.

Il faut noter qu'un tableau commence toujours par 0, c'est à dire que lorsque l'on fait un printf pour avoir la première valeur de notre tableau nous devons faire `monTableau[0]`, et dans notre cas nous pouvons aller jusqu'a `monTableau[3]`.

Pour assigner des valeurs à notre tableau nous avons plusieurs moyens, lors de la création de celui-ci `int monTableau[4] = {1, 47, 36, 5}`; après la création de celui-ci `int monTableau[4]; monTableau[1] = 1, etc...`.

Toute les valeurs non-assigné dans un tableau seront à `0`.

Voici un petit exemple complet:
```c
void afficherUnTableau(int *tableau, int tailleDuTableau); // *tableau peut être écrit comme ça: tableau[].

void main()
{
	int monTableau[4] = {1, 47, 36};
	afficherUnTableau(monTableau, 4);

	return 0;
}

void afficherUnTableau(int *tableau, int tailleDuTableau)
{
	int i;

	for (i = 0; i < tailleDuTableau; i++)
	{
		printf("%d\n", tableau[i]);
	}
}
```

# Chaîne de caractère

`strlen` pour calculer la longueur d'une chaîne

`strcpy` pour copier une chaîne dans une autre

`strcat` pour concaténer 2 chaînes

`strcmp` pour comparer 2 chaînes

`strchr` pour rechercher un caractère

`strpbrk` pour rechercher le premier caractère de la liste

`strstr` pour rechercher une chaîne dans une autre

`sprintf` pour écrire dans une chaîne

# Constante de préprocesseur

Une constante de préprocesseur est simplement une variable défini par `#define` en haut de notre fichier `.c`. La différence entre les variables de préprocesseur et les variables normal c'est que les variables de préprocesseur ne prennent pas de place en mémmoire, c'est-à-dire qu'elles sont remplacées directement lors de la compilation du programme.

On peut également faire des petites opérations dans le code via ces variables. `+ - * % /`. Attention de mettre l'opération entre parenthèse!

Nous avons aussi des constantes prédéfinnie par le préprocesseur, les voici:

```c
__LINE__ // permet de récup le numéro de la ligne actuelle
__FILE__ // permet de récup le nom du fichier actuel
__DATE__ // permet de récup la date de la compilation
__TIME__ // permet de récup l'heure de la compilation
```

On peut aussi définir une constante vide `#define maConstanteVide`.

## Macro

On peut créer une macro comme ceci: `#define maMacro() printf("Coucou toi!");`, on peut évidement créer plusieurs ligne par macro en utilisant le caractère `\`, voici un exemple:

```c
#define maMacro() printf("Coucou toi!\n"); \
                  printf("Comment ça va?\n"); \
                  printf("Au revoir!\n");)

void main()
{
	maMacro()
	return 0;
}
```

Attention, à ne pas confondre avec les slashs `/`!
À noter, le point virgule n'est pas obligatoire à la fin de l'appel d'une macro.

Une Macro peut aussi prendre des paramètres et faire à peu près les mêmes choses qu'une fonction.

```c
#define majeur(age) if (age >= 18) \
                         printf("Vous êtes majeur!\n"); \
                    else \
                         printf("Vous êtes mineur!\n"); \
					
void main()
{
	majeur(20)
	return 0;
}
````

On peut ajouter des accolades aussi!

# Conditions en préprocesseur

On peut faire des conditions en préprocesseur en utilisant `#if`, `#elif` et `#endif`. Attention, si la condition est vraie alors elle sera écrite dans le fichier lors de la compilation autrement elle n'apparaîtra juste pas.

Exemple:
```c
#if 1
	printf("Cette ligne sera toujours affichée!\n");
#elif 
	printf("Cette ligne ne sera jamais affichée!\n");
#endif
```

J'ai écrit plus haut que l'on pouvait définir des constantes de préprocesseur vide, on va maintenant voir à quoi elle peuvent nous servir. On va donc imaginer que l'on souhaite faire un programme multiplateformes.

```c
#define WINDOWS

#ifdef WINDOWS
	printf("Programme pour Windows!\n");
#endif

#ifdef LINUX
	printf("Programme pour Linux!\n");
#endif

#ifdef MAC
	printf("Programme pour Mac!\n");
#endif
```

Mainteanant que l'on connait tout ça, on peut ajouter une petite sécurité pour éviter qu'un fichier `.h` soit inclu plusieurs fois.
I faut donc faire comme ceci dans tout nos fichiers `.h`:

```c
#ifndef MON_HEADER_H
#define MON_HEADER_H

// code du header (.h)

#endif
```

# Structures

Une structure permet de regrouper plusieurs variables sous un même nom. Voici comment en construire une:

```c
struct Coordonnees
{
	int x;
	int y;
};
```

Attention une structure doit ABSOLUMENT se terminer par un point-virgule et être composer d'au moins deux variables.

On peut aussi ajouter des tableaux dans nos structures.

```c
struct Personne
{
	char nom[50];
	char prenom[50];
	char adresse[300];
	int age;
	int etudiant; // Boolean
};
```

Maintenant il faut savoir s'en servir, voici comment:

```c
#include "main.h"  

void main(int argc, char* argv[]) // équivalent à main()  
{  
	struct Personne utilisateur[2] = {0};

	strcpy(utilisateur[0].prenom, "Nishi");
	strcpy(utilisateur[0].nom, "Koto");
	utilisateur[0].age = 22;
	strcpy(utilisateur[0].adresse, "123 Rue de la paix, Tokyo");
	utilisateur[0].etudiant = 0;

	strcpy(utilisateur[1].prenom, "Evian");
	strcpy(utilisateur[1].nom, "Off");
	utilisateur[1].age = 18;
	strcpy(utilisateur[1].adresse, "123 Rue de la cathedrale, Sfax");
	utilisateur[1].etudiant = 1;

  return 0;  
}
```

Comme vous pouvez le voir nous déclarons un tableau de structure `utilisateur` qui contient deux `Personne`. Mais cela devrais être redondant à force de réecrire `struct MaStructure;` à chaque structure, c'est pour cela qu'il existe `typedef`; il nous permet simplement de créer un alias pour notre structure, voici comment l'écrire:

`Dans notre fichier header (.h)`
```c
typedef struct Personne Personne;
struct Personne
{
	char nom[50];
	char prenom[50];
	char adresse[300];
	int age;
	int etudiant; // Boolean
};
```

Donc nous utilisons le type `typedef` pour définir un alias suivi de `struct Personne` pour définir un alias de la structure `Personne` et pour terminer le nom de notre alias.

## Utilisation des pointeurs avec les structures

Reprenons l'exemple de la structure Coordonnees et envoyons la dans une fonction via un pointeur.

`main.h`
```c
#ifndef MAIN_H
#define MAIN_H

typedef struct Coordonnees Coordonnees;
struct Coordonnees
{
	int x;
	int y;
};

void initialiserCoordonnees(Coordonnees* point);

#endif // MAIN_H
```

`main.c`
```c
#include "main.h"

void main()
{
	Coordonnees monPoint;

	initialiserCoordonnees(&monPoint);
}

void initialiserCoordonnees(Coordonnees* point)
{
	(*point).x = 10;
	(*point).y = 20;
}
```

Dans notre exemple, je crée une variable `monPoint` de type `Coordonnees`. Ensuite j'appelle la focntion `initialiserCoordonnees` contenant le paramère `point` qui attend un pointeur. Pour modifier le pointeur je met entre parenthèse `*point` pour que l'ordinateur comprenne que je veux prendre `*point` et non juste `point` et je peux donc modifier mes valeurs. (Compliqué... Oui... Un peu...)

On peut aussi utiliser l'opérateur `->` pour simplifier l'écriture. Exemple:

```c
void initialiserCoordonnees(Coordonnees* point)
{
	point->x = 10;
	point->y = 20;
}
```

Mais il faut savoir que c'est STRICTEMENT équivalent à l'écriture avec les parenthèses!

# Enum

Une énumération permet de créer des constantes entières plus lisible. Voici comment en créer une:

```c
typedef enum Volume Volume;
enum Volume
{
	FAIBLE,
	MOYEN,
	FORT
};
```

On utilise aussi un `typedef` pour définir un alias pour notre énumération.

Automatiquement une enum commence à 0 et incrémente de 1. Donc dans notre exemple `FAIBLE` vaut `0`, `MOYEN` vaut `1` et `FORT` vaut `2`. On peut aussi définir la valeur que l'on souhaite pour chaque élément.

```c
enum Volume
{
	FAIBLE = 10,
	MOYEN = 50,
	FORT
};
```

Comme on peut le voir ici je n'ai rien ajouté à `FORT` et donc il prendra la valeur de `MOYEN + 1`, c'est à dire `51`.

Grace à ça on pourra écrire de manière lisible dans notre code.

```c
if (musique == FORT)
{
	printf("La musique est trop forte!\n");
}
```