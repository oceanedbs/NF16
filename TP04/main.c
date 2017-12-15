#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

int main(){

  int a;
  printf("Vous souhaitez : \n 1-utiliser la représentation ABR \n 2-utiliser la représentation AL\n" );
  scanf("%d", &a);
  printf("Ok\n" );

  if(a == 1){
    printf("Vous avez chsoisi la représentation ABR\n" );
    Arbre *dico;

    dico=initDico("rapidement");

    ajoutMot(dico, "rapide");
    ajoutMot(dico, "rap");
    ajoutMot(dico, "rapidite");
    ajoutMot(dico, "rapiditu");
    ajoutMot(dico, "nul");
    ajoutMot(dico, "nulla");
    ajoutMot(dico, "final");
    ajoutMot(dico, "chaise");
    ajoutMot(dico, "tableau");
    ajoutMot(dico, "table");
    ajoutMot(dico, "tablier");
    ajoutMot(dico, "tabouret");

    printf("fin init\n" );

    dico=verimotABR(dico);
    printf("fin charger ABR\n" );
    ajoutMot(dico,"rire");

  }
  else if (a==2){
    printf("vous avez choisi la représentation AL\n");


    Dico* dico = malloc(sizeof(Dico));
    Dico* dico2= malloc(sizeof(Dico));
    Dico* dico3= malloc(sizeof(Dico));
    Dico* dico4= malloc(sizeof(Dico));
    Dico* dico5= malloc(sizeof(Dico));
    Dico* dico6= malloc(sizeof(Dico));

dico->c='m';
dico->succ=dico2;
dico->alt=NULL;
dico2->c='a';
dico2->succ=dico3;
dico2->alt=NULL;
dico3->c='n';
dico3->succ=dico4;
dico3->alt=NULL;
dico4->c='$';
dico4->succ=NULL;
dico4->alt=dico5;
dico5->c='u';
dico5->succ=dico6;
dico5->alt=NULL;
dico6->c='$';
dico6->succ=NULL;
dico6->alt=NULL;

printf("init fini\n" );

dico = chargerAL(dico);
dico=verimotAL(dico);
  }

return 0;
}
