/* -------------------------------------------------------------
   Demo hashcoding
   
   F. Balmas                                 2021
   -------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include "liste.h"
#include "hashcode.h"
#include "base.c"

#define SIZE BUFSIZ

char *table_mots[]= { "vigne", "calculer", "chemin", "route", "cartable", "crayon", "mine", "coussin", "pelochon", "cahier", "classeur", "" };
int main() {
    int i;
    int y;
    char mot[21];
    LINKED res;
  
    init_freeliste();
    init_tabhash(); 
    
    for (i=0; liste[i]!= "" ; i++) {
        printf("ajout de %s\n", liste[i], i);
        
        add_nom(liste[i]);
    }
    print_tabhash();
    printf("%d elts ajoutes\n", i);
    
    while(1) {
        scanf("%s", mot);
        if (mot[0]=='Q') break;
            res = search_nom(mot);
        if (res==NULL) {
            printf("non trouve\n");
        } else {
            printf("trouve\n");
        }
    } 
  /* pour ajouter un nom dans la table de hash :
     void add_nom(char *s);
     pour chercher un nom dans la table de hash :
     LINKED search_nom(char *nom);
     retourne pointeur sur le chaînon si trouve, NULL sinon
     pour afficher un nom de la table de hash :
     void print_nom(LINKED);
  */
    
  
  

    return EXIT_SUCCESS;
}
