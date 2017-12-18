#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

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
    int ulu ;
    new_mot->val = malloc(sizeof(char)*110);
    for(ulu=0;ulu<100;ulu++){new_mot->val[ulu]=valeur[ulu];}
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
        else if(strcmp(pointeury->val, valeur)==0){
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
/*
char * creerMot1(char tab[]){
  int i=0;
  char *mot;
  while(tab[i]!=0){
    strncat(mot, tab[i],1);
  }
  return mot;
}*/

DicoABR *rechercherMot(DicoABR* dico, char* valeur) {

  if(!dico || !valeur )  return dico;

  int n=strcmp(valeur, dico->val);
  if(n==0) return dico;

  if(n>0) return rechercherMot(dico->fils_droit, valeur);

  return rechercherMot(dico->fils_gauche, valeur);
}

DicoABR* mini(DicoABR* dico) {  //min du sad de dico
  DicoABR* temp=dico;

  while (temp->fils_gauche!=NULL) {
    temp = temp->fils_gauche;
  }
  return temp;
}

int supprimeMot(Arbre *dico, char* valeur) {
  DicoABR* dic = rechercherMot(dico->racine,valeur);
  DicoABR* temp;
  DicoABR* temp2;
  if (dic==NULL) {printf("mot non exitant \n"); return -1;}
  else {printf("le mot existe \n");}
  if (dic->fils_droit==NULL && dic->fils_gauche==NULL) {
    dic = dic->pere;
    if (dic->fils_droit != NULL && strcmp(dic->fils_droit->val,valeur)==0) {free(dic->fils_droit); dic->fils_droit=NULL;}
    else {free(dic->fils_gauche); dic->fils_gauche=NULL;}
    return 0;
  }
  if (dic->fils_droit==NULL) {
    temp = dic;
    dic->fils_gauche->pere = dic->pere;
    dic = dic->pere;
    if (dic->fils_droit != NULL && strcmp(dic->fils_droit->val,valeur)==0) {dic->fils_droit=dic->fils_droit->fils_gauche; free(temp);}
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
    temp = mini(dic->fils_droit);
    dic->val = temp->val;
    //suppr temp

          if (temp->fils_droit==NULL && temp->fils_gauche==NULL) {
            temp2= temp->pere;
            if (temp2->fils_droit != NULL && strcmp(temp2->fils_droit->val,temp->val)==0) {free(temp2->fils_droit); temp2->fils_droit=NULL;}
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

void parcours_prefixe(DicoABR *dico){
  if(dico != NULL){
    printf("Valeur : %s\n", dico->val );
    parcours_prefixe(dico->fils_gauche);
    parcours_prefixe(dico->fils_droit);
  }
}

void parcours_infixe(DicoABR *dico){
  if(dico != NULL){
    parcours_infixe(dico->fils_gauche);
    printf("Valeur : %s\n", dico->val );
    parcours_infixe(dico->fils_droit);
  }
}
void parcours_postfixe(DicoABR *dico){
  if(dico!=NULL){
    parcours_postfixe(dico->fils_gauche);
    parcours_postfixe(dico->fils_droit);
    printf("Valeur %s \n", dico->val );
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
    for(i=0;i<100;i++){tab[i]=0;}
    printf("entrez un mot\n");
    gets(tab);
    Mot* mot;
    Mot* mot2;
    Mot* mot3;
    mot = malloc(sizeof(Mot));
    mot->c=tab[0];
    mot2 = mot;
    i=1;
    while (tab[i]!=0 && i<100) {
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
                  //  printf("i = %d \n",i);
    return mot;
}

Mot* creerMotChaine(char *chaine){        //IT WORKS
    char tab[100];
     int i;
    for(i=0;i<100;i++){tab[i]=0;}
    Mot* mot;
    Mot* mot2;
    Mot* mot3;
    mot = malloc(sizeof(Mot));
    mot->c=chaine[0];
    mot2 = mot;
    i=1;
    while (isalpha(chaine[i])) {
       mot3 = malloc(sizeof(Mot));
       mot2->suiv = mot3;
       mot2=mot2->suiv;
       mot2->c=chaine[i];
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
        if(dico->alt != NULL && dico->alt->c <= mot->c){
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

Mot *prefixeMotpointeur(Dico *dico, Mot *mot){     //IT WORKS

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
        if (dico2==NULL) {return mot2;}
        if (mot2->suiv->c =='$') { return mot2;}
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
      return dico;
    }
    else{ //le mot n'existe pas dans le dictionnaire
      Dico *pointeur = prefixeMot(dico, mot);
      Mot *caractere = prefixeMotpointeur(dico,mot);
      if(pointeur==NULL || caractere == NULL){
        printf("Impossible de trouver le mot, aucun prefix\n" );
        pointeur= dico;
        caractere=mot;
        while(pointeur->alt != NULL && pointeur->alt->c<=caractere->c){
          pointeur=pointeur->alt;
        }
      }
      else {
        printf("Il y a un prefixe ! Dico %c, Mot %c \n", pointeur->c, caractere->c );
        if(caractere->suiv->c != '$'){caractere=caractere->suiv;}
        else if(caractere->suiv->c == '$'){
          Dico *pointeur2 = pointeur->succ;
          Dico *new=malloc(sizeof(Dico));
          new->c='$';
          new->succ=NULL;
          new->alt=pointeur2;
          pointeur->succ=new;
          return new;


        }

      //printf("ici pointeur = %c et caractere = %c \n", pointeur->c, caractere->c );
      pointeur=pointeur->succ;
      while(pointeur->alt != NULL){
        if(pointeur->c < caractere->c && pointeur->alt->c < caractere->c){
          pointeur=pointeur->alt;
        }
        else {
          break;
        }
      }
    }

      Dico * newdico = malloc(sizeof(Dico));
      newdico->alt = NULL;
      newdico->succ = NULL;
      newdico->c = caractere->c;
      if(pointeur->alt != NULL) {newdico->alt = pointeur->alt; pointeur->alt = newdico;}
      else{pointeur->alt = newdico;}
      pointeur=pointeur->alt;

      caractere=caractere->suiv;
      while(caractere->c != '$'){
        Dico* newdico2 = malloc(sizeof(Dico));
        newdico2->alt = NULL;
        newdico2->succ=NULL;
        newdico2->c=caractere->c;

        pointeur->succ=newdico2;
        pointeur=pointeur->succ;
        caractere=caractere->suiv;
      }
      Dico* dico3 = malloc(sizeof(Dico));
      dico3->alt = NULL;
      dico3->succ=NULL;
      dico3->c=caractere->c;
      pointeur->succ=dico3;
      printf("Tout est écrit \n");
    }
    return dico;
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
                                           //   printf("first = %c , dico2 = %c \n",first->c,dico2->c);
                                           // printf("motfirst = %c , mot2 = %c \n",motfirst->c,mot2->c);

  //check 1ere lettre
  if (dico->c!=mot->c) {
                                            //printf("fuck u \n");
        while (dico2->alt->c!=mot2->c) {printf("fuck u2 \n"); dico2=dico2->alt;}
  }             //on est sur le pere de l'alt qu'on veut
                                            //printf("fuck u3 \n");
  first = dico2;
  if(dico2->alt!=NULL && dico->c!=mot->c){dico2=dico2->alt; }
                                           // printf("fuck u4 \n");
                                           // printf("first = %c , dico2 = %c \n",first->c,dico2->c);
                                           // printf("motfirst = %c , mot2 = %c \n",motfirst->c,mot2->c);
  //fin de check 1er lettre
  while (dico2->c!='$' || mot2->c!='$') {       //printf("dico2 = %c \n",dico2->c);
        if (dico2->succ->alt != NULL) {
              first = dico2; motfirst = mot2;
              if (dico2->succ->c==mot2->suiv->c) {dico2=dico2->succ;  mot2=mot2->suiv;}
              else {
                  dico2=dico2->succ;
                  mot2=mot2->suiv;
                    while (dico2->alt->c!=mot2->c) {dico2=dico2->alt;}
                  first = dico2;
                  motfirst = mot2;
                  dico2=dico2->alt; //si pas de alt ? //yen a forcement un vu que le mot qu on recherche existe
              }
        }
        else {
            dico2=dico2->succ;
            mot2=mot2->suiv;
        }
  }
    //fin de preparation, le first et motfirst sont au bon endroit
    //periode de suppression de la partie voulue de l'AL
                                           // printf("first = %c , dico2 = %c \n",first->c,dico2->c);
                                           // printf("motfirst = %c , mot2 = %c \n",motfirst->c,mot2->c);
    if (first->c==dico->c && first->c==mot->c) {                //printf("fuck 1");
        Dico* rest = first->alt;
        while (first!=NULL) {dico2=first; first=first->succ; free(dico2);}
        return rest;
    }
    if (first->c==motfirst->c) {            //printf("fuck 2");
      dico2=first->succ;
      first->succ=first->succ->alt;
      while (dico2!=NULL) {first = dico2; dico2=dico2->succ; free(first);}
      return dico;
    }
    else {                                  //printf("fuck 3");
      dico2 = first->alt;
      first->alt = first->alt->alt;
      while (dico2!=NULL) {first=dico2; dico2=dico2->succ; free(first);}
      return dico;
    }
return dico;
  }


void suggestionMot2(int k, Dico* dico, Mot* mot) {

  //CA ME SAOULE PTIN !!!!! #ragequit
  //EDIT : en fait ca va
    int n=k;
    Mot * mot2;
    mot2=mot;
    print2(dico,mot2,&n);
    if(n>0){printf("il n'y a plus de mots a suggerer \n");}

}


//  PARTIE 3 -------------------------------------------------------------------------------------

Arbre* chargerABR(Arbre* dico){ //charge le fichier dans ABR
   FILE* file = fopen("dictionnaire.txt", "r");
   char line[100];

   while (fgets(line, sizeof(line), file)) {
      ajoutMot(dico, line);
   }
   fclose(file);
   return dico;


/*
  char *mot;
  mot=(char*)malloc((strlen(mot)+1)*sizeof(char));
  printf("Rentrez le mot à ajouter \n");
  scanf("%s",mot);
  ajoutMot(dico, mot);
   return dico;

*/
}

void printABR(DicoABR *dico, int* n) { //affiche les mots dans l'ordre croissant // mettre n<0 pour tt afficher
    if(dico==NULL || (*n)==0){return 0;}
    DicoABR* dico2 = dico;
    printABR(dico2->fils_gauche,n);
    if(dico2->val!= NULL){printf("%s \n",dico2->val);
}
}

void printABR2(DicoABR *dico, int* n) { //affiche les mots dans l'ordre decroissant // mettre n<0 pour tt afficher
    if(dico==NULL || (*n)==0){return 0;}
    DicoABR* dico2 = dico;
    printABR2(dico2->fils_droit,n);
    printf("%s \n",dico2->val);
    (*n)--;
    printABR2(dico2->fils_gauche,n);
}

void printABR3(DicoABR* dico, int* n,char* c){  //affiche maximum n mots inf a c
    if (dico==NULL){return 0;}
	if((*n)==0){return 0;}
    if (strcmp(dico->val,c)<=0){
        printf("%s \n",dico->val); (*n)--;
        printABR(dico->fils_gauche,n);
        printABR3(dico->fils_droit,n,c);
    }
    else{
        printABR3(dico->fils_gauche,n,c);
    }
 return 0;
}

void printABR4(DicoABR* dico, int* n,char* c){  //affiche maximum n mots sup a c
    if (dico==NULL){return 0;}
    if (strcmp(dico->val,c)>=0){
        printf("%s \n",dico->val); (*n)--;
        printABR(dico->fils_droit,n);
        printABR4(dico->fils_gauche,n,c);
    }
    else{
        printABR3(dico->fils_droit,n,c);
    }
 return 0;
}

Arbre *verimotABR(Arbre *dico){
   FILE* file = fopen("file.txt", "r"); /* should check the result */
  if(file == NULL){ printf("Erreur d'ouverture du fichier\n"); return NULL;}

  char line[20];

  while (fgets(line, sizeof(line), file)) {
    printf("%s", line);
    int b, *c, *a;
    char *sugg;
    a =rechercherMot(dico->racine, line);
    if(a != NULL){
      printf("le mot exite déjà dans l'arbre\n" );

    }
    else{
      printf("Le mot n'existe pas, que souhaitez vous faire ? \n 1-ajouter le mot au dicitionnaire ? \n 2-remplacer le mot par un mot existant \n");
      scanf("%d", &b);
      if(b==1){
        ajoutMot(dico, line);
      }
      if(b==2){
        int c;
        c=suggestionMots(dico, line, 5);
        if(c==1){
          printf("Entrez le mot que vous souhaitez remplacer\n" );
          scanf("%s",sugg );
          printf("%s\n", sugg );
          printf("Bonjour\n");
          c=rechercherMot(dico->racine, sugg);
          printf("Bonjour 2\n" );
          if(c==NULL){
            printf("Vous n'avez pas entré le bon mot\n");
          }
          else{
            printf("Il faut remplacer le mot \n" );
        }
      }
    }
  }

}


fclose(file);
return dico;
}

Dico* chargerAL(Dico *dico){
  FILE* file = fopen("dictionnaire.txt", "r"); /* should check the result */
   char line[100];

   while (fgets(line, sizeof(line), file)) {
	printf("%s", line);
  Mot* mot;
  mot=creerMotChaine(line);
  printf("mot créé\n" );
  ajoutMot2(mot, dico);

  }
return dico;
}

Dico* verimotAL(Dico* dico){

  FILE* file = fopen("file.txt", "r"); /* should check the result */
   char line[100];

   while (fgets(line, sizeof(line), file)) {
	printf("%s", line);
  Mot* mot;
  mot=creerMotChaine(line);
   int d, c=rechercheMot2(dico, mot);
   char *chaine1;
   if(c==0){ //le mot n'a pas été trouvé
     printf("Le mot n'esite pas dans le dictionaire, vous souhaitez : \n 0 - ajouter le mot \n 1 - remplacer le mot\n" );
     scanf("%d", &d);
     if(d==0){
       ajoutMot2(mot, dico);

     }
     else{
       printf("Suggestion\n" );
       suggestionMot2(5, dico, mot);
       printf("Ecrivez le mot que vous souhaitez remplacer\n" );
       scanf("%s", chaine1);
       printf(" crée : %s\n", chaine1 );
       Mot *mot4 = creerMotChaine(chaine1);
        printf("suppression\n" );
       supprimeMot2(mot4,dico);
       printf("ajout\n" );
       ajoutMot2(mot, dico);
     }
   }


   }

   fclose(file);
   return dico;
   }





void print(Dico* dico, char* tab, int i, int* n){  //print tout le sous ensemble de dico dans l'AL // IT WORKS //mettre n<0 si on veut pas lutiliser
    if(*n==0){}
  int k;
  tab[i]=dico->c;

  if (dico->succ!=NULL) {
        char tab3[100];
        for (k=0;k<100;k++) {tab3[k]=tab[k];}
        print(dico->succ,tab3,i+1,n);
  }
  else {printf("%s \n",tab);
          if((*n)>0){(*n)--;}
        }
  if (dico->alt!=NULL) {
        char tab2[100];
        for (k=0;k<100;k++) {tab2[k]=tab[k];}
        print(dico->alt,tab2,i,n);
  }
}

void print2(Dico* dico, Mot* mot,int* n){      //affiche tt le ss ensemble de dico qui commence par mot //mettre n<0 si on veut pas l'utiliser
    Dico* dico2; Mot *mot2;
  dico2 = dico;
  Dico *dico3;
  while (mot->c!=dico2->c) {                  //on cherche si ya le premier char, si oui on pointe dessu sinon on return null
    if (dico2->alt!=NULL) {dico2=dico2->alt;}
    else { printf("sous ensemble non existant \n"); return;}
  }
  //ici on a mot->c == dico2->c == dico3->c

  int i = 0;
    char tab[100];
  for(i=0;i<100;i++){tab[i]=0;}
  tab[0]=mot->c;
  i=1;

  dico3=dico2;
  mot2=mot;
  dico2=dico2->succ;
  while(mot2->c!='$') {
        if (dico2==NULL) {break;}
        if (mot2->suiv->c =='$') { break;}
        if (dico2->c==mot2->suiv->c) {dico3=dico2;  mot2=mot2->suiv;  dico2=dico2->succ; tab[i]=mot2->c; i++;}
        else {dico2=dico2->alt;}
  }
    //lolilol
    if (dico3==NULL){printf("sous ensemble non existant \n"); }

  print(dico3->succ,tab,i,n);
}


void grofree(Mot* mot){ //permet de free des Mot
Mot* mot2 = mot;
Mot* mot3 = mot->suiv;
while(mot3!=NULL){free(mot2);mot2=mot3;mot3=mot3->suiv;}
free(mot2);
return ;
}

Dico* veridicoAL(Dico* dico){
    char chaine[100];
    printf("veuillez entrer le ss ensemble recherche \n");
    scanf("%s", chaine);
    Mot* mot = creerMotChaine(chaine);
    int d=5;
    print2(dico,mot,&d);
    grofree(mot);
    printf("\n Que voulez vous faire? \n");
    printf("\n 1 - correction de ces mot \n");
    printf("\n 2 - suppression du mot \n");
    printf("\n 3 - valider \n");
    int i,a;
    scanf("%d",&i);
    if(i==1){
        printf("entrez le mot a corriger \n");
        scanf("%s", chaine );
        mot = creerMotChaine(chaine);
        if(rechercheMot2(dico,mot)==0){printf("mot nn existant \n"); grofree(mot);return dico;}
        dico = supprimeMot2(mot,dico);
        printf("entrez sa correction \n");
        scanf("%s", chaine );
        grofree(mot);
        mot = creerMotChaine(chaine);
	printf("etes vous sur de vouloir contnuer ?(1 si oui)\n");
	    scanf("%d",&a);
	    if(a!=1){grofree(mot);printf("abort the mission\n"); return dico;}
        dico = ajoutMot2(mot,dico);
        grofree(mot);
        printf("C'est bon le mot est corrige \n");
        return dico;
    }
    if(i==2){
        printf("entrez le mot a supprimer \n");
        scanf("%s", chaine);
        mot = creerMotChaine(chaine);
        if(rechercheMot2(dico,mot)==0){printf("mot nn existant \n"); grofree(mot);return dico;}
	    printf("etes vous sur de vouloir contnuer ?(1 si oui)\n");
	    scanf("%d",&a);
	    if(a!=1){grofree(mot);printf("abort the mission\n"); return dico;}
        dico = supprimeMot2(mot,dico);
        grofree(mot);
        printf("suppression done \n");
        return dico;
    }
    if(i==3){printf("good, have a nice day \n"); return dico;}
    else{printf("looser\n"); return dico;}
}

Arbre* veridicoABR(Arbre* dico){
        printf("veuillez entrer le ss ensemble recherche \n");
        char tab[100];
        int a;
        for(a=0;a<100;a++){tab[a]=0;}
        scanf("%s",tab );
        suggestionMots(dico,tab,5);
        printf("\n Que voulez vous faire? \n");
    printf("\n 1 - correction de ces mot \n");
    printf("\n 2 - suppression du mot \n");
    printf("\n 3 - valider \n");
    int i;
    scanf("%d",&i);
    if(i==1){
        printf("entrez le mot a corriger \n");
        for(a=0;a<100;a++){tab[a]=0;}
        scanf("%s", tab);
        supprimeMot(dico,tab);
        for(a=0;a<100;a++){tab[a]=0;}
        printf("entrez sa correction \n");
        scanf("%s",tab);
        printf("sur de vouloir faire ca?(1 pour oui)\n");
        scanf("%d",&a);
        if(a!=1){printf("abort \n"); return dico;}
        ajoutMot(dico,tab);
        printf("C'est bon le mot est corrige \n");
        return dico;
    }
    if(i==2){
        printf("entrez le mot a supprimer \n");
        for(a=0;a<100;a++){tab[a]=0;}
        scanf("%s" ,tab);
        printf("sur de vouloir faire ca?(1 pour oui)\n");
        scanf("%d",&a);
        if(a!=1){printf("abort \n"); return dico;}
        supprimeMot(dico,tab);
        printf("suppression done \n");
        return dico;
    }
    if(i==3){printf("good, have a nice day \n");}
    else{printf("looser\n"); return dico;}

}


/*

BONUS :
CALCULER LE TEMPS D'EXECUTION D'UNE FONCTION
GRAPHIQUE : TAILLE DE DONNEES / TEMPS
COMPARER COMPLEXITE THEORIQUE

*/
