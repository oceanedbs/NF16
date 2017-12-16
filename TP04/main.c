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
    int choix =0, n=-1;
    dico=initDico("rapidement");
    while(choix != 5){
      printf("Que voulez vous faire \n 0- charger un mot \n 1-verimot ABR \n 2 - veridico ABR \n 3-print ordre croissant \n 4 - print ordre décroissant \n 5-quitter \n" );
      scanf("%d", &choix );

      if(choix == 0){
        dico=chargerABR(dico);
      }
      if(choix == 1){
        dico=verimotABR(dico);
      }
      if(choix==2){
        dico=veridicoABR(dico);
      }
      if(choix==3){
        printABR(dico, &n);

      }
      if(choix==4){
        printABR2(dico, &n);
      }
      if(choix==5){
        return 0;
      }
    }


    int d;
    d=-1;
    printABR(dico,&d);

  }
  else if (a==2){
    printf("vous avez choisi la représentation AL\n");
    char tab2[100];int lol;
    Dico* dico;
    int choix;
    dico=malloc(sizeof(Dico));
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
      scanf("%s",tab2 );
      Mot* mot = creerMotChaine(tab2);
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
