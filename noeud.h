/**
 * \file hashtable.h
 * \brief Header du fichier liste.c
 * \author Yann Feunteun
 * \version 0.1
 * \date 1 Novembre 2014
 *
 */

#ifndef NOEUD_H
#define NOEUD_H


/**
 * \struct Information
 * \brief Objet Information
 *
 * Information est un petit objet de gestion de duet mot-nombre d'occurence du mot dans un texte.
 * C'est un quantum de liste chaînée.
 */
typedef struct noeud {
    char * mot; /*!< Un mot du texte. */
    int nbOcc;  /*!< Le nombre d'occurence de ce mot dans le texte. */
    struct noeud * gauche; /*!< Un pointeur sur l'élément suivant de la structure liste. */
    struct noeud * droit; /*!< Un pointeur sur l'élément suivant de la structure liste. */
}Noeud;


/**
 * \fn Information *remplir(Information* dico, FILE* flux)
 * \brief Remplir la structure avec les mots du fichier correspondant à flux.
 * \param dico Un pointeur sur l'index à remplir.
 * \param flux Un flux de données comprenant les mots à ajouter à l'index.
 * \return Un pointeur sur la structure remplie à partir de flux.
 * */
Noeud *remplir(Noeud* dico, FILE* flux);

/**
 * \fn void afficher(Information* dico)
 * \brief Afficher le contenu de la structure sous la forme d'un duet <mot => nombre d'occurence>.
 * \param dico Un pointeur sur l'index à afficher.
 **/
void afficher(Noeud *dico);


/**
 * \fn Information* insererEnTete(Information* dico, char * mot)
 * \brief Ajoute un élément en tête de la structure liste.
 * \param dico Un pointeur sur la structure.
 * \param mot Le le mot à ajouter à la structure.
 * \return Un pointeur sur la structure mise à jour.
 * */
Noeud *inserer(Noeud* dico, char * mot);

/**
 * \fn int lireMot(FILE * fp, char * mot)
 * \brief Lit un mot dans flux de données et remplit le tableau mot.
 * La chaine est convertie en majuscule.
 * \param fp Un flux de données comprenant les mots à lire.
 * \param mot Une chaine de caractères qui sera ramplie avec le mot lu.
 * \return Retourne 1 si un mot a été lu, 0 sinon.
 * */
int lireMot(FILE * fp, char * mot);

#endif // NOEUD_H
