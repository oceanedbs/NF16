	#include<stdio.h>
	#include<stdlib.h>
	#include <string.h>
	#include "TP03.h"

/*				

FONCTION PRGRM PRINCIPAL -> faire menu interactif (toutes les fonctions sont pretes)
1. CrÃ©er une liste
2. Ajouter un Ã©lÃ©ment dans une liste
3. Supprimer un Ã©lÃ©ment dâ€™une liste
4. Rechercher un Ã©lÃ©ment dans une liste
5. Afficher les Ã©lÃ©ments dâ€™une liste
6. Supprimer une liste
7. Fusionner deux listes
8. Quitter


	
*/

/*
int main() {
    char* a="Hey", *c="Oooh", *e="Yoyo", *g="Bhabha";
    T_Element* new_elemt,*new_elemt2, *rechercher;
    T_Liste *new_lst, *new_lst2, *fusion;
    int b,d,f,h, suppr_elemt, suppr_lst;


	    new_elemt = creerElement(a);
	   

    if(new_elemt != NULL){ printf("Element cree \n");}
    else {printf("Echec crÃ©ation element \n");}

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


*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "head.h"


int main() {
int a,i=0;
T_Element *j;
int b,c,d=0;
char v[20];
T_Liste* tab[20];
T_Liste* list;
for (a=0;a<=20;a++) {tab[a]=NULL;}
	while(1) {
        a = NULL;
		a = menu();
		if (a==8) {
			printf("Au revoir !\n");
			return 0;
		}
		if (a==1) {
                d=0;
			for (i=0;i<=20;i++) {
				if (tab[i]==NULL) {
					tab[i] = creerListe();
					printf("liste cree sous tab[%d] \n",i);
					break;
				}
            d++;
			}
			if (d==21) {printf("pas assez de place pour mettre d'autres liste, veuillez en supprimer une ancienne \n");}
		}
		if (a==2) {

			//faire le cas ou aucune liste n'est créée
			printf("veuillez choisir la liste concernee (entrer l'indice du tableau) \n");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici \n");}
				else {
					list = tab[b];
					printf("entrez la valeur a inserer \n");
					if (scanf("%s",v)==1) {
					i = insererElement(list, v);
					if (i==0) {printf("insertion reussie \n");}
					if (i==-1) {printf("insertion failed, la valeur est déjà dans la liste \n");}}
				}
			}
			else {printf("veuillez entrer une valeur correcte \n");}
		}
		if (a==3) {
			printf("veuillez choisir la liste concernee (entrer l'indice du tableau)\n");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici \n");}
				else {
					list = tab[b];
					printf("entrez la valeur a supprimer \n");
					if (scanf("%s",v)==1) {
					i = supprimerElement(list, v);
					if (i==0) {printf("suppression reussie \n");}
					if (i==-1) {printf("suppression failed, élement non trouvé \n");}}
				}
			}
			else {printf("veuillez entrer une valeur correcte \n");}
		}
		if (a==4) {
			printf("veuillez choisir la liste concernee (entrer l'indice du tableau)\n");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici \n");}
				else {
					list = tab[b];
					printf("entrez la valeur a rechercher \n");
					if (scanf("%s",v)==1) {
					j = NULL;
					j = rechercherElement(list, v);
					if (j==NULL) {printf("element introuvable \n");}
					else {printf("element found \n");}}
				}
			}
			else {printf("veuillez entrer une valeur correcte \n");}
		}
		if (a==5) {
			printf("veuillez choisir la liste concernee (entrer l'indice du tableau) \n");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici \n");}
				else {
					i = afficher(tab[b]);
					if (i==0) {printf("everything is ok \n");}
					if (i==-1) {printf("everything is shit \n");}
				}
			}
			else {printf("veuillez entrer une valeur correcte \n");}
		}
		if (a==6) {
			printf("veuillez choisir la liste concernee (entrer l'indice du tableau)\n");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici \n");}
				else {
					i = supprimerListe(tab[b]);
					tab[b] = NULL;
					if (i==0) {printf("everything is ok \n");}
					if (i==-1) {printf("everything is shit \n");}
				}
			}
			else {printf("veuillez entrer une valeur correcte \n");}
		}
		if (a==7) {
			printf("veuillez choisir la premiere liste concernee (entrer l'indice du tableau)\n");
			if ((scanf("%d",&b) == 1) && (b<=20) && (b>=0)) {
				if (tab[b]==NULL) {printf("indice incorrect, pas de liste ici \n");}
				else {
							printf("veuillez choisir la deuxieme liste concernee (entrer l'indice du tableau) \n");
						if ((scanf("%d",&i) == 1) && (i<=20) && (i>=0)) {
						if (tab[i]==NULL) {printf("indice incorrect, pas de liste ici \n");}
						else {
							list = fusionnerListes(tab[i], tab[b]);
							tab[i] = list;
							tab[b] = NULL;
							printf("la nouvelle liste a prit la place de la liste numero %d \n",i);
						}
					}
					else {printf("veuillez entrer une valeur correcte \n");}
				}
			}
			else {printf("veuillez entrer une valeur correcte \n");}
		}

	}
return 0;
}

