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
    cell* mycell = add_val_cell(nb_lvl, val);                      /* voir si demander a l'utilisateur nb_lvl */
    for(int i = 0; i <= mycell->nb_lvl-1; ++i){
        mycell->next[i] = mylist->heads[i];
        mylist->heads[i] = mycell;



        /*if (mylist->heads[i] == NULL){
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
        }*/

    }
    return mylist;
}


void print_lvl_list(list* mylist, int nb_lvl){
    cell * tmp = mylist->heads[nb_lvl];
    printf("[list head_%d @-]-->",nb_lvl+1);
    //cell * tmp2 = mylist->heads[0];
    //int i = 0;
    while(tmp != NULL){
        if (tmp->value == tmp2->value){
            printf("[ %d|@- ]-->",tmp->value);
            tmp = tmp->next[nb_lvl];
            //tmp2->value = mylist->heads[0]->value-1;
            //tmp2->value -=1;
        }
        else{
            printf("non\n");
            //tmp2->value -=1;
            //return;
        }

    }
    printf(" NULL\n");
    //tmp2 = mylist->heads[0];
    return;
}


void print_all_list(list* mylist){
    cell * tmp;
    for (int i = 0; i < mylist->max_lvl; i++){
        print_lvl_list(mylist, i);
    }
    return;
}