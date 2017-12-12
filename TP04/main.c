#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

int main(){
  /*Arbre *dico;
  int w;
  w=strncmp("rapide", "rap", strlen("rap"));
  printf("%d", w);
  dico=initDico("rapidement");

  ajoutMot(dico, "rapide");
  ajoutMot(dico, "rap");
  ajoutMot(dico, "rapidement");
  ajoutMot(dico, "rapidite");
  ajoutMot(dico, "rapidita");
  ajoutMot(dico, "rapiditu");
  ajoutMot(dico, "nul");
  ajoutMot(dico, "final");
  ajoutMot(dico, "chaise");
  ajoutMot(dico, "tableau");
  ajoutMot(dico, "table");
  ajoutMot(dico, "tablier");
  ajoutMot(dico, "tabouret");

 rechercherMot(dico, "rap");

 suggestionMots(dico, "ra", 5);*/

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

Mot* mot= creerMot();
printf("done \n");
 printf("resultat  = %d \n",rechercheMot2(dico,mot));
Dico* doc;
doc = prefixeMot(dico,mot);
printf("doc = %c \n",doc->c);
//dico = supprimeMot2(mot,dico);
/*printf("appels a print1 puis 2\n");
char tab[100];
int u;
for(u=0;u<100;u++){tab[u]=NULL;}
tab[0]='m';
print(dico2,tab,1);
printf("\n wait bitch \n");*/
print2(dico,mot);
  return 0;
}
