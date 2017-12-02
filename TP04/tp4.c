#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include "tp4.h"

DicoABR* initDico(char* valeur){
  DicoABR *new_dico;
  new_dico=malloc(sizeof(DicoABR));
  if(new_dico!=NULL){
    new_dico->val=valeur;
    new_dico->pere=NULL;
    new_dico->fils_droit=NULL;
    new_dico->fils_gauche=NULL;
  }
  else{
    printf("Erreur d'allocation mémoire\n");
  }

  return new_dico;
}

DicoABR *ajoutMot(DicoABR *dico, char *valeur){
  DicoABR* new_mot;
  new_mot=malloc(sizeof(DicoABR));
  if(new_mot!=NULL){
    new_mot->val = valeur;
    new_mot->pere=NULL;
    new_mot->fils_gauche=NULL;
    new_mot->fils_droit=NULL;
    if(dico != NULL){
      DicoABR* pointeurx, *pointeury;
      pointeurx=dico;
      pointeury=NULL;

      while(pointeurx!=NULL){
        pointeury=pointeurx;
        if(strcmp(pointeurx->val, valeur)>0){
          pointeurx=pointeurx->fils_gauche;
        }
        else if(strcmp(pointeurx->val, valeur)<0){
          pointeurx=pointeurx->fils_droit;
        }
        if(strcmp(pointeury->val, valeur==0)){
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
  return(new_mot);

}

DicoABR* rechercherMot(DicoABR* dico, char* valeur) {
  DicoABR* dic = dico;
  while (dic->val!=valeur && dic!=NULL) {
    if (strcmp(dic->val,valeur)>0) {dic = dic->fils_gauche;}
    if (strcmp(dic->val,valeur)<0) {dic = dic->fils_droit;}
  }
  if (dic==NULL) {printf("not found :( \n");}
  if (dic->val == valeur) {printf("word found :D \n");}
  return dic;
}

DicoABR* mini(DicoABR* dico) {
  DicoABR* temp = dico->fils_droit;
  while (temp->fils_gauche!=NULL) {
    temp = temp->fils_gauche;
  }
  return temp;
}

int supprimeMot(DicoABR* dico, char* valeur) {
  DicoABR* dic = rechercherMot(dico,valeur);
  DicoABR* temp;
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

  }
}


void suggestionMots(DicoABR *dico, char* souschaine, int k){
  DicoABR *pointeur;
  pointeur=dico;
  while(strcnmp(pointeur->val, souschaine, sizeof(souschaine))!=0){
    if(strcmp(pointeur->val, souschaine)>0){
      pointeur=pointeur->fils_gauche;
    }
    else if(strcmp(pointeur->val, souschaine)<0){
      pointeur=pointeur->fils_droit;
    }
    else{
      printf("Il n'y a pas de mots contenant cette sous chaine\n", );
    }
    //choix : on affiche les n
  }


}


/*
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

BONUS :
CALCULER LE TEMPS D'EXECUTION D'UNE FONCTION
GRAPHIQUE : TAILLE DE DONNEES / TEMPS
COMPARER COMPLEXITE THEORIQUE
