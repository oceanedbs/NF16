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

T_Element *creerElement(char *val){
	T_Element new;
	new.valeur = val;
	new.suivant = 0;
	new.precedent = 0;
	
}

int main (){

	return 0;

}
