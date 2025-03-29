//Bonne pratique, pour les includes systemes toujours utiliser <> et "" pour les includes de votre projet.
#include <stdio.h>
#include "definition.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

extern int total_items;
// j'ai déclarer ces fonctions avec static grace a chapgpt pour que pour qu'il soit limité accessible seulement ici 
static void afficherMenu() {
	printf("\n---MENU---\n");
	printf("1 - Afficher l'inventaire\n");
	printf("2 - Ajouter un item aléatoire\n");
	printf("3 - Rechercher un item \n");
	printf("4 - Supprimer un item \n");
	printf("5 - Trier l'inventaire\n");
	printf("6 - Quitter\n");
	printf("Votre choix : ");
}
static void afficherInventaire(Inventaire* inventaire) {
	if (inventaire == NULL) {
		printf("L'inventaire est vide.\n");
		return;
	}
	Inventaire* courant = inventaire;
	int index = 1;
	while (courant != NULL )
	{
		printf("%d - %s (Valeur : %d)\n", index, courant->item->nom, courant->item->valeur);
		courant = courant->Next;
		index++;
	}
}

static void RechercherItem(Inventaire* inventaire) {
	char nomRecherche[50];
	printf("Entrer le nom de l'item a rechercher : ");
	scanf("%s", nomRecherche);
	Inventaire* courant = inventaire;
	while (courant != NULL)
	{
		if (strcmp(courant->item->nom, nomRecherche) == 0) {
			printf("Item trouvé : %s (Valeur : %d)\n", courant->item->nom, courant->item->valeur);
			return;
		}
		courant = courant->Next;
	}
	printf("Item non trouvé .\n");
}
static void supprimerItem(Inventaire** inventaire){
	char nomRecherche[50];
	printf("Entrer le nom de l'item a supprimer : ");
	scanf("%s", nomRecherche);
	Inventaire* courant = inventaire;
	while (courant != NULL)
	{
		if (strcmp(courant->item->nom, nomRecherche) == 0) {
			printf("Item trouvé : %s (Valeur : %d)\n", courant->item->nom, courant->item->valeur);
			return;
		}
		courant = courant->Next;
	}
	printf("Item non trouvé .\n");
}

int main() {
	monprojet_LireFichierCVS("tp1_data.csv");
	Inventaire* moninventaire = monprojet_createInventaire();

	

	int choix;
	
	int end = 0;

	while (!end)
	{
		afficherMenu();
		printf("-> ");
		if (scanf("%d", &choix) != 1) {
			printf("Entrée invalide. Veuillez entrer un numéro.\n");
			while (getchar() != '\n');
			continue;
		}
		switch (choix) {
		    case 1:
			    afficherInventaire(moninventaire);
			    break;

			case 2: 
				monprojet_addItemAléatoire(&moninventaire);
				break;
			case 3:
				RechercherItem(moninventaire);
				break;
			case 4:
				supprimerItem(&moninventaire);
				break;
			case 5:
				monprojet_TrierInventaire(&moninventaire);
				printf("Inventaire triee !\n");
				break;
			case 6:
				printf("Fermeture du programme...\n");	
				break;
			default:
				printf("Choix invalide, Veiller réessayer.\n");
				break;
		}
		


	}

	return 0;
}









//int main(int argc, char** argv){
//    printf("Bienvenue dans mon application nommer monprojet !\n");
//    printf("20 plus 22 donne: %d\n", monprojet_add(20,22));
//    monprojet_ditbonjour();
//}

