//
// Created by david on 05/12/2023.
//

#include "rdv.h"
#include "stdlib.h"
#include <stdio.h>
#include "agenda.h"

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

/*
 * creer un rdv (un contacte peut avoir plusieurs rdv)
 * creer un rdv en demander (heure date durer objet etc)
 * int ok
 * str -> scanstring dans agenda
 * les rdv se stock dans les contacts
 * rdv stocké en liste chainee pour pouvoir avoir n rdv
 * mettre rdv en tete
 */

date *create_date(){
    date *new_date = create_empty_date();

    printf("\nEntrez la date (JJ/MM/AAAA) : ");
    char *date_str = scanString();

    sscanf(date_str, "%d/%d/%d", &(new_date->jour), &(new_date->mois), &(new_date->annee));

    free(date_str);

    return new_date;
}

heure *create_heure(){
    heure *new_heure = create_empty_heure();

    printf("\nEntrez l'heure (HH:MM) : ");
    char *heure_str = scanString();

    sscanf(heure_str, "%d:%d", &(new_heure->h), &(new_heure->min));

    free(heure_str);

    return new_heure;
}

duree *create_duree(){
    duree *new_duree = create_empty_duree();

    printf("\nEntrez la duree (HH:MM) : ");
    char *duree_str = scanString();

    sscanf(duree_str, "%d:%d", &(new_duree->h), &(new_duree->min));

    free(duree_str);

    return new_duree;
}

rdv *create_rdv(){
    rdv *new_rdv = create_empty_rdv();

    new_rdv->date = create_date();
    new_rdv->heure = create_heure();
    new_rdv->duree = create_duree();

    printf("\nEntrez l'objet du rendez-vous : ");
    new_rdv->objet = scanString();

    return new_rdv;
}

void print_rdv(rdv* myrdv){
    printf("\nDate : %d/%d/%d", myrdv->date->jour,myrdv->date->mois,myrdv->date->annee);
    printf("\nHeure : %d:%d", myrdv->heure->h,myrdv->heure->min);
    printf("\nDuree : %d", myrdv->duree->min);
    printf("\nObjet : %s", myrdv->objet);
}

