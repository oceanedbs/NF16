#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "TP03.h"



T_Element *creerElement(char *val){
	T_Element* new_elemt;
	new_elemt=malloc(sizeof(*new_elemt));
	if(new_elemt==NULL){
		printf("Erreur d'allocation mémoire pour l'élément");
	}
	else{
		strcpy(new_elemt->valeur, val);
		new_elemt->suivant = NULL;
		new_elemt->precedent = NULL;
	}
	return new_elemt;

}

T_Liste *creerListe(){ //OK
	T_Liste* new_lst;
	new_lst=malloc(sizeof(* new_lst));
	if(new_lst==NULL){
		printf("Erreur d'allocation pour la liste");
	}
	else{
		new_lst->taille = 0;
		new_lst->tete = NULL;
		new_lst->queue = NULL;
	}

	return new_lst;
}

int insererElement(T_Liste *list, char *val){ //OK
	T_Element* new_elemt, *tete;
	tete = malloc(sizeof(*tete));
	tete=list->tete;
	new_elemt=creerElement(val);
	int i=0, cmp;

    if(list == NULL){return -1;}
    else {
        if(list->taille == 0){ //la liste est vide
                list->tete = new_elemt;
                list->queue = new_elemt;
                list->taille ++;
		return 0;

        }else {
            while(i<list->taille){
                cmp = strcmp(tete->valeur, val);

                 if(cmp != 0){
                        if(cmp>0){ 
                            if(i==0){ //insertion en tete de liste
                                list->tete->precedent = new_elemt;
                                new_elemt->suivant=tete;
                                list->tete = new_elemt;
                            }
                            else{ // insertion n'importe ou dans la liste
                                new_elemt->suivant = tete;
                                new_elemt->precedent=tete->precedent;
				tete->precedent->suivant=new_elemt;
                                tete->precedent=new_elemt;


                            }
                            list->taille++;
                            return 0;
                        }else{ 
                            i++;
                            if(i==list->taille){ //insertion en fin de liste

                            new_elemt->precedent = list->queue;
                            list->queue->suivant = new_elemt;
                            list->queue = new_elemt;

                            list->taille++;
                            return 0;

                            }
                            tete=tete->suivant;
                        }
                 }else{return -1;}
            }
        }
    }
    return -1;
}


T_Element *rechercherElement(T_Liste *list, char *val){ //OK
	T_Element* debut = list->tete;

	if(strcmp(list->queue->valeur, val) < 0 || strcmp(list->tete->valeur, val)>0){
		printf("l'element n'est pas dans la liste");
		return NULL;
	}else{

		while(debut != NULL){
			if(strcmp(debut->valeur, val)==0){
				return debut;
			}
			else if (strcmp(debut->valeur,val)>0){
				return NULL;
			}

			else{
				debut=debut->suivant;

			}

		}

		return NULL;
	}

}



int supprimerElement(T_Liste *list, char *val) { //OK
 
 	if ((list->taille == 1) && (strcmp(list->tete->valeur,val)==0)) {
		free(list->tete);
		list->tete = NULL;
		list->queue = NULL;
		list->taille = 0;
		return 0;
	}
 	T_Element * a; 
 	a = rechercherElement(list, val);
 	if (a==NULL) {return -1;}
 	else if (a->precedent == NULL) {
 			a->suivant->precedent = NULL;
 			list->tete = a->suivant;
 			free(a);
 			list->taille = list->taille - 1;
 			return 0;
 		}
 	else if (a->suivant == NULL) {
 			list->queue = a->precedent;
 			a->precedent->suivant = NULL;
 			free(a);
 			list->taille = list->taille - 1;
 			return 0;
 		}
 	else {
		a->suivant->precedent = a->precedent;
 		a->precedent->suivant = a->suivant;
 		free(a);
 		list->taille = list->taille - 1;
 		return 0;
	}
 }


 
 
 int supprimerListe(T_Liste *list) { //Pb tout n'est pas free a priori si tu install valgrind et que tu le lance, on obtient à la fois 488 dans 13 blocks qui n'ont pas été free et en indirect lost il y a 120 bytes dans 3 blocks donc il manque des trucs a free (et quand je le debug a la fin la liste que j'ai free a comme taille 0 mais les pointeurs tete et queue sont initialisés)
 
 	if(list !=NULL)
	{
		T_Element *a = list->tete;
		while(a != NULL)
		{		
			T_Element *b=a;
			a = a->suivant;
			free(b);
		}
	free(list);
	}
	return 0;
 
 }
 

 T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2) { //OK
 
 //cas listes vides
//check la plus petite tete
//remplir 3e list tete et retirer de l'autre l'element (use supprElem) 
	T_Liste * res;
	int a,i;
	char* k;
	res = creerListe();
	
		if (list1->taille == 0) {return list2;}
		if (list2->taille == 0) {return list1;}
		else {
			while ((list1->taille != 0) && (list2->taille != 0)) {
				a = strcmp(list1->tete->valeur, list2->tete->valeur);
				if (a<0) {							//list1 plus petit
					k =list1->tete->valeur;
					insererElement(res,k);
					supprimerElement(list1, k);
				}
				if (a==0) {							//same faut prendre un et delete 1&2
					k = list1->tete->valeur;
					insererElement(res,k);
					supprimerElement(list1, k);
					supprimerElement(list2, k);
				}
				if (a>=1) {							//list2 plus petit
					k = list2->tete->valeur;
					insererElement(res,k);
					supprimerElement(list2, k);
				}
			}
			//1 ou 2 est vide a ce moment
			if (list1->taille == 0) {
				while (list2->taille != 0) {
					k = list2->tete->valeur;
					insererElement(res,k);
					supprimerElement(list2, k);
				}
			
			}
			if (list2->taille == 0) {
				while (list1->taille != 0) {
					k = list1->tete->valeur;
					insererElement(res,k);
					supprimerElement(list1, k);
				}
			
			}
		}
		
	return res;
 }


