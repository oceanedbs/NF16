#include<stdio.h>
#include <stdlib.h>
#include<string.h>

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

DicoABR *rechercherMot(Arbre* dico, char* valeur);

int supprimeMot(Arbre *dico, char* valeur);

void suggestionMots(Arbre *dico, char* souschaine, int k);

void parcours_infixe(DicoABR *mot, int k, char *souschaine);
