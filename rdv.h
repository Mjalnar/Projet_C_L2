//
// Created by david on 05/12/2023.
//

#ifndef PROJET_C_RDV_H
#define PROJET_C_RDV_H

typedef struct date{
    int jour;
    int mois;
    int annee;
}date;

typedef struct heure{
    int h;
    int min;
}heure;

typedef struct duree{
    int h;
    int min;
}duree;

typedef struct rdv{
    date* date;
    heure* heure;
    duree* duree;
    char* objet;
    struct rdv *next;
}rdv;

date *create_empty_date();
heure *create_empty_heure();
duree *create_empty_duree();
rdv* create_empty_rdv();
date *create_date();
heure *create_heure();
duree *create_duree();
rdv *create_rdv();
void print_rdv(rdv* myrdv);
#endif //PROJET_C_RDV_H
