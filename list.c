//
// Created by david on 23/10/2023.
//

#include "list.h"
#include "cell.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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
    for(int i=0; i<nb_lvl; i++){
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
    cell* mycell = add_val_cell(nb_lvl, val);                  /* voir si demander a l'utilisateur nb_lvl */
    for(int i = 0; i <= mycell->nb_lvl-1; ++i){
        mycell->next[i] = mylist->heads[i];
        mylist->heads[i] = mycell;
    }
    return mylist;
}


void print_lvl_list(list* mylist, int nb_lvl){
    cell * tmp = mylist->heads[nb_lvl];
    cell * tmp2 = mylist->heads[0];
    printf("[list head_%d @-]--",nb_lvl+1);

    while(tmp != NULL){
        if (tmp->value == tmp2->value){
            printf(">[ %d|@- ]--",tmp->value);
            tmp = tmp->next[nb_lvl];
        }
        else{
            printf("-----------");
        }
        tmp2 = tmp2->next[0];
    }
    printf(">NULL\n");
}


void print_all_list(list* mylist){
    cell * tmp;
    for (int i = 0; i < mylist->max_lvl; i++){
        print_lvl_list(mylist, i);
    }
    return;
}

void tri_liste_croisant(list *mylist, cell *newcell){

    int lvl = mylist->max_lvl;
    cell **cur = mylist->heads;

    while(lvl >= 0){
        cell *temp = cur[lvl];
        if(temp->value < newcell->value){
            lvl--;
        }
        else if(temp->value > newcell->value) {
                lvl--;
                cur = temp->next;
        }
            else{
                lvl = -1;
            }
    }
    
}


list* creer_liste_pour_n(int n){
    printf("\noui");
    list* mylist = create_empty_list(n);
    printf("\n3");

    int taille_liste = pow(2,n)-1;
    int nb_niv = n;

    printf("\ntaille liste = %d", taille_liste);
    for(int i = taille_liste; i>0; i--){

        printf("\nattente numero %d", i);

        mylist = add_val_to_head(mylist,nb_niv,i);

        printf("\neffectué numero %d", i);
    }
    printf("\n4");
    return mylist;
}