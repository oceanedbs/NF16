#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "TP03.h"


int main() {
    char* a="Hey";
    T_Element* new_elemt;
    T_Liste *new_lst;
    int b;

    new_elemt = creerElement(a);

    if(new_elemt != NULL){ printf("Element cree \n");}
    else {printf("Echec création element \n");}

    new_lst = creerListe();

    if(new_lst !=NULL){printf("Liste cree \n");}
    else{printf("echec creation liste \n");}

    b = insererElement(new_lst, a);

    if(b== -1){printf("Erreur d'insertion \n");}
    else{printf("insertion correcte \n");}

    printf("taille liste %d", new_lst->taille);

    return 0;
}
