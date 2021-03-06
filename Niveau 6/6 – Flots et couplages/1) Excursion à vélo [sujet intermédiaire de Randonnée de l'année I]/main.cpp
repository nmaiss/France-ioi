#include <stdio.h>
#include <vector>

#define INDEFINI -1
#define MAX_NB 1000

using namespace std;

int     nbInformations, nbPersonnes, nbVelos;
vector<int> personnes[MAX_NB];
int     attributions[MAX_NB], maxAttributions = 0, nbPrevisions = 0;

int     coupler(int iPersonne, int *vu){
    for (unsigned int i = 0 ; i < personnes[iPersonne].size() ; i++){
        int     iVelo = personnes[iPersonne][i];
        if (!vu[iVelo]){
            vu[iVelo] = 1;
            if (attributions[iVelo] == INDEFINI || coupler(attributions[iVelo], vu)){
                attributions[iVelo] = iPersonne;
                return (1);
            }
        }
    }
    return (0);
}

int     main(void){
    for (int i = 0 ; i < MAX_NB ; i++)
        attributions[i] = INDEFINI;
    scanf("%d%d%d", &nbPersonnes, &nbVelos, &nbInformations);
    for (int i = 0 ; i < nbInformations ; i++){
        int     personne, velo, prevision;
        scanf("%d%d%d", &personne, &velo, &prevision);
        personnes[personne].push_back(velo);
        nbPrevisions += prevision;
    }
    for (int i = 0 ; i < nbPersonnes ; i++){
        int     vu[MAX_NB];
        for (int j = 0 ; j < MAX_NB ; j++)
            vu[j] = 0;
        maxAttributions += coupler(i, vu);
    }
    if (maxAttributions == nbPrevisions)
        printf("OUI");
    else
        printf("NON");
    return (0);
}