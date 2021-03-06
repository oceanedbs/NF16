#include "TP03.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 20

T_Element *creerElement(char *val) {
  T_Element *new_elemt;
  new_elemt = malloc(sizeof(*new_elemt));
  if (new_elemt == NULL) {
    printf("Erreur d'allocation mémoire pour l'élément");
  } else {
    strcpy(new_elemt->valeur, val);
    new_elemt->suivant = NULL;
    new_elemt->precedent = NULL;
  }
  return new_elemt;
}

T_Liste *creerListe() { // OK
  T_Liste *new_lst;
  new_lst = malloc(sizeof(*new_lst));
  if (new_lst == NULL) {
    printf("Erreur d'allocation pour la liste");
  } else {
    new_lst->taille = 0;
    new_lst->tete = NULL;
    new_lst->queue = NULL;
  }

  return new_lst;
}

int insererElement(T_Liste *list, char *val) { // OK
  T_Element *new_elemt, *pointeur;
  pointeur = list->tete;
  new_elemt = creerElement(val);
  int i = 0, cmp;

  if (list == NULL) {
    return -1;
  } else {
    if (list->taille == 0) { // la liste est vide
      list->tete = new_elemt;
      list->queue = new_elemt;
      list->taille++;
      return 0;

    } else {
      if (strcmp(list->queue->valeur, val) < 0) { // insertion en fin de liste

        new_elemt->precedent = list->queue;
        list->queue->suivant = new_elemt;
        list->queue = new_elemt;

        list->taille++;
        return 0;

      } else {
        while (i < list->taille) {
          cmp = strcmp(pointeur->valeur, val);

          if (cmp != 0) {
            if (cmp > 0) {
              if (i == 0) { // insertion en tete de liste
                list->tete->precedent = new_elemt;
                new_elemt->suivant = pointeur;
                list->tete = new_elemt;
              } else { // insertion n'importe ou dans la liste
                new_elemt->suivant = pointeur;
                new_elemt->precedent = pointeur->precedent;
                pointeur->precedent->suivant = new_elemt;
                pointeur->precedent = new_elemt;
              }
              list->taille++;
              return 0;
            } else {

              if (i == list->taille) { // insertion en fin de liste

                new_elemt->precedent = list->queue;
                list->queue->suivant = new_elemt;
                list->queue = new_elemt;

                list->taille++;
                return 0;
              }
              i++;
              pointeur = pointeur->suivant;
            }
          } else {
            return -1;
          }
        }
      }
    }
  }
  return -1;
}

T_Element *rechercherElement(T_Liste *list, char *val) { // OK
  T_Element *pointeur = list->tete;

  if (strcmp(list->queue->valeur, val) < 0 ||
      strcmp(list->tete->valeur, val) > 0) {
    return NULL;
  } else {

    while (pointeur != NULL) {
      if (strcmp(pointeur->valeur, val) == 0) {
        return pointeur;
      } else if (strcmp(pointeur->valeur, val) > 0) {
        return NULL;
      }

      else {
        pointeur = pointeur->suivant;
      }
    }

    return NULL;
  }
}

int supprimerElement(T_Liste *list, char *val) { // OK

  if ((list->taille == 1) && (strcmp(list->tete->valeur, val) == 0)) {
    free(list->tete);
    list->tete = NULL;
    list->queue = NULL;
    list->taille = 0;
    return 0;
  }
  T_Element *a;
  a = rechercherElement(list, val);
  if (a == NULL) {
    return -1;
  } else if (a->precedent == NULL) {
    a->suivant->precedent = NULL;
    list->tete = a->suivant;
    free(a);
    list->taille = list->taille - 1;
    return 0;
  } else if (a->suivant == NULL) {
    list->queue = a->precedent;
    a->precedent->suivant = NULL;
    free(a);
    list->taille = list->taille - 1;
    return 0;
  } else {
    a->suivant->precedent = a->precedent;
    a->precedent->suivant = a->suivant;
    free(a);
    list->taille = list->taille - 1;
    return 0;
  }
}

int supprimerListe(T_Liste ** list) {

  if (*list != NULL) {
    T_Element *a = (*list)->tete;
    while (a != NULL) {
      T_Element *b = a;
      a = a->suivant;
      free(b);
      b = NULL;

    }
    (*list)->tete = NULL;
    (*list)->queue = NULL;
    (*list)->taille = 0;
    free(*list);
    (*list) = NULL;
    return 0;
  }
  return -1;
}

T_Liste *fusionnerListes(T_Liste *list1, T_Liste *list2) { // OK

  // cas listes vides
  // check la plus petite tete
  // remplir 3e list tete et retirer de l'autre l'element (use supprElem)
  T_Liste *res;
  int a;
  char *k;
  if (list1->taille == 0) {
    return list2;
  }
  if (list2->taille == 0) {
    return list1;
  }
  res = creerListe();

  while ((list1->taille != 0) && (list2->taille != 0)) {
    a = strcmp(list1->tete->valeur, list2->tete->valeur);
    if (a < 0) { // list1 plus petit
      k = list1->tete->valeur;
      insererElement(res, k);
      supprimerElement(list1, k);
    }
    if (a == 0) { // same faut prendre un et delete 1&2
      k = list1->tete->valeur;
      insererElement(res, k);
      supprimerElement(list1, k);
      supprimerElement(list2, k);
    }
    if (a >= 1) { // list2 plus petit
      k = list2->tete->valeur;
      insererElement(res, k);
      supprimerElement(list2, k);
    }
  }
  // 1 ou 2 est vide a ce moment
  if (list1->taille == 0) {

    while (list2->taille != 0) {
      k = list2->tete->valeur;
      insererElement(res, k);
      supprimerElement(list2, k);
    }
    supprimerListe(&list1);
    supprimerListe(&list2);
  }
  if (list2->taille == 0) {

    while (list1->taille != 0) {
      k = list1->tete->valeur;
      insererElement(res, k);
      supprimerElement(list1, k);
    }
    supprimerListe(&list1);
    supprimerListe(&list2);
  }

  return res;
}

int afficher(T_Liste *list) {

  if (list->taille == 0) {
    return -1;
  }
  T_Element *a;
  int i = 1;
  a = list->tete;
  printf("\n Affichage de la liste \n");
  while (a != NULL) {

    printf("element %d | %s \n", i, a->valeur);
    i++;
    a = a->suivant;
  }
  return 0;
}

int menu() {

  int a = 8;
  char k;
  printf("Menu general : que voulez vous faire? \n");
  printf("1. creer une liste \n");
  printf("2. ajouter un element dans une liste \n");
  printf("3. supprimer un element d'une liste \n");
  printf("4. rechercher un element dans une liste \n");
  printf("5. afficher les elements d'une liste \n");
  printf("6. supprimer une liste \n");
  printf("7. fusionner deux listes \n");
  printf("8.  Quitter \n");

  if ((scanf("%d%c", &a, &k) == 2) && (a < 9) && (a > 0) && (k == '\n')) {
    return a;
  } else {
    a = 0;
    printf("veuillez entrer une valeur juste la prochaine fois! ><' \n");
    return 8;
  }
}

int tableau_vide(T_Liste *tab[]) {
  int k, vide = 0;

  for (k = 0; k <= TAILLE; k++) {
    if (tab[k] != NULL) {
      vide = 1;
      break;
    }
  }
  return vide;
}
