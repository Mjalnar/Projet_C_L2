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
list* add_val_to_head(list *mylist, int nb_lvl, int val);
void print_all_list(list* mylist);
void print_lvl_list(list* mylist, int nb_lvl);


#endif //PROJET_LIST_H