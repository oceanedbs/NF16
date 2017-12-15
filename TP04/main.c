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
        dico=printABR(dico, &n);

      }
      if(choix==4){
        dico=printABR2(dico, &n);
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


dico = chargerAL(dico);

int i;
char tab[100];
for(i=0;i<100;i++){tab[i]=0;}
i=-1;
print(dico, tab, 0, &i);

//dico=verimotAL(dico);

dico = veridicoAL(dico);
for(i=0;i<100;i++){tab[i]=0;}
i=-1;
print(dico, tab, 0, &i);

}

return 0;
}
