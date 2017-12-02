#include<stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct ABR{
  char* val;
  struct ABR* pere;
  struct ABR* fils_gauche;
  struct ABR* fils_droit;
}DicoABR;

DicoABR* initDico(char* valeur);

DicoABR* ajoutMot(DicoABR*dico, char *valeur);

DicoABR* rechercherMot(DicoABR* dico, char* valeur);

int supprimeMot(DicoABR* dico, char* valeur);

void suggestionMots(DicoABR *dico, char* souschaine, int k);

void parcours_infixe(DicoABR *mot, int k, char *souschaine);
