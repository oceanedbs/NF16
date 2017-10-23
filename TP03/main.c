#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "TP03.h"

/*				FONCTION PRGRM PRINCIPAL -> faire menu interactif (toutes les fonctions sont pretes)
1. Créer une liste
2. Ajouter un élément dans une liste
3. Supprimer un élément d’une liste
4. Rechercher un élément dans une liste
5. Afficher les éléments d’une liste
6. Supprimer une liste
7. Fusionner deux listes
8. Quitter
*/
int main() {
    char* a="Hey", *c="Oooh";
    T_Element* new_elemt,*new_elemt2, *rechercher;
    T_Liste *new_lst, *new_lst2, *fusion;
    int b,d, suppr_elemt, suppr_lst;


    new_elemt = creerElement(a);
    new_elemt2 = creerElement(c);

    if(new_elemt != NULL){ printf("Element cree \n");}
    else {printf("Echec création element \n");}

    new_lst = creerListe();
    new_lst2 = creerListe();

    if(new_lst !=NULL){printf("Liste cree \n");}
    else{printf("echec creation liste \n");}

    printf("taille liste %d \n", new_lst->taille);

    b = insererElement(new_lst, a);
    d = insererElement(new_lst, c);

    if(b== -1){printf("Erreur d'insertion \n");}
    else{printf("insertion correcte \n");}

	b = insererElement(new_lst, a);
	 if(b== -1){printf("Erreur d'insertion \n");}
    else{printf("insertion correcte \n");}

    printf("taille liste %d \n", new_lst->taille);

   rechercher = rechercherElement(new_lst, a);

    if(rechercher != NULL){
	printf("l'element a ete trouve \n");
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


/*
//VRAI MAIN :*

int main() {
int a,i=0;
int b;
char v[20];
T_Liste* tab[20];
T_Liste* list;
for (a=0;a<=20;a++) {tab[a]=NULL;}
	while(1) {
	
		a = menu();
		if (a==8) {return 0;}
		if (a==1) {
			for (i=0;i<=20;i++) {
				if (tab[i]==NULL) {
					tab[i] = creerListe();
					printf("liste cree sous tab[%d] /n",i);
					break;
				}
			}
		}
		if (a==2) {
			printf("veuillez choisir la liste concernee (entrer l'indice du tableau)");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici /n");}
				else {
					list = tab[b];
					printf("entrez la valeur a inserer /n");
					scanf("%s",v);
					i = insererElement(list, v);
					if (i==0) {printf("insertion reussie /n");}
					if (i==-1) {printf("insertion failed /n");}
				}
			}
			else {printf("veuillez entrer une valeur correcte /n");}
		}
		if (a==3) {}
	}

}

*/
