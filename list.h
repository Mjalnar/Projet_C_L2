//
// Created by david on 23/10/2023.
//

#ifndef PROJET_LIST_H
#define PROJET_LIST_H
#include "cell.h"


// Définition de la structure list
typedef struct list {
    int max_lvl;         // Nombre maximal de niveaux dans la liste
    struct cell** heads; // Tableau de pointeurs vers la tête de chaque niveau
} list;


// Déclaration des prototypes des fonctions pour manipuler la liste
list* create_empty_list(int nb_lvl);
list* add_val_to_head(list* mylist, cell*);
void print_all_list(list* mylist);
void print_lvl_list(list* mylist, int nb_lvl);
list* tri_liste_croisant(list* mylist, int nb_lvl, int val);
list* creer_liste_pour_n(int n);
void recherche_classique(list* mylist, int val);
void recherche_niveau_haut(list* mylist, int val);

#endif //PROJET_LIST_H
