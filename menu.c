//
// Created by david on 06/12/2023.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "math.h"
#include "rdv.h"
#include "agenda.h"

void menu_partie_1(){
    int choix = 100;
    //tant que l'utilisateur n'arrete pas le programme:
    while (choix != 0) {
        //affichage des options utilisateur
        printf("Choisissez une option :\n");

        printf("\n1. Creer une liste\n");
        printf("0. Quiter\n");

        //faire le choix
        scanf(" %d", &choix);

        int n, val;

        if (choix == 1) {
            //choix suivants
            printf("\nChoisissez un nombre de niveau : ");
            scanf(" %d", &n);
            //création liste

            list *mylist = create_empty_list(n);

            while (choix != 0) {

                printf("\n1. Ajouter une cellule\n");
                printf("2. Afficher liste\n");
                printf("0. Quitter\n");
                scanf(" %d", &choix);

                if (choix == 1) {

                    printf("\nChoisisez un nombre de niveau : ");
                    scanf(" %d", &n);

                    printf("\nChoisissez une valeur : ");
                    scanf(" %d", &val);

                    mylist = tri_liste_croisant(mylist, n, val);
                }
                if (choix == 2) {
                    print_all_list(mylist);
                }
            }
        }
    }
}

void menu_partie_2(){
    int choix = 100;
    //tant que l'utilisateur n'arrete pas le programme:
    while (choix != 0) {
        //affichage des options utilisateur
        printf("Choisissez une option :\n");

        printf("\n1. Creer une liste\n");
        printf("0. Quiter\n");

        //faire le choix
        scanf(" %d", &choix);

        int n, val, i, j;

        if (choix == 1) {
            //choix suivants
            printf("\nChoisissez un nombre de niveau : ");
            scanf(" %d", &n);

            //création liste
            list *mylist = creer_liste_pour_n(n);

            while (choix != 0) {

                printf("\n1. Rechercher une valeur choisi");
                printf("\n2. Rechercher une valeur aleatoire");
                printf("\n3. Afficher liste");
                printf("\n0. Quitter\n");
                scanf(" %d", &choix);

                if (choix == 1) {

                    printf("\nChoisisez la valeur : ");
                    scanf(" %d", &val);
                    startTimer();
                    recherche_classique(mylist,val);
                    stopTimer();
                    printf("\nRecherche classique : ");
                    displayTime();

                    startTimer();
                    recherche_niveau_haut(mylist,val);
                    stopTimer();
                    printf("\nRecherche à partir du plus haut niveau : ");
                    displayTime();
                }

                if (choix == 2) {

                    printf("\nChoisisez le nombre d'iteration : ");
                    scanf(" %d", &i);

                    startTimer();
                    for(j = 0; j<i; j++){
                        int random = rand() % (int)pow(2,n)-1;
                        recherche_classique(mylist,random);
                    }
                    stopTimer();
                    printf("\nRecherche classique : ");
                    displayTime();

                    startTimer();
                    for(j = 0; j<i; j++){
                        int random = rand() % (int)pow(2,n)-1;
                        recherche_niveau_haut(mylist,random);
                    }
                    stopTimer();
                    printf("\nRecherche a partir du plus haut niveau : ");
                    displayTime();
                }
                if (choix == 3) {
                    print_all_list(mylist);
                }
            }
        }
    }
}



void menu_partie_3(){
    int choix = 100;
    //tant que l'utilisateur n'arrete pas le programme:
    while (choix != 0) {
        //affichage des options utilisateur
        printf("Choisissez une option :\n");

        printf("\n1. Creer une liste\n");
        printf("0. Quiter\n");

        //faire le choix
        scanf(" %d", &choix);

        int n, val, i, j;
        agenda* myagenda = create_empty_agenda(4);
        if (choix == 1) {
            while (choix != 0) {

                printf("\n2. Ajouter un contact");
                printf("\n3. Afficher agenda");
                printf("\n0. Quitter\n");
                scanf(" %d", &choix);


                if (choix == 2){
                    contact* mycontact = create_contact();
                    fflush(stdout);

                    myagenda = tri_new_contact(myagenda, mycontact);
                    printf("Afficher rdv? \n4. oui \n5. non \nchoix : ");

                    fflush(stdout);
                    scanf(" %d" , &choix);
                    fgetc(stdin);

                    //contact* mycontact = myagenda->heads[0];

                    if(choix == 4){
                        print_rdv(mycontact->rdv);
                    }
                    if (choix == 5){
                        continue;
                    }
                    //break;
                }
                if (choix == 3){
                    print_all_agenda(myagenda);
                }
            }
//creer contact, ajouter rdv a contact, afficher agenda
        }
    }
}
