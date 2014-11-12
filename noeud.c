/**
 * \file liste.c
 * \brief Fonctions permettant de manipuler une liste chainée
 * \author Yann Feunteun
 * \version 0.1
 * \date 1 Novembre 2014
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "noeud.h"

Noeud* remplir(Noeud *dico, FILE* flux)
{
    char buffer[512];
    while (lireMot(flux, &buffer[0])) {
        dico = inserer(dico, buffer);
    }

    return dico;
}

void afficher(Noeud* dico)
{
    if(dico == NULL) return;

    afficher(dico->gauche);
    printf("%s => %d\n", dico->mot, dico->nbOcc);
    afficher(dico->droit);
}

Noeud* inserer(Noeud* dico, char * mot)
{

    if(dico == NULL){
        dico = (Noeud*)malloc(sizeof(Noeud));
        if(dico){
            dico->droit = NULL;
            dico->gauche = NULL;
            dico->nbOcc = 1;
            dico->mot = (char*)malloc(strlen(mot));
            strcpy(dico->mot, mot);
        }
    } else {

        short comp = strcmp(dico->mot, mot);
        if (comp == 0) ++(dico->nbOcc);
        else if(comp < 0) dico->droit = inserer(dico->droit, mot);
        else dico->gauche = inserer(dico->gauche, mot);
    }

     return dico;


}

int lireMot(FILE * fp, char * mot) {
    int i;
    char c;
    while ( ! (isalpha (c = fgetc(fp)))) {
        if  (c == EOF) {
            mot[0] = '\0';
            return 0;
        }
    }
    mot[0] = c & 0xdf;
    i = 1;
    while ( isalpha (c = fgetc(fp))) {
        mot[i] = c & 0xdf;
        i++;
    }
    mot[i] = '\0';
    return 1;
}
