//
// Created by david on 30/11/2023.
//

#include <stdio.h>
#include <malloc.h>
#include "agenda.h"
#include "stdlib.h"

char *scanString(void){

    int t_p = 0;
    int i = 0;
    char* mystr = (char*)malloc(sizeof(char));
    char c ;

    while ((c = getchar()) != '\n'){
        t_p ++;
        mystr = (char*) realloc(mystr,t_p+1 * sizeof(char));
        mystr[i] = c;
        i++;
    }
    mystr[i] = '\0';
    return mystr;
}