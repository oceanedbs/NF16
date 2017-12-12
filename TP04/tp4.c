#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

/*PARTIE 1*/

Arbre* initDico(char* valeur){
  DicoABR *new_dico;
  Arbre *newArbre;
  new_dico=malloc(sizeof(DicoABR));
  newArbre=malloc(sizeof(Arbre));
  if(new_dico!=NULL){
    new_dico->val=valeur;
    new_dico->pere=NULL;
    new_dico->fils_droit=NULL;
    new_dico->fils_gauche=NULL;
    newArbre->racine = new_dico;
  }
  else{
    printf("Erreur d'allocation mémoire\n");
  }

  return newArbre;
}

DicoABR *ajoutMot(Arbre *newArbre, char *valeur){
  DicoABR* new_mot;
  new_mot=malloc(sizeof(DicoABR));
  if(new_mot!=NULL){
    new_mot->val = valeur;
    new_mot->pere=NULL;
    new_mot->fils_gauche=NULL;
    new_mot->fils_droit=NULL;
    if(newArbre != NULL){
      DicoABR* pointeurx, *pointeury;
      pointeurx=newArbre->racine;
      pointeury=NULL;

      while(pointeurx!=NULL){
        pointeury=pointeurx;
        if(strcmp(pointeurx->val, valeur)>0){
          pointeurx=pointeurx->fils_gauche;
        }
        else if(strcmp(pointeurx->val, valeur)<0){
          pointeurx=pointeurx->fils_droit;
        }
        if(strcmp(pointeury->val, valeur)==0){
          printf("L'élement existe déjà\n");
          return pointeury;
        }
      }
      new_mot->pere=pointeury;
      if(strcmp(pointeury->val, valeur)>0){
          pointeury->fils_gauche=new_mot;
      }else{
          pointeury->fils_droit=new_mot;
      }

      }
      else{printf("Le dictionnaire passé n'a pas été initialisé\n");}
  }
  else{
    printf("Erreur d'allcation mémoire\n");
  }
  printf("Le mot à été inséré dans l'arbre\n" );
  return(new_mot);

}

DicoABR *rechercherMot(Arbre* dico, char* valeur) {
  DicoABR* dic = dico->racine;
  while (dic!=NULL && dic->val!=valeur) {
    if (strcmp(dic->val,valeur)>0) {dic = dic->fils_gauche;}
    if (strcmp(dic->val,valeur)<0) {dic = dic->fils_droit;}
  }
  if (dic==NULL) {printf("not found :( \n");}
  else if (strcmp(dic->val,valeur)==0) {printf("word found :D \n");}
  return dic;
}

DicoABR* mini(DicoABR* dico) {  //min du sad de dico
  DicoABR* temp=dico;

  while (temp->fils_gauche!=NULL) {
    temp = temp->fils_gauche;
  }
  return temp;
}

int supprimeMot(Arbre *dico, char* valeur) {
  DicoABR* dic = rechercherMot(dico,valeur);
  DicoABR* temp;
  DicoABR* temp2;
  if (dic==NULL) {printf("mot non exitant \n"); return -1;}
  else {printf("le mot existe \n");}
  if (dic->fils_droit==NULL && dic->fils_gauche==NULL) {
    dic = dic->pere;
    if (strcmp(dic->fils_droit->val,valeur)==0) {free(dic->fils_droit); dic->fils_droit=NULL;}
    else {free(dic->fils_gauche); dic->fils_gauche=NULL;}
    return 0;
  }
  if (dic->fils_droit==NULL) {
    temp = dic;
    dic->fils_gauche->pere = dic->pere;
    dic = dic->pere;
    if (strcmp(dic->fils_droit->val,valeur)==0) {dic->fils_droit=dic->fils_droit->fils_gauche; free(temp);}
    else {dic->fils_gauche=dic->fils_gauche->fils_gauche; free(temp);}
    return 0;
  }
  if (dic->fils_gauche==NULL) {
    temp = dic;
    dic->fils_droit->pere = dic->pere;
    dic = dic->pere;
    if (strcmp(dic->fils_droit->val,valeur)==0) {dic->fils_droit=dic->fils_droit->fils_droit; free(temp);}
    else {dic->fils_gauche=dic->fils_gauche->fils_droit; free(temp);}
    return 0;
  }
  if (dic->fils_droit!=NULL && dic->fils_gauche!=NULL) {
    //on remplace dic par min de SAD et suppr min SAD
    temp = mini(dic);
    dic->val = temp->val;
    //suppr temp

          if (temp->fils_droit==NULL && temp->fils_gauche==NULL) {
            temp2= temp->pere;
            if (strcmp(temp2->fils_droit->val,temp->val)==0) {free(temp2->fils_droit); temp2->fils_droit=NULL;}
            else {free(temp2->fils_gauche); temp2->fils_gauche=NULL;}
            return 0;
          }
          /*if (temp->fils_droit==NULL) {
            temp = dic;
            dic->fils_gauche->pere = dic->pere;
            dic = dic->pere;
            if (strcmp(dic->fils_droit->val,valeur)==0) {dic->fils_droit=dic->fils_droit->fils_gauche; free(temp);}
            else {dic->fils_gauche=dic->fils_gauche->fils_gauche; free(temp);}
            return 0;
          } */            //ici temp est le min du sad donc il a pas de fils gauche donc
          if (temp->fils_droit!=NULL) {
            temp2 = temp->pere;
            if (strcmp(temp2->fils_droit->val,temp->val)==0) {temp2->fils_droit= temp->fils_droit;}
            else {temp2->fils_gauche = temp->fils_droit;}
            temp->fils_droit->pere = temp->pere;

            free(temp);
            return 0;
          }

  }
}



DicoABR* successeur(DicoABR *pointeur){
  DicoABR *y;
  if(pointeur->fils_droit != NULL){
      return mini(pointeur->fils_droit);
  }
  else{
    y=pointeur->pere;
    while(y!= NULL && pointeur == y->fils_droit){
      pointeur = y;
      y=y->pere;
  }
  return y;
}
}


int suggestionMots(Arbre *dico, char* souschaine, int k){
  DicoABR *pointeur, *mot;
  pointeur=dico->racine;
  int i=k;
  while(pointeur != NULL && strncmp(pointeur->val, souschaine, strlen(souschaine))!=0) {
    if(strncmp(pointeur->val, souschaine, strlen(souschaine))>0){
      pointeur=pointeur->fils_gauche;
    }
    else if(strncmp(pointeur->val, souschaine, strlen(souschaine))<0){
      pointeur=pointeur->fils_droit;
    }else{
      printf("Il n'y a pas de mots contenant cette sous chaine\n");
      return 0;
    }
  }
  if(pointeur == NULL) {
    printf("Il n'y a pas de mots contenant cette sous chaine\n" );
    return 0;
  }
  if (strncmp(pointeur->val, souschaine, strlen(souschaine))==0) { //on récupère la plus petite valeur ayant ce prefixe
      while(pointeur->fils_gauche != NULL && strncmp(pointeur->val, souschaine, strlen(souschaine))==0){
        pointeur=pointeur->fils_gauche;
      }
    }

  DicoABR *w;
  w=pointeur->pere;
  printf("Valeur %d : %s\n",k, w->val );
  k--;
  while(k>0){
    w=successeur(w);
    if(strncmp(w->val, souschaine, strlen(souschaine))==0){
      printf("Valeur %d : %s\n",k, w->val );
      k--;
    }
   else{
      printf("Il n'y a plus de valeurs à suggérer\n" );
     return 1;
    }
  }
  return 1;
}
/* PARTIE 2 */

Mot* creerMot(){        //IT WORKS
    char tab[100];
     int i;
    for(i=0;i<100;i++){tab[i]=NULL;}
    printf("entrez un mot\n");
    gets(tab);
    Mot* mot;
    Mot* mot2;
    Mot* mot3;
    mot = malloc(sizeof(Mot));
    mot->c=tab[0];
    mot2 = mot;
    i=1;
    while (tab[i]!=NULL && i<100) {
       mot3 = malloc(sizeof(Mot));
       mot2->suiv = mot3;
       mot2=mot2->suiv;
       mot2->c=tab[i];
       mot2->suiv=NULL;
       i++;
    }
    mot3 = malloc(sizeof(Mot));
    mot2->suiv = mot3;
       mot2=mot2->suiv;
       mot2->c='$';
       mot2->suiv=NULL;
                    mot2=mot;
                    while(mot2->suiv!=NULL){printf(" mot %c  \n",mot2->c); mot2=mot2->suiv;}
                    printf(" mot %c \n",mot2->c);
                    printf("i = %d \n",i);
    return mot;
}

Dico *initDico2(Dico *dico, Mot *mot){
  if(dico==NULL){
    printf("Le dictionnaire passé en paramètre est vide\n");
    return dico;
  }
  else{
  dico=malloc(sizeof(Dico));
  dico->c=mot->c;
  dico->succ=NULL;
  dico->alt=NULL;
  dico->succ=initDico2(dico-> succ , mot->suiv);
  return dico;
  }
}


int rechercheMot2(Dico *dico, Mot *mot){        //IT WORKS
  if(mot != NULL && dico!=NULL){
    if((mot->c=='$') && (dico->c=='$')){
      return 1;
    }else{
      if(mot->c==dico->c){
        return rechercheMot2(dico->succ,mot->suiv);
      }else{
        if(dico->alt != NULL && dico->alt->c==mot->c){
          return rechercheMot2( dico->alt,mot);
        }else{
          return 0;
        }
      }
    }
  }else{
      printf("return 0 2 \n");
    return 0;
  }
}



Dico *prefixeMot(Dico *dico, Mot *mot){     //IT WORKS

  Dico* dico2; Mot *mot2;
  dico2 = dico;
  Dico *dico3;
  while (mot->c!=dico2->c) {                  //on cherche si ya le premier char, si oui on pointe dessu sinon on return null
    if (dico2->alt!=NULL) {dico2=dico2->alt;}
    else {return NULL;}
  }
  //ici on a mot->c == dico2->c == dico3->c
  dico3=dico2;
  mot2=mot;
  dico2=dico2->succ;
  while(mot2->c!='$') {
        if (dico2==NULL) {return dico3;}
        if (mot2->suiv->c =='$') { return dico3;}
        //if (dico2->c=='$') {/*dico2=dico2->alt;*/printf("oh damn \n");} //useless
        if (dico2->c==mot2->suiv->c) {dico3=dico2;  mot2=mot2->suiv;  dico2=dico2->succ;}
        else {dico2=dico2->alt;}
  }
}


Dico *ajoutMot2(Mot *mot, Dico *dico) {
  Dico *dico2;
  if(mot != NULL && dico != NULL){
    int rech=rechercheMot2(dico, mot);
    if(rech == 1){
      printf("Le mot exite déjà\n");
    }
    else if (rech == 0){ //le mot n'existe pas dans le dictionnaire
      if(dico->c == NULL){ //insertion à la racine si le dictionnaire est vide
          dico->c=mot->c;
          mot=mot->suiv;
          while(mot != NULL){
            Dico  *n;
            n=malloc(sizeof(Dico));
            n->c=mot->c;
            n->succ=NULL;
            n->alt = NULL;
            dico->succ = n;
            dico=dico->succ;
            mot=mot->suiv;
          }
          return dico;
        }

      while (dico->c <= mot->c) { //permet de parcourir tout l'arbre jusqu'au caractère différent du préfixe
        while(mot->c == dico->c){
          dico=dico->succ;
          mot=mot->suiv;
        }
        if(dico->alt != NULL && dico->alt->c <= mot->c){
          dico=dico->alt;
        }
      }
      if(dico->c > mot->c){ // si la lettre à inserer est inférieur à la lettre dans le alt
        Dico *temp, *n;
        n=malloc(sizeof(Dico));
        temp=dico;
        n->c=mot->c;
        n->succ=NULL;
        n->alt = temp;
        dico=n;
        dico=dico->succ;
        mot=mot->suiv;
        while(mot != NULL){
          Dico  *n;
          n=malloc(sizeof(Dico));
          n->c=mot->c;
          n->succ=NULL;
          n->alt = NULL;
          dico->succ = n;
          dico=dico->succ;
          mot=mot->suiv;
        }
        return dico;
      }

       //dico alt n'existe pas, donc on le créé et on rajoute toutes les lettres suivantes
      else if (dico->alt == NULL){
          Dico  *n;
          n=malloc(sizeof(Dico));
          n->c=mot->c;
          n->succ=NULL;
          n->alt = NULL;
          dico->alt = n;
          dico=dico->alt;
          mot=mot->suiv;
          while(mot != NULL){
            Dico  *n;
            n=malloc(sizeof(Dico));
            n->c=mot->c;
            n->succ=NULL;
            n->alt = NULL;
            dico->succ = n;
            dico=dico->succ;
            mot=mot->suiv;
          }
          return dico;
        }
        else{ //dico alt exite, on sauvearde l'actuel dico alt pour le rattachrt au nouveeau neod
          Dico  *n, *y;
          n=malloc(sizeof(Dico));
          y=dico->alt;
          n->c=mot->c;
          n->succ=NULL;
          n->alt = y;
          dico->alt = n;
          dico=dico->alt;
          mot=mot->suiv;
          while(mot != NULL){
            Dico  *n;
            n=malloc(sizeof(Dico));
            n->c=mot->c;
            n->succ=NULL;
            n->alt = NULL;
            dico->succ = n;
            dico=dico->succ;
            mot=mot->suiv;
          }
          return dico;

        }
      }
    }
}


Dico* supprimeMot2( Mot* mot, Dico* dico) {             //SEEMS TO WORK but unsure

  if (rechercheMot2(dico,mot)==0) {printf("lol ya pas ce mot \n");return dico;}
  else {printf("lets get started \n");}
  int i =0;
  Dico* dico2 = dico;
  Dico* first = dico;
  Mot* motfirst=mot;
  Mot* mot2 = mot;
                                              printf("first = %c , dico2 = %c \n",first->c,dico2->c);
                                            printf("motfirst = %c , mot2 = %c \n",motfirst->c,mot2->c);

  //check 1ere lettre
  if (dico->c!=mot->c) {printf("fuck u \n");
        while (dico2->alt->c!=mot2->c) {printf("fuck u2 \n"); dico2=dico2->alt;}
  }             //on est sur le pere de l'alt qu'on veut
                                            //printf("fuck u3 \n");
  first = dico2;
  if(dico2->alt!=NULL){dico2=dico2->alt; }
                                            //printf("fuck u4 \n");
  //fin de check 1er lettre
  while (dico2->c!='$' || mot2->c!='$') {       //printf("dico2 = %c \n",dico2->c);
        //if (mot2->suiv==NULL) {}
        if (dico2->succ->alt != NULL) {
              first = dico2; motfirst = mot2;
              if (dico2->succ->c==mot2->suiv->c) {dico2=dico2->succ;  mot2=mot2->suiv;}
              else {
                                                //printf("fuck u5 \n");
                  dico2=dico->succ;
                  mot2=mot2->suiv;
                  while (dico2->alt->c!=mot2->c) {dico2=dico2->alt;}
                  first = dico2;
                  motfirst = mot2;
                  dico2=dico2->alt;
              }
        }
        else {
            dico2=dico2->succ;
            mot2=mot2->suiv;
        }
  }
    //fin de preparation, le first et motfirst sont au bon endroit
    //periode de suppression de la partie voulue de l'AL
                                            printf("first = %c , dico2 = %c \n",first->c,dico2->c);
                                            printf("motfirst = %c , mot2 = %c \n",motfirst->c,mot2->c);
    if (first->c==dico->c) {
        Dico* rest = first->alt;
        while (first!=NULL) {dico2=first; first=first->succ; free(dico2);}
        return rest;
    }
    if (first->c==motfirst->c) {
      dico2=first->succ;
      first->succ=first->succ->alt;
      while (dico2!=NULL) {first = dico2; dico2=dico2->succ; free(first);}
      return dico;
    }
    else {
      dico2 = first->alt;
      first->alt = first->alt->alt;
      while (dico2!=NULL) {first=dico2; dico2=dico2->succ; free(first);}
      return dico;
    }
return dico;
  }


char** suggestionMot2(int k, Dico* dico, Mot* mot) {
  while (dico->c <= mot->c) { //permet de parcourir tout l'arbre jusqu'au caractère différent du préfixe
    while(mot->c == dico->c){
      dico=dico->succ;
      mot=mot->suiv;
      printf("%c",dico->c );
    }
    if(dico->alt != NULL && dico->alt->c <= mot->c){
      dico=dico->alt;
    }
  }
  if(mot->c == '$'){
    while(k>0){
      if(dico->c=='$'){
        printf("\n");
      }

    }
  }

}


//  PARTIE 3

Arbre* chargerABR(Arbre* dico){ //charge le fichier dans ABR
  FILE* fichier = NULL;
  fichier = fopen("dictionnaire.txt","r");
  if (fichier == NULL) {return EXIT_FAILURE;}
  char tab[100];
  int i;
  Arbre* dico2 = dico;
  while (fichier != EOF) {
    for (i=0;i<100;i++) {tab[i]=NULL;}
    fgets(tab,100,fichier);
    dico2 = ajoutMot(dico2,tab);
  }

  fclose(fichier);
  return dico2;
}


Dico* chargerAL(Dico* dico){
  FILE* fichier = NULL;
  fichier = fopen("dictionnaire.txt","r");
  if (fichier == NULL) {return EXIT_FAILURE;}
  char tab[100];
  int i;
  Dico* dico2 = dico;
  while (fichier != EOF) {
    for (i=0;i<100;i++) {tab[i]=NULL;}
    fgets(tab,100,fichier);
    //transformer le tab en Mot
    Mot* mot;
    Mot* mot2;
    Mot* mot3;
    mot = malloc(sizeof(Mot));
    mot->c=tab[0];
    mot2 = mot;
    i=1;
    while (tab[i]!=NULL) {
        mot3=malloc(sizeof(Mot));
       mot2->suiv = mot3;
       mot2=mot2->suiv;
       mot2->c=tab[i];
       mot2->suiv=NULL;
    }
    mot3=malloc(sizeof(Mot));
    mot2->suiv = mot3;
       mot2=mot2->suiv;
       mot2->c='$';
       mot2->suiv=NULL;
    dico2 = ajoutMot2(mot,dico2);
  }

  fclose(fichier);
  return dico2;
}


void print(Dico* dico, char* tab, int i){  //print tout le sous ensemble de dico dans l'AL // IT WORKS

  int k;
  tab[i]=dico->c;

  if (dico->succ!=NULL) {
        char tab3[100];
        for (k=0;k<100;k++) {tab3[k]=tab[k];}
        print(dico->succ,tab3,i+1);
  }
  else {printf("%s \n",tab);}
  if (dico->alt!=NULL) {
        char tab2[100];
        for (k=0;k<100;k++) {tab2[k]=tab[k];}
        print(dico->alt,tab2,i);
  }
return 0;
}

void print2(Dico* dico, Mot* mot){      //affiche tt le ss ensemble de dico qui commence par mot  //IT WORKS
    Dico* dico2 = prefixeMot(dico,mot);

    Mot* mot2 = mot;
    int i=0;
  char tab[100];
  for(i=0;i<100;i++){tab[i]=NULL;}
  i=0;
    while (mot2->c!='$'){
      tab[i] = mot2->c;
      mot2= mot2->suiv;
      i++;
    }

  print(dico2->succ,tab,i);
    return 0;
}



/*

BONUS :
CALCULER LE TEMPS D'EXECUTION D'UNE FONCTION
GRAPHIQUE : TAILLE DE DONNEES / TEMPS
COMPARER COMPLEXITE THEORIQUE

*/
