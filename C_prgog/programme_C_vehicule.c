#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VEHICULES 100



typedef enum {
    VOITURE,
    MOTO,
    BUS,
    TROTTINETTE,
    VELO
} TypeVehicule;

typedef struct {
    char marque[20];
    char modele[20];
    char couleur[20];
    int annee;
    int vignetteCritAir;
    char plaqueImmatriculation[20];
    TypeVehicule type;
} Vehicule;

Vehicule vehicules[MAX_VEHICULES];
int nbVehicules = 0;

void ajouterVehicule();
void supprimerVehicule();
void modifierVehicule();
void afficherStatistiques();
void afficherVehiculesParType(TypeVehicule type);
void afficherVehiculesParCouleur(const char* couleur);
void afficherVehiculesParVignetteCritAir(int vignetteCritAir);
void afficherVehiculesParMarque(const char* marque);
void afficherVehiculesParPlaqueImmatriculation(const char* plaque);

int main() {
    int choix;

    do {
        printf("Menu:\n");
        printf("1. Ajouter un véhicule\n");
        printf("2. Supprimer un véhicule\n");
        printf("3. Modifier un véhicule\n");
        printf("4. Afficher les statistiques\n");
        printf("5. Afficher les véhicules par type\n");
        printf("6. Afficher les véhicules par couleur\n");
        printf("7. Afficher les véhicules par vignette Crit Air\n");
        printf("8. Afficher les véhicules par marque\n");
        printf("9. Afficher les véhicules par plaque d'immatriculation\n");
        printf("10. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterVehicule();
                break;
            case 2:
                supprimerVehicule();
                break;
            case 3:
                modifierVehicule();
                break;
            case 4:
                afficherStatistiques();
                break;
            case 5: {
                int type;
                printf("Type de véhicule (0: Voiture, 1: Moto, 2: Bus, 3: Trottinette, 4: Vélo): ");
                scanf("%d", &type);
                afficherVehiculesParType((TypeVehicule)type);
                break;
            }
            case 6: {
                char couleur[20];
                printf("Couleur: ");
                scanf("%s", couleur);
                afficherVehiculesParCouleur(couleur);
                break;
            }
            case 7: {
                int vignetteCritAir;
                printf("Vignette Crit Air (1: Oui, 0: Non): ");
                scanf("%d", &vignetteCritAir);
                afficherVehiculesParVignetteCritAir(vignetteCritAir);
                break;
            }
            case 8: {
                char marque[20];
                printf("Marque: ");
                scanf("%s", marque);
                afficherVehiculesParMarque(marque);
                break;
            }
            case 9: {
                char plaque[20];
                printf("Plaque d'immatriculation: ");
                scanf("%s", plaque);
                afficherVehiculesParPlaqueImmatriculation(plaque);
                break;
            }
            case 10:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }

        printf("\n");
    } while (choix != 10);

    return 0;
}

void ajouterVehicule() {
    if (nbVehicules == MAX_VEHICULES) {
        printf("Nombre maximal de véhicules atteint.\n");
        return;
    }

    Vehicule v;

    printf("Marque: ");
    scanf("%s", v.marque);

    printf("Modèle: ");
    scanf("%s", v.modele);

    printf("Couleur: ");
    scanf("%s", v.couleur);

    printf("Année: ");
    scanf("%d", &v.annee);

    printf("Vignette Crit Air (1: Oui, 0: Non): ");
    scanf("%d", &v.vignetteCritAir);

    printf("Plaque d'immatriculation: ");
    scanf("%s", v.plaqueImmatriculation);

    printf("Type de véhicule (0: Voiture, 1: Moto, 2: Bus, 3: Trottinette, 4: Vélo): ");
    scanf("%d", (int*)&v.type);

    vehicules[nbVehicules] = v;
    nbVehicules++;

    printf("Véhicule ajouté avec succès.\n");
}

void supprimerVehicule() {
    if (nbVehicules == 0) {
        printf("Aucun véhicule à supprimer.\n");
        return;
    }

    char plaque[20];

    printf("Plaque d'immatriculation du véhicule à supprimer: ");
    scanf("%s", plaque);

    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].plaqueImmatriculation, plaque) == 0) {
            int j;
            for (j = i; j < nbVehicules - 1; j++) {
                vehicules[j] = vehicules[j + 1];
            }
            nbVehicules--;
            printf("Véhicule supprimé avec succès.\n");
            return;
        }
    }

    printf("Aucun véhicule avec cette plaque d'immatriculation trouvé.\n");
}

void modifierVehicule() {
    if (nbVehicules == 0) {
        printf("Aucun véhicule à modifier.\n");
        return;
    }

    char plaque[20];

    printf("Plaque d'immatriculation du véhicule à modifier: ");
    scanf("%s", plaque);

    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].plaqueImmatriculation, plaque) == 0) {
            Vehicule v = vehicules[i];

            printf("Nouvelle marque: ");
            scanf("%s", v.marque);

            printf("Nouveau modèle: ");
            scanf("%s", v.modele);

            printf("Nouvelle couleur: ");
            scanf("%s", v.couleur);

            printf("Nouvelle année: ");
            scanf("%d", &v.annee);

            printf("Nouvelle vignette Crit Air (1: Oui, 0: Non): ");
            scanf("%d", &v.vignetteCritAir);

            printf("Nouvelle plaque d'immatriculation: ");
            scanf("%s", v.plaqueImmatriculation);

            printf("Nouveau type de véhicule (0: Voiture, 1: Moto, 2: Bus, 3: Trottinette, 4: Vélo): ");
            scanf("%d", (int*)&v.type);

            vehicules[i] = v;

            printf("Véhicule modifié avec succès.\n");
            return;
        }
    }

    printf("Aucun véhicule avec cette plaque d'immatriculation trouvé.\n");
}

void afficherStatistiques() {
    printf("Nombre total de véhicules: %d\n", nbVehicules);

    int nbVoitures = 0, nbMotos = 0, nbBus = 0, nbTrottinettes = 0, nbVelo = 0;
    int i;
    for (i = 0; i < nbVehicules; i++) {
        switch (vehicules[i].type) {
            case VOITURE:
                nbVoitures++;
                break;
            case MOTO:
                nbMotos++;
                break;
            case BUS:
                nbBus++;
                break;
            case TROTTINETTE:
                nbTrottinettes++;
                break;
            case VELO:
                nbVelo++;
                break;
        }
    }

    printf("Nombre de voitures: %d\n", nbVoitures);
    printf("Nombre de motos: %d\n", nbMotos);
    printf("Nombre de bus: %d\n", nbBus);
    printf("Nombre de trottinettes: %d\n", nbTrottinettes);
    printf("Nombre de vélos: %d\n", nbVelo);
}

void afficherVehiculesParType(TypeVehicule type) {
    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (vehicules[i].type == type) {
            printf("Marque: %s\n", vehicules[i].marque);
            printf("Modèle: %s\n", vehicules[i].modele);
            printf("Couleur: %s\n", vehicules[i].couleur);
            printf("Année: %d\n", vehicules[i].annee);
            printf("Vignette Crit Air: %d\n", vehicules[i].vignetteCritAir);
            printf("Plaque d'immatriculation: %s\n", vehicules[i].plaqueImmatriculation);
            printf("\n");
        }
    }
}

void afficherVehiculesParCouleur(const char* couleur) {
    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].couleur, couleur) == 0) {
            printf("Marque: %s\n", vehicules[i].marque);
            printf("Modèle: %s\n", vehicules[i].modele);
            printf("Couleur: %s\n", vehicules[i].couleur);
            printf("Année: %d\n", vehicules[i].annee);
            printf("Vignette Crit Air: %d\n", vehicules[i].vignetteCritAir);
            printf("Plaque d'immatriculation: %s\n", vehicules[i].plaqueImmatriculation);
            printf("\n");
        }
    }
}

void afficherVehiculesParVignetteCritAir(int vignetteCritAir) {
    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (vehicules[i].vignetteCritAir == vignetteCritAir) {
            printf("Marque: %s\n", vehicules[i].marque);
            printf("Modèle: %s\n", vehicules[i].modele);
            printf("Couleur: %s\n", vehicules[i].couleur);
            printf("Année: %d\n", vehicules[i].annee);
            printf("Vignette Crit Air: %d\n", vehicules[i].vignetteCritAir);
            printf("Plaque d'immatriculation: %s\n", vehicules[i].plaqueImmatriculation);
            printf("\n");
        }
    }
}

void afficherVehiculesParMarque(const char* marque) {
    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].marque, marque) == 0) {
            printf("Marque: %s\n", vehicules[i].marque);
            printf("Modèle: %s\n", vehicules[i].modele);
            printf("Couleur: %s\n", vehicules[i].couleur);
            printf("Année: %d\n", vehicules[i].annee);
            printf("Vignette Crit Air: %d\n", vehicules[i].vignetteCritAir);
            printf("Plaque d'immatriculation: %s\n", vehicules[i].plaqueImmatriculation);
            printf("\n");
        }
    }
}

void afficherVehiculesParPlaqueImmatriculation(const char* plaque) {
    int i;
    for (i = 0; i < nbVehicules; i++) {
        if (strcmp(vehicules[i].plaqueImmatriculation, plaque) == 0) {
            printf("Marque: %s\n", vehicules[i].marque);
            printf("Modèle: %s\n", vehicules[i].modele);
            printf("Couleur: %s\n", vehicules[i].couleur);
            printf("Année: %d\n", vehicules[i].annee);
            printf("Vignette Crit Air: %d\n", vehicules[i].vignetteCritAir);
            printf("Plaque d'immatriculation: %s\n", vehicules[i].plaqueImmatriculation);
            printf("\n");
        }
    }
}
