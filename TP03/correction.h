

int insererElement(T_Liste *list, char *val) {
  T_element *new_elemt, tete, recherche;
  tete = list->tete;
  new_elemt = creerElement(val);
  int i, cmp;

  if (list == NULL) {
    return -1;
  } else {
    if (list->taille != 0) {
      while (i < list->taille) {
        cmp = strcmp(list->valeur, val);

        if (cmp != 0) {
          if (i == 0) {
            new_elemt->suivant = tete;
            tete->precedent = new_elemt;
            tete = new_elemt;

            list->taille++;
            return 0;

          } else if (strcmp(list->queue, val) < 0) {
            new_elemt->precedent = list->queue list->queue->precedent =
                new_elemt;
            list->queue = new_elemt;

            list->taille++;
            return 0;

          } else {
            while (strcmp(tete->valeur, val) < 0) {
              tete = tete->suivant;
            }
            new_elemt->suivant = tete;
            new_elemt->precedent = tete->precedent tete->precedent = new_elemt;
            tete->precedent->suivant = new_elemt;

            list->taille++;
            return 0;
          }
        }
      }
      else return -1;
    } else {
      tete = new_elemt;
      list->queue = new_elemt;

      list->taille++;
      return 0;
    }
  }
}
