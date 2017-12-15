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
    char tab2[100];int lol;
    Dico* dico;
    int choix;
dico = chargerAL(dico);
  while(1){
printf("que voulez vous faire? \n");
printf("1 - print tout\n");
printf("2 - print ss ensemble\n");
printf("3 - verimot\n");
printf("4 - veridico\n");
printf("5 - quitter\n");
    
    scanf("%d",&choix);
    if(choix==5){break;}
    if(choix==1){for(lol=0;lol<100;lol++){tab2[lol]=0;} lol=-1; print(dico,tab2,0,&lol);}
    if(choix==2){
      printf("entrez le ss ensemble\n");
      Mot* mot = creerMot();
      //printf("combien de valeurs max voulez vous?\n");
      //scanf("%d",&lol);
      lol=-1;
      print2(dico,mot,&lol);
    }
    if(choix==3){dico=verimotAL(dico);}
    if(choix==4){dico = veridicoAL(dico);}
    printf("\n-------- fin de l'iteration, on recommence -------\n");

  }
  }

return 0;
}
