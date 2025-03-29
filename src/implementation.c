#include "definition.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 100 // Chapgt m'a donné cette ligne de code qui permet de fixer la limite au nombre maximum d'items que l'on peut stocker dans la liste 

// Il est important de faire l'implementation de vos fonctions dans un fichier .c
// Si vous le faites dans le fichier "header", chaque fichier qui l'include va compiler l`implementation
// et cela causeras des definitions de symboles multiples.



// Fonction pour créer un nouvel inventaire
Inventaire * monprojet_createInventaire(void) {
	Inventaire* inventaire = malloc(sizeof(Inventaire));
	inventaire->item = NULL;
	inventaire->Next = NULL;
	return NULL;

}

// Fonction pour ajouter un item a l'inventaire
void monprojet_addItem(Inventaire** inventaire, Item* item) {
	Inventaire* nouveau = malloc(sizeof(Inventaire));
	nouveau->item = item;
	nouveau->Next = *inventaire;
	*inventaire = nouveau;

}

// Fonction pour enlever un item de l'inventaire 
void monprojet_RemoveItem(Inventaire** inventaire, Item* item) {
	if (*inventaire == NULL) return;
	if ((*inventaire)->item == item) {
		Inventaire* temp = *inventaire;
		*inventaire = (*inventaire)->Next;
		free(temp);
		return;

	}
	else {
		Inventaire* courant = *inventaire;
		while (courant->Next != NULL){
			if (courant->Next->item == item) {
				Inventaire* temp = courant->Next;
				courant->Next = temp->Next;
				free(temp);
				return;
			}
			courant = courant->Next;


		}
	}

}

// Fonction pour trier les items dans l'inventaire 
void monprojet_TrierInventaire(Inventaire** inventaire) {
	if (*inventaire == NULL || (*inventaire)->Next == NULL) return;
	Inventaire* trie = NULL;
	Inventaire* courant = *inventaire;

	while (courant != NULL) {
		Inventaire* Next = courant->Next; // Sauvegarde du prochaine élément
		if (trie == NULL || strcmp(courant->item->nom, trie->item->nom) < 0) {
			courant->Next = trie;
			trie = courant;
		}
		else {
			// recherche de la position correcte  dans la liste triée
			Inventaire* temp = trie;
			while (temp->Next != NULL && strcmp(temp->Next->item->nom, courant->item->nom) < 0)
			{
				temp = temp->Next;
			}
			courant->Next = temp->Next;
			temp->Next = courant;
		}
		courant = Next;
	}
	//	Mise a jour pointeur de tete avec la liste trié 
	*inventaire = trie;
}


// Fonction pour trouver un item relatif a sa position daans l'inventaire
Item* monprojet_TrouverItemParPosition(Inventaire* inventaire, int position) {
	int courant = 0;
	while (inventaire != NULL)
	{
		if (courant == position) return inventaire->item;
		courant++;
		inventaire = inventaire->Next;
	}
	return NULL;
}

// Fonction pour trouver un item relatif a son nom
Item* monprojet_TrouverItemParNom(Inventaire* inventaire, char nom) {
	while (inventaire != NULL)
	{
		if (strcmp(inventaire->item->nom, nom) == 0) return inventaire->item;
		inventaire = inventaire->Next;

	}
	return NULL;

}

// Fonction pour avoir la quantité d'item dans l'inventaire
int monprojet_GetQuantiteItems(Inventaire* inventaire) {
	int quantite = 0;
	while (inventaire != NULL)
	{
		quantite++;
		inventaire = inventaire->Next;

	}	return quantite;
}

// Fonction pour ajouter un item aléatoire a l'inventaire
void monprojet_addItemAléatoire(Inventaire** inventaire) {
	

	if (total_items == 0) {
		printf("Aucun item disponible dans la liste.\n");
		return;
	}
	int index = rand() % total_items; // Sélection Aléatoire
	Item* nouvelItem = malloc(sizeof(Item));
	*nouvelItem = liste_items[index];
	monprojet_addItem(inventaire,nouvelItem);
	printf("Item ajouté : %s (valeur : %d)\n", nouvelItem->nom, nouvelItem->valeur);
}

 //Fonction pour lire le fichier CVS et peupler le liste des items possible
Item liste_items[MAX_ITEMS];
int total_items = 0;
// Cette fonction c'est chapgt qui m'a expliqué les instructions car avec la boucle while j'essaye d'utiliser While du ligne 72 L4S2 mais cela ne fonctinner pas 
void monprojet_LireFichierCVS(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		printf("Erreur : impossible d'ouvrir le fichier % s\n", filename);
		return;
	}
	char ligne[100];
	while (fgets(ligne, sizeof(ligne), file) && total_items < MAX_ITEMS) {
		char* nom = strtok(ligne, ",");
		char* valeurStr = strtok(NULL, ",");
		if (nom && valeurStr) {
			strcpy(liste_items[total_items].nom, nom);
			liste_items[total_items].valeur = atoi(valeurStr);
			total_items++;

		}
	}
	fclose(file);
}

















//int monprojet_add(int a, int b){
//    return a+b;
//}
//
//void monprojet_ditbonjour(void){
//    printf("Hello Sailor !\n");
//}