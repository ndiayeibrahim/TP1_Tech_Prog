#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100




// Vous devez ajouter ce #pragma a tous vos fichiers .h de votre projet.
// Il garantit que le fichier "header" n'est inclus qu'une seule fois par compilation,
// ce qui evite les erreurs de redefinition et les conflits de symboles.
#pragma once

// Vous devez definir les structures et fonctions que vous voulez exposer dans les "headers"
// Si jamais vous avez des fonctions avec des noms commun, vous devez les prefixer pour eviter des conflits de symboles
// Le prefix peut etre le nom de votre projet, exemple: forhonor_nom_de_fonction


// Structure pour représenter les Items
typedef struct Item {
    char nom[100];
    int valeur;
} Item;

// structure pou représenter les inventaire
typedef struct Inventaire {
    Item* item;
    struct Inventaire* Next;
} Inventaire;

extern int total_items;
extern Item liste_items[];
// chapgpt m'a suggéré d'utilser extern car sans la extern j'avais tout le temps des erreurs mais il m'a permit de le déclarer alors qu'il est défini dans le implementation.c

// Fonction pour créer un nouvel inventaire 
Inventaire* monprojet_createInventaire(void);

// Fonction pour ajouter un item a l'inventaire
void monprojet_addItem(Inventaire** inventaire, Item* item);

// Fonction pour enlever un item de l'inventaire 
void monprojet_RemoveItem(Inventaire** inventaire, Item* item);

// Fonction pour trier les items dans l'inventaire 
void monprojet_TrierInventaire(Inventaire** inventaire);


// Fonction pour trouver un item relatif a sa position daans l'inventaire
Item* monprojet_TrouverItemParPosition(Inventaire* inventaire, int position);

// Fonction pour trouver un item relatif a son nom
Item* monprojet_TrouverItemParNom(Inventaire* inventaire, char nom);

// Fonction pour avoir la quantité d'item dans l'inventaire
int monprojet_GetQuantiteItems(Inventaire* inventaire);

// Fonction pour ajouter un item aléatoire a l'inventaire
void monprojet_addItemAléatoire(Inventaire** inventaire);

// Fonction pour lire le fichier CVS et peupler le liste des items possible
void monprojet_LireFichierCVS(const char* filename);







//int monprojet_add(int a, int b);
//
//// Lorsqu'une fonction n'a pas de parametre, mettre void entre les parentheses.
//void monprojet_ditbonjour(void);