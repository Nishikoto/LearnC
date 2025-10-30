<h5 align="center">Learn C - Nishikoto</br>Créer le 24/10/2025 - Modifié le 28/10/2025</br>Cette page est tiré de mon apprentissage du site OpenClassrooms.com.</br>PS: Désoler pour les fautes d'orthographes!</h5>

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

# Manipulation de fichiers

Pour appeler un fichier on utilise la structure `FILE` qui se trouve dans notre préprocesseur `stdio.h`.

`FILE* fopen(const char* nomDuFichier, const char* modeOuverture); // Prototype de la fonction qui permet d'ouvrir un fichier`

Attention à ne pas modifié la structure `FILE` directement car elle sera différente selon les systèmes d'exploitation. Par exemple nous ne ferons jamais `fichier.element`.

Lorsque l'on créer une variable de type `FILE` on doit toujours le faire avec un pointeur et l'initialiser à `NULL`!

Les modalitées d'ouverture sont les suivantes:

- `r` : **Lecture seule**, permet de lire le fichier et le fichier doit exister.
- `w` : **Ecriture seule**, permet seulement d'écrire dans le fichier, si le fichier n'éxiste pas il sera créé.
- `a` : **Mode d'ajout**, permet d'ajouter du texte à la fin du fichier, si le fichier n'éxiste pas il sera créé.
- `a+` : **Ajout en lecture/écriture à la fin**, permet de lire et d'ajouter du texte à la fin du fichier, si le fichier n'éxiste pas il sera créé.
- `r+` : **Lecture/écriture**, permet de lire et d'écrire dans le fichier, le fichier doit exister.
- `w+` : **Ecriture/lecture, avec suppression du contenu au préalable**, permet de d'abord vider le fichier puis d'écrire dedans et ensuite de le lire, si le fichier n'éxiste pas il sera créé.

Le fichier doit toujours être dans le même répertoire que l'executable de notre programme. On peut toujours le mettre dans un sous-dossier. On peut aussi ouvrir n'importe quel fichier présent dans nos disques dur en faisant ça:

`fichier = fopen("C:\\Program Files\\Notepad++\\readme.txt", "r+");`

Dans mon exemple j'utilise des doubles antislashs `\\` car un simple antislash `\` est un caractère d'échappement en C.

Le problème avec les chemins asolus (oui c'est comme ça qu'on dit) c'est que le programme ne saura pas trouver le fichier si il est exécuté sur un autre système d'exploitation, tel que Linux. C'est pour cela qu'il est préférable d'utiliser des chemins relatifs.

Aprèsn avoir terminer de modifié notre fichier, il faut toujours le fermer avec la fonction `fclose`.

```c
// Prototype:
int fclose(FILE* pointeurSurFicheir);
```

Voici un petit exemple complet:

```c
#include <stdio.h>

void main()
{
	FILE *fichier = NULL;

	fichier = fopen("monFichier.txt", "w+"); // fopen_s(&fichier, "test.txt", "+r");

	if (fichier != NULL)
	{
		// Suite du code

		fclose(fichier);
	}
	else
	{
		printf("Erreur lors de l'ouverture du fichier!\n");
	}
}
```

Il faut toujours penser à fermer son fichier après les modifications pour permettre de libérer de la mémoire. Si vous oubliez de libéré la mémoire sur de gros programmes vous vous heurterez surement à des fuites de mémoire. Attention donc à bien vérifier vos codes avant de les lancé.

Nous allons voir maintenant comment écrire dans un fichier. Pour cela nous allons utiliser différentes fonctions:

```c
fputc // Pour écrire un seul caractère à la fois
fputs // Pour écrire une chaîne de caractère
fprintf // Pour écrire une chaîne formatées
```

## fputc

```c
// Prototype:

int fputc(int caractere, FILE* pointeurSurFichier);
```

Ici `fputc` retourn un entier, si l'écriture s'est mal passée il retourne `EOF` (End Of File) sinon il retourne autre chose. Ensuite le premier paramètre est un `int` et le deuxième paramètre est le pointeur de notre fichier qui a comment type `FILE`.

## fputs

```c
// Prototype:

int fputs(const char* chaine, FILE* pointeurSurFichier);
```

Ici `fputs` retourne aussi un entier, si l'écriture s'est mal passée il retourne `EOF` (End Of File) sinon il retourne autre chose. Ensuite le premier paramètre est une chaîne (tableau quoi) de caractère et le deuxième paramètre est le pointeur de notre fichier qui a comment type `FILE`.

## fprintf

```c
// Prototype:
int fprintf(FILE* pointeurSurFichier, const char* format, ...);
```

Ici `fprintf` retourne toujours un entier, si l'écriture s'est mal passée il retourne `EOF` (End Of File) sinon il retourne autre chose. Ensuite le premier paramètre est le pointeur de notre fichier qui a comment type `FILE`, le deuxième paramètre est une chaîne de format et le reste des paramètres sont les variables à insérer dans la chaîne de format.

## fgetc

```c
// Prototype:
int fgetc(FILE* pointeurDeFichier);
```

Ici `fgetc` retourne un entier qui correspond au caractère lu, si la fonction n'a pas pu lire le caractère elle retourna `OEF`. Le paramètre est le pointeur de notre fichier qui a comme type `FILE`.
A noté que le caractère retourné est la ou le curseur du fichier se trouve, imaginons que l'on souhaite lire `Bonjour!` alors on appel notre fonction `fgetc` qui nous retourneras `B` et si nous rappelons la même fonction alors cette fois-ci elle nous retournera `o`, vous me suivez?

## fgets

```c
// Prototype:
char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);
```

Ici `fgets` retourne une chaîne de caractère (un pointeur vers un tableau de caractères) qui correspond à la chaîne lue, si la fonction n'a pas pu lire la chaîne elle retourna `NULL`. Le premier paramètre est un pointeur vers une chaîne de caractère (tableau de caractère) qui va recevoir la chaîne lue, le deuxième paramètre est le nombre de caractère à lire et le troisième paramètre est le pointeur de notre fichier qui a comme type `FILE`, si nous souhaitons lire le clavier (ce qui est possible) nous devons mettre `stdin` comme dernier paramètre.

Comme le prototype nous explique, nous avons besoin de définir la taille de notre tableau avant d'appeler la fonction `fgets` et pour cela nous pouvons faire appel à `define`.

Il faut savoir que cette fonction ne peut lire qu'une seule ligne, si on souhaite en lire plusieurs il faudra faire une boucle.

## fscanf

```c
// Prototype:
void fscanf(FILE* pointeurSurFichier, char* chaine, ...);
```

Ici `fscanf` ne retourne rien, le premier paramètre est le pointeur de notre fichier qui a comme type `FILE`, le deuxième paramètre est une chaîne de format et le reste des paramètres sont les variables où seront stockées les valeurs lues.

## Renommer un fichier

```c
int rename(const char* ancienNom, const char* nouveauNom); // Renomme un fichier
```

La fonction renvoie `0` si elle à réussie, autrement elle renvoie une valeur différente.

## Supprimer un fichier

```c
int remove(const char* fichierASupprimer); // Supprime un fichier
```

Cette fonction supprime litéralement le fichier du disque dur. Elle ne le met pas dans la corbeille! Seul des outils spécifique pourrait récupérer le fichier! Elle ne demande pas de confirmation avant de supprimer le fichier.

# Position du curseur dans un fichier

Voici les 3 fonctions qui permettent de manipuler le curseur dans un fichier.

## ftell

```c
long ftell(FILE* pointeurSurFichier); // Retourne la position actuelle du curseur dans le fichier
```

## fseek
```c
int fseek(FILE* pointeurSurFichier, long deplacement, int origine); // Permet de déplacer le curseur

// Exemple:
fseek(fichier, 2, SEEK_SET); // Déplace le curseur de 2 caractères depuis le début du fichier
fseek(fichier, -2, SEEK_END); // Déplace le curseur de 2 caractères depuis la fin du fichier
fseek(fichier, 3, SEEK_CUR); // Déplace le curseur de 3 caractères depuis la position actuelle
```

Remarquez que nous pouvons utiliser des valeurs négatives pour reculer le curseur et donc des valeurs positives pour avancer celui-ci. Comme écrit ci-dessus nous avons trois constantes préalablement défini, les voicis:

```c
SEEK_SET // Début du fichier
SEEK_END // Fin du fichier
SEEK_CUR // Position actuelle du curseur
```

Attention, si vous utilisez `fseek` pour déplacer le curseur dans un fichier ouvert en mode texte alors celle-ci peut se comporter bizarrement.

## rewind

```c
void rewind(FILE* pointeurSurFichier); // Permet de ramener le curseur au début du fichier
```

Equivalent de la fonction `fseek` avec les paramètres `0` et `SEEK_SET`.

# La fonction basique sizeof

Cette fonction directement intégré dans le language C permet de connaître la taille en octet d'un type ou d'une variable.

```c
// Exemple:

printf("Resultat: %d", sizeof(int)); // Retourne 4 sur la plupart des systèmes
```

On peut faire ça aussi sur les structures, exemple:

```c
typedef Cordonnees Coordonnees;
struct Coordonnees
{
	int x;
	int y;
};

printf("Resultat: %d octes", sizeof(Coordonnees)); // Imaginon qu'elle retourn 8 octets
```

Et maintenant avec un tableau qui a comme type ma structure:

```c
Coordonnees monTableau[100]; // Elle retournera donc 8 multiplié par le nombre de case réservé dans notre tableau donc 800 octets!
```

# Allocation dynamique

L'allocation dynamique permet de réserver de la mémoire à l'exécution du programme.

## malloc

La fonction `malloc` est utilisé pour réserver un certain nombre d'octets en mémoire.*

```c
// Prototype:
void* malloc(size_t nombreOctetsNecessaires);
```

Le paramètre est le nombre d'octets que l'on souhaite réserver dans la mémoire. La fonction retourne un pointeur de type `void` car notre fonction ne sais pas quel type elle doit retourner, elle renvoie donc un type que l'on appel `type universel`, ce qui nous permettra de déclarer nous même le type souhaité.

```c
// Exemple:

int *memoireAllouee = NULL;
memoireAlloue = malloc(sizeof(int));
```

Comme pour la gestion de fichier nous devons tester notre allocation mémoire, en gros vérifié que notre mémoire à bien été alloué. Pour cela rien de plus simple on va faire comme pour les fichiers!

```c
int main()
{
	int *memoireAllouee = NULL;
	memoireAllouee = malloc(sizeof(int));

	if (memoireAllouee == NULL)
	{
		exit(0);
	}
	
	// On peut continuer le programme normalement si la mémoire à bien été allouée

	return 0;
}
```

Dans mon exemple si la mémoire n'a pas pu être allouée alors le programme s'arrête immédiatement grace à la fonction `exit()`.

## free

La fonction `free` permet de libérer la mémoire que l'on a précédemment alloué avec `malloc`.

```c
// Prototype:
void free(void* pointeurSurMemoireAllouee);
```

La fonction `free` à juste besoin de l'adresse de la mémoire à libérer et ne retourne rien.

```c
// Exemple:

int main()
{
	int *memoireAllouee = NULL;
	memoireAlloue = malloc(sizeof(int));

	if (memoireAllouee == NULL)
	{
		exit(0);
	}
	
	// On peut continuer le programme normalement si la mémoire à bien été allouée
	free(memoireAllouee); // On libère la mémoire avant de quitter le programme

	return 0;
}
```

## Exemple d'utilisation du stockage dymamique avec un tableau

On va demander combien d'amis à l'utilisateur et leurs ages.

```c
void main()
{
	int nombreAmis = 0, i = O;
	int *AgeAmis = NULL;

	printf("Combien d'amis avez-vous?\n");
	scanf("%d", &nombreAmis);

	if (nombreAmis > 0)
	{
		ageAmis = malloc(sizeof(int) * nombreAmis);

		if (ageAmis == NULL)
		{
			exit(0);
		}

		for (i = 0; i < nombreAmis; i++)
		{
			printf("Quel âge a votre ami numéro %d?\n", i + 1);
			scanf("%d", &ageAmis[i]);
		}

		for (i = 0; i < nombreAmis; i++)
		{
			printf("Votre ami numéro %d a %d an(s).\n", i + 1, ageAmis[i]);
		}
	
		free(ageAmis);
	}

	return 0;
}
```