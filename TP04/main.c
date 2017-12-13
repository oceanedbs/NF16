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

Mot *m;
/*printf("mot à rechercher \n" );
Mot* mot= creerMot();
printf("mot à prefixer\n");
Mot* mot1= creerMot();
*/
printf("mots à ajouter \n" );
Mot* mot2= creerMot();
ajoutMot2(mot2, dico);

rechercheMot2(dico, mot2);

Mot* mot3 =creerMot();
ajoutMot2(mot3, dico);


Mot* mot4= creerMot();
ajoutMot2(mot4, dico);

Mot* mot5= creerMot();
ajoutMot2(mot5, dico);


Mot* mot6= creerMot();
ajoutMot2(mot6, dico);


Mot* mot7= creerMot();
ajoutMot2(mot7, dico);


printf("Rechercher un mot \n" );
Mot* mot8= creerMot();
printf("resultat recherche  = %d \n",rechercheMot2(dico,mot8));

/*
printf("Prefixer un mot \n" );
Mot* mot9= creerMot();
Dico* doc;
doc = prefixeMot(dico,mot9);
if(doc != NULL){
  printf("doc = %c \n",doc->c);
}
else{printf("Le mot n'existe pas\n" );}
*/

/*printf("appels a print1 puis 2\n");
char tab[100];
int u;
for(u=0;u<100;u++){tab[u]=NULL;}
tab[0]='m';
print(dico2,tab,1);
printf("\n wait bitch \n");*/

/*
printf("mots à supprimer\n" );
Mot* mot10= creerMot();
supprimeMot2(mot10,dico);

Mot* mot11= creerMot();
supprimeMot2(mot11,dico);
*/
printf("print\n" );
Mot* mot12= creerMot();

int a=5;
print2(dico,mot12, &a);
  return 0;
}
