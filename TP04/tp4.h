#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* PARTIE 1 */

typedef struct ABR {
  char *val;
  struct ABR *pere;
  struct ABR *fils_gauche;
  struct ABR *fils_droit;
} DicoABR;

typedef struct Dico { DicoABR *racine; } Arbre;

Arbre *initDico(char *valeur);

DicoABR *ajoutMot(Arbre *newArbre, char *valeur);

DicoABR *rechercherMot(DicoABR *dico, char *valeur);

int suggestionMots(Arbre *dico, char *souschaine, int k);

int supprimeMot(Arbre *dico, char *valeur);

void parcours_prefixe(DicoABR *dico);

void parcours_infixe(DicoABR *dico);

void parcours_postfixe(DicoABR *dico);

DicoABR *successeur(DicoABR *pointeur);

DicoABR *predecesseur(DicoABR *pointeur);

DicoABR *max(DicoABR *pointeur);

DicoABR *mini(DicoABR *dico);

void supprimeABRtotal(DicoABR *dico);

void printABR(DicoABR *dico, int *n);

void printABR2(DicoABR *dico, int *n);

void printABR3(DicoABR *dico, int *n, char *c);

void printABR4(DicoABR *dico, int *n, char *c);

/*PARTIE 2 */

typedef struct Car {
  char c;
  struct Car *suiv;
} Mot;

typedef struct Cellule {
  char c;
  struct Cellule *succ;
  struct Cellule *alt;
} Dico;

Dico *initDico2(Dico *dico, Mot *mot);

int rechercheMot2(Dico *dico, Mot *mot);

Dico *prefixeMot(Dico *dico, Mot *mot);

Mot *prefixeMotpointeur(Dico *dico, Mot *mot);

Dico *ajoutMot2(Mot *mot, Dico *dico);

Dico *supprimeMot2(Mot *mot, Dico *dico);

void suggestionMot2(int k, Dico *dico, Mot *mot);

Mot *creerMotChaine(char *chaine);

void print(Dico *dico, char *tab, int i, int *n);

void print2(Dico *dico, Mot *mot, int *n);

// PARTIE 3

Arbre *chargerABR(Arbre *dico);

void ajoutMotfile(char mot[]);

void remplacerMot(char correction[], char supp[]);

Arbre *verimotABR(Arbre *dico);

Arbre *veridicoABR(Arbre *dico);

Dico *chargerAL(Dico *dico);

Dico *verimotAL(Dico *dico);

void grofree(Mot *mot);

Dico *veridicoAL(Dico *dico);

void supprimeALtotal(Dico *dico);
