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

void print_rdv(rdv* allrdv){
    if(allrdv == NULL){
        printf("\nAucun rendez_vous de prevu");
    }

    int i = 1;

    while(allrdv->next != NULL){
        printf("\nRendez-vous numero %d", i);
        printf("\nDate : %d/%d/%d", allrdv->date->jour,allrdv->date->mois,allrdv->date->annee);
        printf("\nHeure : %d:%d", allrdv->heure->h,allrdv->heure->min);
        printf("\nDuree : %d:%d", allrdv->duree->h, allrdv->duree->min);
        printf("\nObjet : %s", allrdv->objet);
        allrdv = allrdv->next;
        i++;
    }
}

rdv *add_rdv_to_head(rdv* allrdv, rdv* newrdv){

    newrdv->next = allrdv->next;
    allrdv->next = newrdv;

    return allrdv;
}