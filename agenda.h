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
agenda *create_empty_list(int nb_lvl);

#endif //PROJET_C_AGENDA_H
