#ifndef main_h
#define main_h

typedef struct Personne Personne;
struct Personne
{
    char nom[50];
    char prenom[50];
    char adresse[300];
    int age;
    int etudiant; // Boolean
};

#endif // !main_h

