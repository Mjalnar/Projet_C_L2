//
// Created by david on 06/12/2023.
//

#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include "timer.h"
#include "math.h"

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
                    displayTime();

                    startTimer();
                    recherche_niveau_haut(mylist,val);
                    stopTimer();
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
                    displayTime();

                    startTimer();
                    for(j = 0; j<i; j++){
                        int random = rand() % (int)pow(2,n)-1;
                        recherche_niveau_haut(mylist,random);
                    }
                    stopTimer();
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


}
