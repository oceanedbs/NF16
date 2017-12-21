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
    char *chaine;
    int choix =0, n=-1;
    char chaine2[100];
    dico=initDico("rapidement");
    while(choix != 8){
      printf("Que voulez vous faire \n 0- charger l'ABR depuis le fichier dictionnaire.txt \n 1-verimot ABR \n 2 - veridico ABR \n 3- print parcours prefixe \n 4 - print parcours infixe \n 5- parcours parcours_postfixe \n 6- afficher sous ensemble 1 (affiche tous les mots du dictionnaire avant la chaine passée en argument)\n 7-afficher sous ensemble 2 (affiche les mots commençant par le préfixe passé en argument)\n 8-quitter \n" );
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
        parcours_prefixe(dico->racine);

      }
      if(choix==4){
        parcours_infixe(dico->racine);
      }
      if(choix == 5){
        parcours_postfixe(dico->racine);
      }
      if(choix==6){
        printf("Entrez la chaine de caractere souhaitée \n" );
        scanf("%s", chaine2);
        printABR3(dico->racine, &n,chaine2);
      }
      if(choix==7){
        printf("Entrez la chaine de caractere souhaitée \n" );
        scanf("%s", chaine2);
        printABR4(dico->racine, &n,chaine2);
      }
      if(choix==8){
        return 0;
        supprimeABRtotal(dico->racine);
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
    if(choix==5){supprimeALtotal(dico); break;}
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
