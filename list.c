//
// Created by david on 23/10/2023.
//

#include "list.h"
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>

/*fonction création de list et initialisé à null
pointeur list
attribution de valeur
allocation dynamique
boucle pour initialiser les tetes
    à null.
retour de la nouvelle liste*/

list* create_empty_list(int nb_lvl){                               /* voir si demander a l'utilisateur nb_lvl */
    list* new_list = (list*) malloc(sizeof(list));
    new_list->max_lvl = nb_lvl;
    new_list->heads = (cell**) malloc(sizeof(cell*)*nb_lvl);
    for(int i=0; i<=nb_lvl; i++){
        new_list->heads[i] = NULL;
    }
    printf("liste cree\n");
    return new_list;
}



/*fonction qui ajoute une valeur à la cellule
creation d'une cellule avec ces valeurs
    si il n'y a rien dans la liste
        on ajoute une cellule à la liste
        tout les niveau inférieur ont la meme valeur
    dans le cas ou la liste est pas vide
        on ajoute une cellule à la liste et on la fait pointer niveau suivant vers la cellule suivante
retour de notre liste*/

list* add_val_to_head(list *mylist, int nb_lvl, int val){
    cell* mycell = add_val_cell(nb_lvl, val);            /* voir si demander a l'utilisateur nb_lvl */
    cell* temp;
    for(int i = nb_lvl-1; i >= 0; i--){
        printf("tu est la \n");
        if (mylist->heads[i] == NULL){
            printf("ici ; ");
            mylist->heads[i] = mycell;
            printf("null : %d\n",mylist->heads[i]->value);
        }
        else{
            printf("la ; ");
            temp = mylist->heads[i];
            mylist->heads[i] = mycell;
            mycell->next[i] = temp;
            printf("avec val : %d\n",mylist->heads[i]->value);
        }
    }
    return mylist;
}


void print_lvl_list(list* mylist, int nb_lvl){
    cell * tmp;
    if (mylist->heads[0] == NULL){
        printf("[list head_%d @-]--> NULL",nb_lvl-1);
    }
    tmp = mylist->heads[nb_lvl];
    printf("[list head_%d @-]-->",nb_lvl-1);
    while(tmp != NULL){
        printf("[ %d|@- ]-->",tmp->value);
        tmp = tmp->next[nb_lvl-1];
    }
    printf(" NULL\n");
    return;
}


void print_all_list(list* mylist){
    cell * tmp;
    if (mylist->heads[0] == NULL){
        for (int i = 0; i < mylist->max_lvl; i++){
            printf("[list head_%d @-]--> NULL",i);
        }
        return;
    }
    for (int i = 0; i < mylist->max_lvl; i++){
        tmp = mylist->heads[i];
        printf("[list head_%d @-]-->",i);
        while(tmp != NULL){
            printf("[ %d|@- ]-->",tmp->value);
            tmp = tmp->next[i];
        }
        printf(" NULL\n");
    }
    return;
}