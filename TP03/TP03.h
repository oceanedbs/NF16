#include<stdio.h>
#include<stdlib.h>


struct Element {
	char valeur[20];
	struct Element* suivant;
	struct Element* precedent;

};

typedef struct Element T_Element;

struct Liste{
	int taille;
	struct Element* tete;
	struct Element* queue;

};


typedef struct Liste T_Liste;

T_Element *creerElement(char *val);


T_Liste *creerListe();

int insererElement(T_Liste *list, char *val);


T_Element *rechercherElement(T_Liste *list, char *val);


int supprimerElement(T_Liste *list, char *val);


 int supprimerListe(T_Liste *list);



 T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2);

