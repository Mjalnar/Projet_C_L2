//
// Created by david on 30/11/2023.
//

#ifndef PROJET_C_AGENDA_H
#define PROJET_C_AGENDA_H

#include "contact.h"

typedef struct agenda{
    int max_lvl;
    struct contact** heads;
}agenda;


char *scanString(void);
agenda *create_empty_agenda(int nb_lvl);
agenda* add_val_to_head_agenda(agenda *mylist, contact * mycontact);
contact* search_contact(agenda myagenda, char* smone);
//agenda* tri_new_contact(agenda* myagenda);
agenda* tri_new_contact(agenda* myagenda, contact *new_contact);
void print_all_agenda(agenda* myagenda);
void print_lvl_agenda(agenda* myagenda, int nb_lvl);
void free_agenda(agenda* my_agenda);
#endif //PROJET_C_AGENDA_H
