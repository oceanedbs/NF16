/*	#include<stdio.h>
        #include<stdlib.h>
        #include <string.h>
        #include "TP03.h"



FONCTION PRGRM PRINCIPAL -> faire menu interactif (toutes les fonctions sont
pretes)
1. CrÃ©er une liste
2. Ajouter un Ã©lÃ©ment dans une liste
3. Supprimer un Ã©lÃ©ment dâ€™une liste
4. Rechercher un Ã©lÃ©ment dans une liste
5. Afficher les Ã©lÃ©ments dâ€™une liste
6. Supprimer une liste
7. Fusionner deux listes
8. Quitter



*/

#include "TP03.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 20

int main() {
  int a, i = 0, k;
  T_Element *j;
  int b, c, d = 0;
  char v[20];
  T_Liste *tab[TAILLE];
  T_Liste *list;
  for (a = 0; a <= TAILLE; a++) {
    tab[a] = NULL;
  }
  while (1) {
    a = 0;
    a = menu();
    if (a == 8) {
      for (d = 0; d <= TAILLE; d++) {
        supprimerListe(tab[d]);
      }
      printf("Au revoir !\n");
      return 0;
    }
    if (a == 1) {
      d = 0;
      for (i = 0; i <= TAILLE; i++) {
        if (tab[i] == NULL) {
          tab[i] = creerListe();
          printf("liste cree sous tab[%d] \n", i);
          break;
        }
        d++;
      }
      if (d == TAILLE+1) {
        printf("pas assez de place pour mettre d'autres liste, veuillez en "
               "supprimer une ancienne \n");
      }
    }
    if (a == 2) {
      k = tableau_vide(tab);

      if (k == 1) {
        printf("veuillez choisir la liste concernee (entrer l'indice du "
               "tableau) \n");
        if ((scanf("%d", &b) == 1) && (b <= TAILLE) && (b >= 0)) {
          if (tab[b] == NULL) {
            printf("indice incorrect, pas de liste ici \n");
          } else {
            list = tab[b];
            printf("entrez la valeur a inserer \n");
            if (scanf("%s", v) == 1) {
              i = insererElement(list, v);
              if (i == 0) {
                printf("insertion reussie \n");
              }
              if (i == -1) {
                printf("insertion failed, la valeur est d�j� dans la liste \n");
              }
            }
          }
        } else {
          printf("veuillez entrer une valeur correcte \n");
        }
      } else {
        printf("Aucune liste n'a ete cree \n");
      }
    }
    if (a == 3) {

      k = tableau_vide(tab);

      if (k == 1) {

        printf("veuillez choisir la liste concernee (entrer l'indice du "
               "tableau) \n");
        if ((scanf("%d", &b) == 1) && (b <= TAILLE) && (b >= 0)) {
          if (tab[b] == NULL) {
            printf("indice incorrect, pas de liste ici \n");
          } else {
            list = tab[b];
            printf("entrez la valeur a supprimer \n");
            if (scanf("%s", v) == 1) {
              i = supprimerElement(list, v);
              if (i == 0) {
                printf("suppression reussie \n");
              }
              if (i == -1) {
                printf("suppression failed, élement non trouvé \n");
              }
            }
          }
        } else {
          printf("veuillez entrer une valeur correcte \n");
        }

      } else {
        printf("Aucune liste n'a ete cree \n");
      }
    }
    if (a == 4) {

      k = tableau_vide(tab);

      if (k == 1) {

        printf("veuillez choisir la liste concernee (entrer l'indice du "
               "tableau)\n");
        if ((scanf("%d", &b) == 1) && (b <= TAILLE) && (b >= 0)) {
          if (tab[b] == NULL) {
            printf("indice incorrect, pas de liste ici \n");
          } else {
            list = tab[b];
            printf("entrez la valeur a rechercher \n");
            if (scanf("%s", v) == 1) {
              j = NULL;
              j = rechercherElement(list, v);
              if (j == NULL) {
                printf("element introuvable \n");
              } else {
                printf("element found \n");
              }
            }
          }
        } else {
          printf("veuillez entrer une valeur correcte \n");
        }

      } else {
        printf("Aucune liste n'a ete cree \n");
      }
    }
    if (a == 5) {

      k = tableau_vide(tab);

      if (k == 1) {
        printf("veuillez choisir la liste concernee (entrer l'indice du "
               "tableau) \n");
        if ((scanf("%d", &b) == 1) && (b <= TAILLE) && (b >= 0)) {
          if (tab[b] == NULL) {
            printf("indice incorrect, pas de liste ici \n");
          } else {
            i = afficher(tab[b]);
            if (i == 0) {
              printf("everything is ok \n");
            }
            if (i == -1) {
              printf("everything is shit \n");
            }
          }
        } else {
          printf("veuillez entrer une valeur correcte \n");
        }

      } else {
        printf("Aucune liste n'a ete cree \n");
      }
    }
    if (a == 6) {

      k = tableau_vide(tab);

      if (k == 1) {

        printf("veuillez choisir la liste concernee (entrer l'indice du "
               "tableau) \n");
        if ((scanf("%d", &b) == 1) && (b <= TAILLE) && (b >= 0)) {
          if (tab[b] == NULL) {
            printf("indice incorrect, pas de liste ici \n");
          } else {
            i = supprimerListe(tab[b]);
            tab[b] = NULL;
            if (i == 0) {
              printf("everything is ok \n");
            }
            if (i == -1) {
              printf("everything is shit \n");
            }
          }
        } else {
          printf("veuillez entrer une valeur correcte \n");
        }

      } else {
        printf("Aucune liste n'a ete cree \n");
      }
    }
    if (a == 7) {

      k = tableau_vide(tab);

      if (k == 1) {
        printf("veuillez choisir la premiere liste concernee (entrer l'indice "
               "du tableau) \n");
        if ((scanf("%d", &b) == 1) && (b <= TAILLE) && (b >= 0)) {
          if (tab[b] == NULL) {
            printf("indice incorrect, pas de liste ici \n");
          } else {
            printf("veuillez choisir la deuxieme liste concernee (entrer "
                   "l'indice du tableau) \n");
            if ((scanf("%d", &i) == 1) && (i <= TAILLE) && (i >= 0)) {
              if (tab[i] == NULL) {
                printf("indice incorrect, pas de liste ici \n");
              } else {
                list = fusionnerListes(tab[i], tab[b]);
                tab[i] = list;
                tab[b] = NULL;
                printf("la nouvelle liste a prit la place de la liste numero "
                       "%d \n",
                       i);
              }
            } else {
              printf("veuillez entrer une valeur correcte \n");
            }
          }
        }

      } else {
        printf("Aucune liste n'a ete cree \n");
      }
    }
  }
  return 0;
}
