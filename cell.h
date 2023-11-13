//
// Created by david on 23/10/2023.
//

#ifndef PROJET_CELL_H
#define PROJET_CELL_H

typedef struct cell{
    int value;
    int nb_lvl;
    struct cell **next;
}cell;

cell* create_empty_cell(int level);
cell* add_val_cell(int level, int val);

#endif //PROJET_CELL_H
