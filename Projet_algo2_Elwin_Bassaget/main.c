#include <stdio.h>
#include <stdlib.h>
#include "string.h"

struct arbre{
    char id[10];
    int length;
    int token;
    int countdoublon;
    struct arbre *pattern;
    struct arbre *doublon;
};
typedef struct arbre *Arbre;

void printPatterns(Arbre *a);
void ajouter(Arbre *a, char *tablettre, int length, int token);
void motif1(Arbre *a, char *tablettre);
void motif2(Arbre *a,char *tablettre);
//void sorting(Arbre *a);

int main(){
    Arbre pattern1 = NULL;
    Arbre pattern2 = NULL;

    printf("alphabet à remplir avec BSGE \n\n"

           "motifs à rechercher: BSG*E* BS+GE? \n\n"

           "* le caractère précedent apparait - de 0 à n fois\n"
           "+ le caractère précedent apparait de 1 à n fois\n"
           "? le caractère précedent apparait de 0 ou 1 fois\n\n");

    char lettres[4] = {'B','S','G','E'};
    char tablettre[150];
    for (int x = 0; x < 150; x++){
        tablettre[x] = lettres[rand()% 4];
        printf("%c", tablettre[x]);
    }
    printf("\n");
    //motif1(&pattern1,tablettre);
    motif2(&pattern2,tablettre);
}
// motif n°1
void motif1(Arbre *a, char *tablettre){
    int count = 0;
    for (int x = 0 ; x < 150; x++){
        int length = 0 ;
        int token;
        if (tablettre[x] == 'B' && tablettre[x+1] == 'S'){
            count += 1;
            token = x;
            length +=2;
            if ( tablettre[x+length] == 'G') {
                length +=1;
                while (tablettre[x + length] == 'G'){
                    length +=1;

                }
            }
            if ( tablettre[x+length] == 'E') {
                length +=1;
                while (tablettre[x + length] == 'E'){
                    length +=1;
                }
            }
            // Storage de l'occurence trouvé dans un array
            char occur[10];
            int i =0;
            for (int y = token; y < token+length; y++ ){
                occur[i] = tablettre[y];
                i++;
            }
            occur[i] = '\0';
            ajouter(a, occur, length, token);
        }
    }
    //sorting(a);
    printPatterns(a);
    printf("\n\nNombre total d'occurence trouvé : %d\n", count);
}

// Motif n°2
void motif2(Arbre *a, char *tablettre){
    int count = 0;
    for (int x = 0 ; x < 150; x++){
        int length = 0 ;
        int token;
        if (tablettre[x] == 'B' && tablettre[x+1] == 'S'){
            token = x;
            length +=2;
            while (tablettre[x + length] == 'S'){
                length +=1;
            }
            if ( tablettre[x+length] == 'G') {
                count += 1;
                length += 1;
                if (tablettre[x+length] == 'E'){
                    length += 1;
                }
                // Storage de l'occurence trouvé dans un array
                char occur[10];
                int i =0;
                for (int y = token; y < token+length; y++ ){
                    occur[i] = tablettre[y];
                    i++;
                }
                occur[i] = '\0';
                ajouter(a, occur, length, token);
            }
        }
    }
    //sorting(a);
    printPatterns(a);
    printf("\nNombre total d'occurence trouvé : %d\n", count);
}

// Créer et sauve les occurences dans une struct
void ajouter(Arbre *a, char *tablettre, int length, int token){
    if(*a==NULL){
        *a=(Arbre)malloc(sizeof(struct arbre));
        strcpy((*a)->id, tablettre);
        (*a)->length = length;
        (*a)->token = token;
        (*a)->doublon=NULL;
        (*a)->pattern=NULL;
        (*a)->countdoublon = 1;
    }
    else if (strcmp((*a)->id, tablettre) == 0){
        (*a)->countdoublon +=1;
        ajouter(&(*a)->doublon, tablettre, length, token);
    }
    else ajouter(&(*a)->pattern, tablettre, length, token);

}
// Imprime les occurences trouvé
void printPatterns(Arbre *a){
    if (*a == NULL)
        return;
    printf("\n");
    printf("Occurence : %s | position : %d | longueur : %d | Répétition : %d", (*a)->id, (*a)->token, (*a)->length,
           (*a)->countdoublon);
    printPatterns(&(*a)->pattern);


}
/*
void sorting(Arbre *a) {
    Arbre *mem =(Arbre)malloc(sizeof(struct arbre));
    if (*a == NULL)
        return;
    if ((*a)->length < (*a)->pattern->length) {
        mem = &((*a)->pattern);
        (*a)->pattern = *a;
        a = mem;
    }
    sorting(a);
}
*/