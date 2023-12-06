//
// Created by david on 05/12/2023.
//

#include "rdv.h"
#include "stdlib.h"

date *create_empty_date(){
    date* new_date = (date*)malloc(sizeof(date));
    return new_date;
}

heure *create_empty_heure(){
    heure* new_heure = (heure*)malloc(sizeof(heure));
    return new_heure;
}

duree *create_empty_duree(){
    duree* new_duree = (duree*)malloc(sizeof(duree));
    return new_duree;
}

rdv* create_empty_rdv(){
    rdv* new_rdv = (rdv*)malloc(sizeof(rdv));
    new_rdv->date = create_empty_date();
    new_rdv->heure = create_empty_heure();
    new_rdv->duree = create_empty_duree();
    new_rdv->objet = NULL;
    new_rdv->next = NULL;
    return new_rdv;
}