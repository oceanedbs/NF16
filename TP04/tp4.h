#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>


/* PARTIE 1 */

typedef struct ABR{
  char* val;
  struct ABR* pere;
  struct ABR* fils_gauche;
  struct ABR* fils_droit;
}DicoABR;

typedef struct Dico{
  DicoABR *racine;
}Arbre;

Arbre* initDico(char* valeur);

DicoABR *ajoutMot(Arbre *newArbre, char *valeur);

DicoABR *rechercherMot(DicoABR* dico, char* valeur);

DicoABR* mini(DicoABR* dico);

int supprimeMot(Arbre *dico, char* valeur);

int suggestionMots(Arbre *dico, char* souschaine, int k);

void parcours_infixe(DicoABR *mot);

/*PARTIE 2 */

typedef struct Car{
  char c;
  struct Car *suiv;
}Mot;

typedef struct Cellule{
  char c;
  struct Cellule* succ;
  struct Cellule* alt;
}Dico;
//Dico n'est pas un ABR, car il n'est pas binaire, et que son clé[fils[x]] peut être plus grande que clé[x]

Mot* creerMotChaine(char *chaine);

Dico *initDico2(Dico *dico, Mot *mot);

Dico *prefixeMot(Dico *dico, Mot *mot);

Mot *prefixeMotpointeur(Dico *dico, Mot *mot);

int rechercheMot2(Dico *dico, Mot *mot);

Dico *ajoutMot2(Mot *mot, Dico *dico);

Mot* creerMot();

void print2(Dico* dico, Mot* mot,int* n);


// PARTIE 3


Arbre* chargerABR(Arbre* dico);


void printABR(DicoABR *dico, int* n);
