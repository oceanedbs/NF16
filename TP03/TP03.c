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

T_Liste *creerListe(){
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

int insererElement(T_Liste *list, char *val){
	T_Element* new_elemt, *tete;
	tete=list->tete;
	new_elemt=creerElement(val);
	int i=0, cmp;

    if(list == NULL){return -1;}
    else {
        if(list->taille == 0){
                tete = new_elemt;
                list->queue = new_elemt;
                list->taille ++;

        }else {
            while(i<list->taille){
                cmp = strcmp(tete->valeur, val);

                 if(cmp != 0){
                        if(cmp<0){
                            if(i==0){
                                tete->precedent = new_elemt;
                                new_elemt->suivant=tete;
                                tete = new_elemt;
                            }
                            else{
                                new_elemt->suivant = tete;
                                new_elemt->precedent=tete->precedent;
                                tete->precedent=new_elemt;
                                tete->precedent->suivant=new_elemt;

                            }
                            list->taille++;
                            return 0;
                        }else{
                            i++;
                            if(i==list->taille){

                            new_elemt->precedent = list->queue;
                            list->queue->precedent = new_elemt;
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
}/*
T_Element *rechercherElement(T_Liste *list, char *val){
	int i;

	if(strcmp(list->queue, val) < 0 || strcmp(list->tete, val)>0){
		printf("l'element n'est pas dans la liste");
		return NULL;
	}else{

		T_Element* debut = list->tete;
		for(i=0; i<list->taille; i++){
			if(debut->valeur == val){
				return debut;
			}
			else if (debut->valeur > val){
				printf("la valeur n'es pas dans la liste");
			}

			else{
				debut=debut->suivant;

			}

		}

		return NULL;
	}

}


int supprimerElement(T_Liste *list, char *val) {

	T_Element * a; 
	a = rechercherElement(list, val);
	if (a==NULL) {return -1;}
	if (a->precedent == NULL) {
			a->suivant->precedent = NULL;
			
			free(a);
			list->taille = list->taille - 1;
			return 0;
		}
	if (a->suivant == NULL) {
			
			a->precedent->suivant = NULL;
			free(a);
			list->taille = list->taille - 1;
			return 0;
		}
	a->suivant->precedent = a->precedent;
	a->precedent->suivant = a->suivant;
	free(a);
	list->taille = list->taille - 1;
	return 0;
}


int supprimerListe(T_Liste *list) {

	//a faire flemme maintenant <3

}

*/

