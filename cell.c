//
// Created by david on 23/10/2023.
//

#include "cell.h"
#include <stdio.h>
#include <stdlib.h>

//Fonction qui va creer une cellule à niveau (nb = level) completement vide
cell* create_empty_cell(int level){
    cell* new_cell = (cell*) malloc(sizeof(cell));                                                //création du pointeur "new_cell" de type cell
    new_cell->nb_lvl = level;                                       //attribution d'une valeur level
    new_cell->next = (cell**) malloc(sizeof(cell*) * level);    //allocation mémoire
    for(int i=0; i<=level; i++){                                   //boucle pour initialiser les tetes
        new_cell->next[i] = NULL;                                  //à null.
    }
    printf("cell cree ; nb_lvl : %d\n",new_cell->nb_lvl);
    return new_cell;
}

//fonction qui ajoute une valeur (val) à la cellule
cell* add_val_cell(int level, int val){
    cell* mycell = create_empty_cell(level);    //création du pointeur et de la cellule vide
    mycell->value = val;                        //ajout de la valeur à la cellule
    printf("valeur : %d\n", mycell->value);
    return mycell;                              //retour de la cellule modifié
}