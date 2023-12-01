//
// Created by david on 23/10/2023.
//

#ifndef PROJET_LIST_H
#define PROJET_LIST_H
#include "cell.h"


typedef struct list{
    int max_lvl;
    struct cell** heads;
}list;

list* create_empty_list(int nb_lvl);
list* add_val_to_head(list *mylist, cell*);
void print_all_list(list* mylist);
void print_lvl_list(list* mylist, int nb_lvl);
list* tri_liste_croisant(list *mylist, int nb_lvl, int val);
list* creer_liste_pour_n(int n);


#endif //PROJET_LIST_H