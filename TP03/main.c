	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	#include "TP03.h"


	int main() {
	    char* a="Hey", *c="Oooh", *e="Ahhha", *g="Bbbhh";
	    T_Element* new_elemt,*rechercher;
	    T_Liste *new_lst, *new_lst2, *fusion;
	    int b,d,f,h, suppr_elemt, suppr_lst;


	    new_elemt = creerElement(a);
	   

	    if(new_elemt != NULL){ printf("Element cree \n");}
	    else {printf("Echec cr�ation element \n");}

	    new_lst = creerListe();
	    new_lst2 = creerListe();

	    if(new_lst !=NULL){printf("Liste cree \n");}
	    else{printf("echec creation liste \n");}


	    b = insererElement(new_lst, a);
	    d = insererElement(new_lst, c);
	    f = insererElement(new_lst, e);
	    h= insererElement(new_lst2, g);

	    if(b== -1){printf("Erreur d'insertion \n");}
	    else{printf("insertion correcte \n");}

	    printf("taille liste %d \n", new_lst->taille);

	   rechercher = rechercherElement(new_lst, "Yoyo");

	    if(rechercher != NULL){
		printf("l'element %s a ete trouve \n", rechercher->valeur);
		}

		fusion=fusionnerListes(new_lst, new_lst2);
		if(fusion != NULL) {
			printf("Les listes ont ete fusionnee avec succes \n");
		}
		else{printf("Erreur lors de la fusion des listes \n");}

	    	suppr_elemt = supprimerElement(fusion, a);

		if(suppr_elemt==0){printf("L'element a ete supprime avec succes \n");}
		else{printf("Erreur dans la supression de l'element \n");}

	   new_elemt = creerElement(a);

	     b = insererElement(new_lst, a);
	     suppr_lst = supprimerListe(new_lst);

	    if(suppr_lst == 0){printf("La liste a ete supprimee avec succes\n");}
	    else{printf("Erreur lors de la suppression de la liste \n");}


	    return 0;
	}
