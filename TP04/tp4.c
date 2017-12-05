#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

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
  DicoABR* temp=dico->fils_droit;
  
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


void suggestionMots(Arbre *dico, char* souschaine, int k){
  DicoABR *pointeur, *mot;
  pointeur=dico->racine;
  int i=k;
  while(strncmp(pointeur->val, souschaine, strlen(souschaine))!=0){
    if(strncmp(pointeur->val, souschaine, strlen(souschaine))>0){
      pointeur=pointeur->fils_gauche;
    }
    else if(strncmp(pointeur->val, souschaine, strlen(souschaine))<0){
      pointeur=pointeur->fils_droit;
    }else{
      printf("Il n'y a pas de mots contenant cette sous chaine\n");
    }
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
     return 0;
    }
  }

  /*
  DicoABR* y, *z, *x;
  y=pointeur;
  while (k>0 && y->pere != NULL) {
    y=y->pere;
    z=y->fils_droit;
    x=y->fils_gauche;
    printf("Valeur %d : %s \n", k, y->val);
    k--;
    while(z != NULL && k>0){
      if(strncmp(z->val, souschaine, sizeof(souschaine))==0){
        printf("Valeur %d : %s \n",k, z->val );
        k--;
      }
      z=z->fils_droit;

    }

    while(x != NULL && k>0){
      if(strncmp(x->val, souschaine, sizeof(souschaine))==0){
        printf("Valeur %d : %s \n",k, x->val );
        k--;
      }
      x=x->fils_gauche;
//NON !!!!

    }

  }
  if(k>0){printf("Il n'y a pas d'autres valeurs correspondant au suffixe donné \n");}
*/


}



/*
void parcours_infixe(DicoABR *mot, int k, char *souschaine){
  while(mot != NULL && k>0){
    if(mot->fils_gauche !=NULL){
      parcours_infixe(mot->fils_gauche, k, souschaine);
    }
    if(mot->fils_droit != NULL){
    parcours_infixe(mot->fils_droit, k, souschaine);
    }
//    if(strncmp(mot->val, souschaine, sizeof(souschaine))==0){
      printf("Valeur n° %d : %s \n", k, mot->val);
      k=k-1;
  //  }
  }
}



dico initDico2(dico dico, mot mot){
  if(dico==null){
    return dico;
}
  else{
  dico=malloc(sizeof(dico))
  dico->c=mot->c;
  dico->suicant=NULL;
  dico->alt=NULL;
  dico->succ=initDico2(dico-> succ   , mot->suivant)
  return dico
}
}

int recherchermot2(mot m, dico d){
  if(m!=NULL && d!=NULL){
    if(m->c == d->c && m->c=='$'){
      return1;
  }
  else{
    if(m->c==d->c){
    return recherchermot2(m->suivant, d->succ)
    else{
      if(d->alt!=NULL && d->alt->c<=m->c){
        return recherchermot2(m, d->alt);

      }
      else{
      return 0
    }
    }
    else{
      return 0;
    }
  }
  }
  }
}
}
}



Dico ajoutMot2(Mot mot, Dico dico) {

  

}

BONUS :
CALCULER LE TEMPS D'EXECUTION D'UNE FONCTION
GRAPHIQUE : TAILLE DE DONNEES / TEMPS
COMPARER COMPLEXITE THEORIQUE

*/
