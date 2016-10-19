//  main.c
//  Cours1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


/* void square(longueur, hauteur){  //Supprimer les // les slash étoiles pour que le programme marche
    
    int i = 0;
    int j = 0;
    
    for(i = 0; i < longueur; i++){
        
        printf("#");
    }
    for(j = 0; j < hauteur-1; j++){
        
        printf("\n");
        
        for(i = 0; i < longueur; i++){
            
            if((i == 0) || (i == longueur-1)){
                printf("#");
                }
            else{
                    printf(" ");
                }
        }
    }
    printf("\n");
    
    for(i = 0; i < longueur; i++){
        printf("#");
    }
}

int main(int argc, const char * argv[]) {

    int x = 0;
    int y = 0;
   
    
    printf("Entrez la longueur du tableau");
    scanf("%d", &x);
    
    printf("Entrez la hauteur");
    scanf("%d", &y);
        y = y - 1;
    
    square(x,y);
    
    printf("\n");

    
}
*/

/*int main(int argc, const char * argv[]) {         Programme pour donner la table de 10 sur 10 puis demander a l'utilisatur
                                                        une table et l'afficher.
    int tab[100][100]={0};
    int table=10;
    int nombre=10;
    int i=1;
    int j=1;
    
    for(i=0;i<=table;i++){
        printf("\n");
        j=1;
        
        for(j=0;j<=nombre;j++){
            tab[i][j]=(i*j);
            
        printf("%d ",tab [i][j]);
            
    }
    }
    printf("\nSaisir la table souhaitée\n");
    scanf("%d",&table);
    
    printf("\nSaisir le nombre maximal d'éléments souhaités\n");
    scanf("%d", &nombre-1);
    
    for(j=1;j<=nombre;j++){
        
        printf("%d ",table*j);
    }
    
}
*/
/*

int main(int argc, const char * argv[]) {

#define MAP_H 30
#define MAP_W 30
#define MAP_ITEMS 3
#define MAP_SOL 0
#define MAP_MOVE_TO_PAID 1
#define MAP_PLAYER 2
#define PLAYER_MOVE_POINT 10
#define ID_J1 1
#define ID_J2 2
#define HERBE 1
#define MOVE_HERBE 1
#define SABLE 2
#define MOVE_SABLE 2
#define ROCHER 3
#define MOVE_ROCHER 5
#define PLAYER_STATS 4
#define X 0
#define Y 1
#define MP 2
#define ID 3
    
    
    void waitFor (unsigned int secs) {
        unsigned int retTime = time(0) + secs;   // Get finishing time.
        while (time(0) < retTime);               // Loop until it arrives.
    }
    
    int doRand(int startVal, int endVal){       //on met le nombre de départ et d'arrivée
        waitFor(0.05);
        srand(time(NULL)*rand());
        if(startVal == 0 && endVal == 1){
            return rand() % 2;
        }else{
            return (rand() % ((endVal + startVal -1)) + startVal);      // la fonction retournera un nombre entre celui de départ et d'arrivée aléatoirement
        }
    }
    
    void PrintTableau(int map[MAP_H][MAP_W][MAP_ITEMS],int item){
        
        int i;
        int j;
        
        for(i = -1; i < MAP_H+1; i++){
            for(j = -1; j < MAP_W+1; j++){
                
                if(i == 1 || i == MAP_H || j == -1 || j == MAP_W){
                    printf("#");
                }else{
                    if(map[i][j][item] != 0){
                        printf
                    }
                }
            }
        }
    }
    
    void JeuRencontreInit(int map[MAP_H][MAP_W][MAP_ITEMS]){ //doit remplir le tableau 2D qui était rempli de zéro avec les élements nécessaires, avec un for et un do Rand pour l'aléatoirité
        int i;
        int j;
        
        for(i = 0; i < MAP_H; i++){
            
            for(j = 0; j < MAP_W; j++){
                
                map[i][j][MAP_SOL] = doRand(1,3);
                
                switch (map[i][j][MAP_SOL]){
                    
                    case HERBE:
                        map[i][j][MAP_MOVE_TO_PAID] = MOVE_HERBE;
                        break;
                        
                    case SABLE:
                        map[i][j][MAP_MOVE_TO_PAID] = MOVE_SABLE;
                        break;
                        
                    case ROCHER:
                        map[i][j][MAP_MOVE_TO_PAID] = MOVE_ROCHER;
                        break;
                }
            }
        }
        
    }
    
    void JeuRencontrePlacementJoueur(int player[PLAYER_STATS],int map[MAP_H][MAP_W][MAP_ITEMS]){
        
        PLAYER_STATS[X] = doRand(0, MAP_H-1);
        PLAYER_STATS[Y] = doRand(0, MAP_W-1);
        
        map [PLAYER_STATS[X]][PLAYER_STATS[Y]][MAP_PLAYER] = player[ID];
        
        
    }
    
    void JeuRencontreDeplacement(int player[PLAYER_STATS],int destination[PLAYER_STATS],int map[MAP_H][MAP_W][MAP_ITEMS]){
        
        while((player[X] != destination[X])&&(player[Y] != destination[Y])){
            
            //JOUEUR 1
            player[MP] = PLAYER_MOVE_POINT
            
            while(player[MP] > 0){
                
                if(
            }
        }
        
    }
    
    void JeuRencontre(){
        int player1[PLAYER_STATS];      //tableau pour le joueur 1 de 4 cases
        player1[ID] = ID_J1;
        int player2[PLAYER_STATS];
        player2[ID] = ID_J2;
        int map[MAP_H][MAP_W][MAP_ITEMS] = {0};
        
        JeuRencontreInit(map);      // initialise la carte en la prenant en paramètres pour caler des obstacles etc
        PrintTableau(map,MAP_SOL);      //initialise le sol sur la map
        printf("////////////////////////////////////////\n");
        PrintTableau(map,MAP_MOVE_TO_PAID);     // initialise les points de mouvements
        printf("////////////////////////////////////////\n");
        getchar();
        JeuRencontrePlacementJoueur(player1,map);       //met le joueur 1 de façon aléatoire sur la map
        JeuRencontrePlacementJoueur(player2,map);
        PrintTableau(map,MAP_PLAYER);       // initialise les joueurs sur la map
        printf("////////////////////////////////////////\n");
        getchar();  //attends que l'utilisateur fasse entrée
        while(player1[X] != player2[X] && player1[Y] != player2[Y]){        //boucle tant que les coordonées des joueurs 1 et 2 ne sont pas égaux
            player1[MP] = PLAYER_MOVE_POINT;        //initialise a 10 les pts de mouvements de chaques joueurs
            player2[MP] = PLAYER_MOVE_POINT;
            JeuRencontreDeplacement(player1,player2,map);       //déplacement d'un joueur l'un vers l'autre, j1 vers j2 en loccurence
            JeuRencontreDeplacement(player2,player1,map);
            PrintTableau(map,MAP_PLAYER);
            printf("////////////////////////////////////////\n");
            getchar();
        }
        printf("Gagne\n");
    }
    
    int calcul(int entier1, int entier2){
        int a = 6;
        entier1 -= 2;
        entier2 -= 2;
        return (entier1 + entier2)*6;
    }
    
    void useFonction(){
        int a = 10;
        int b = 6;
        int r =  0;
        r = calcul(a,b);
        printf("a = %d b = %d r = %d\n",a,b,r);
    }
    
    int main()
    {
        //Square2();
        //useFonction();
        //tp6();
        //tp5();
        //Multiplication();
        //SecretAndUnsecret();
        JeuRencontre();
        return 0;
    }

    
    
    
    
}
*/
/*

int main(int argc, const char * argv[]) {

    int jasmine = 7;                            //TP2
    int aladin = 5;
    int nouveauPannier = 0;
    
    nouveauPannier = jasmine + aladin;
    
    printf("Leurs nombre de pommes est %d\n", nouveauPannier);
}


*/
/*
int main(int argc, const char * argv[]) {

    float aMax = 0;
    float aJuju = 0;
    float aTog = 0;
    float commun = 0;
    float nbbiere = 0;
    
    printf("Entrez l'argent de Max :\n");
    scanf("%f", &aMax);
    fpurge(stdin);
    
    printf("Entrez l'argent de Juju :\n");          //jeu pour calculer le nombre de bières achetables
    scanf("%f", &aJuju);
    fpurge(stdin);
    
    printf("Entrez l'argent de Tog :\n");
    scanf("%f", &aTog);
    fpurge(stdin);
    
    commun = aMax + aJuju + aTog;
    nbbiere = commun / 0.86;
    
    printf("\nIls peuvent s'acheter %f bières\n", nbbiere);
}
*/
/*
void remplirRes(int *res, int *camion){
    
    if (*camion == 100 && *res == 0){
        *camion = 0;
        *res = 100;
        printf("La cuve %d remplie !\n", *res);
        
    }else{
        printf("Le camion n'est pas rempli\n");
    }
}

void remplirCamion (int *camion){
    
    if (*camion == 0){
        *camion = 100;
        
    }else{
        printf("Le camion est déja rempli\n");
    }
    
}


int main(int argc, const char * argv[]) {
    
    int res951 = 0;

    int res952 = 0;
    
    int res981 = 0;
    
    int res982 = 0;
    
    int resG = 0;
    
    int camion95 = 100;
    
    int camion98 = 100;
    
    int camionG = 100;
    
    int saisie = 0;
    
    printf("Quelle cuve voulez-vous remplir ?\n 1 pour SP95(1), 2 pour SP95(2), 3 pour SP98(1), 4 pour SP98(2) et 5 pour G\n");
    scanf("%d", &saisie);
    
    if(saisie == 1 || saisie == 2 || saisie == 3 || saisie == 4 || saisie == 5){
        printf("Vous avez entré un mauvais nom de cuve, saisissez-en un valide, nom mais !\n");
        scanf("%d", &saisie);
        
    }else{
        switch(saisie){
                
            case 1:
                remplirRes (&res951, &camion95);
                break;
            
            case 2:
                remplirRes (&res952, &camion95);
                break;
                
            case 3:
                remplirRes (&res981, &camion98);
                break;
                
            case 4:
                remplirRes (&res982, &camion98);
                break;
                
            case 5:
                remplirRes (&resG, &camionG);
                break;
        }
    }
    
}
    
*/


void waitFor (unsigned int secs) {
    unsigned int retTime = time(0) + secs;   // Get finishing time.
    while (time(0) < retTime);               // Loop until it arrives.
}

int doRand(int startVal, int endVal){
    waitFor(0.05);
    srand(time(NULL)*rand());
    if(startVal == 0 && endVal == 1){
        return rand() % 2;
    }else{
        return (rand() % ((endVal + startVal -1)) + startVal);
    }
}
/*
#define CUVE_SP95_1_MAX 100
#define CUVE_SP95_2_MAX 120
#define CUVE_G_1_MAX 150
#define CUVE_G_2_MAX 80
#define CUVE_SP98_1_MAX 100

#define CAMION_SP95_MAX 80
#define CAMION_SP98_MAX 60
#define CAMION_G_MAX 150

void AfficherCuve(int cuve, int max){
    int i;
    for(i=0;i<cuve;i++){
        printf("|");
    }
    printf(" -> %f pourcent\n",(float)cuve/(float)max*100);
}

void Remplir(int* cuve, int* camion, int max){
    system("cls");
    while(*cuve < max && *camion > 0){
        *cuve = *cuve + 1;
        *camion = *camion - 1;
    }
    AfficherCuve(*cuve,max);
    getchar();
}

void Vider(int* cuve){
    *cuve = *cuve - doRand(0,*cuve);
}

void Ravitaillement(int* camionG,int* camionSP95,int* camionSP98){
    int saisi = -1;
    while(saisi){
        system("cls");
        printf("Etat camionG : %f pourcent soit %d litre\n",(float)*camionG /(float)CAMION_G_MAX*100,*camionG);
        printf("1 : pour ravitailler\n");
        printf("Etat camionSP95 : %f pourcent soit %d litre\n",(float)*camionSP95/(float)CAMION_SP95_MAX*100,*camionSP95);
        printf("2 : pour ravitailler\n");
        printf("Etat camionSP98 : %f pourcent soit %d litre\n",(float)*camionSP98/(float)CAMION_SP98_MAX*100,*camionSP98);
        printf("3 : pour ravitailler\n");
        scanf("%d",&saisi);
        switch(saisi){
            case 0:
                break;
            case 1:
                *camionG = CAMION_G_MAX;
                printf("Camion rempli\n");
                break;
            case 2:
                *camionSP95 = CAMION_SP95_MAX;
                printf("Camion rempli\n");
                break;
            case 3:
                *camionSP98 = CAMION_SP98_MAX;
                printf("Camion rempli\n");
                break;
            default :
                printf("Erreur de saisi\n");
                break;
        }
    }
    
}

void Stats(int* camionG,int* camionSP95,int* camionSP98,
           int* cuveG1,int* cuveG2,int* cuveSP951,int* cuveSP952,int* cuveSP981){
    AfficherCuve(*cuveG1,CUVE_G_1_MAX);
    printf("Cuve G 1 :%d\n\n",*cuveG1);
    AfficherCuve(*cuveG2,CUVE_G_2_MAX);
    printf("Cuve G 2 :%d\n\n",*cuveG2);
    AfficherCuve(*cuveSP951,CUVE_SP95_1_MAX);
    printf("Cuve SP95 1 :%d\n\n",*cuveSP951);
    AfficherCuve(*cuveSP952,CUVE_SP95_2_MAX);
    printf("Cuve SP95 2 :%d\n\n",*cuveSP952);
    AfficherCuve(*cuveSP981,CUVE_SP98_1_MAX);
    printf("Cuve SP98 1 :%d\n\n",*cuveSP981);
    
    AfficherCuve(*camionG,CAMION_G_MAX);
    printf("Camion G :%d\n\n",*camionG);
    AfficherCuve(*camionSP95,CAMION_SP95_MAX);
    printf("Camion SP95 :%d\n\n",*camionSP95);
    AfficherCuve(*camionSP98,CAMION_SP98_MAX);
    printf("Camion SP98 :%d\n\n",*camionSP98);
    getchar();
}

void Cuve(){
    int cuveSP951 = 2;
    int cuveSP952 = 0;
    int cuveSP981 = 4;
    int cuveG1 = 3;
    int cuveG2 = 5;
    int camionSP95 = CAMION_SP95_MAX;
    int camionSP98 = CAMION_SP98_MAX;
    int camionG = CAMION_G_MAX;
    
    int i;
    for(i=0;i<10;i++){
        int saisi=-1;
        Stats(&camionG,&camionSP95,&camionSP98,&cuveG1,&cuveG2,&cuveSP951,&cuveSP952,&cuveSP981);
        system("cls");
        while(saisi){
            system("cls");
            printf("Jour %d sur 10\n",i+1);
            printf("Selectionner cuve a remplir (0 pour arreter)\n");
            printf("1 : Cuve SP95 1\n");
            printf("2 : Cuve SP95 2\n");
            printf("3 : Cuve SP98 1\n");
            printf("4 : Cuve G 1\n");
            printf("5 : Cuve G 2\n");
            printf("6 : Ravitailler un camion\n");
            printf("7 : Afficher le status de la station\n");
            printf("8 : Sauvegardez votre station essence (la classe)\n");
            scanf("%d",&saisi);
            fflush(stdin);
            
            switch(saisi){
                case 0:
                    break;
                case 1:
                    Remplir(&cuveSP951,&camionSP95,CUVE_SP95_1_MAX);
                    break;
                case 2:
                    Remplir(&cuveSP952,&camionSP95,CUVE_SP95_2_MAX);
                    break;
                case 3:
                    Remplir(&cuveSP981,&camionSP98,CUVE_SP98_1_MAX);
                    break;
                case 4:
                    Remplir(&cuveG1,&camionG,CUVE_G_1_MAX);
                    break;
                case 5:
                    Remplir(&cuveG2,&camionG,CUVE_G_2_MAX);
                    break;
                case 6:
                    Ravitaillement(&camionG,&camionSP95,&camionSP98);
                    break;
                case 7:
                    Stats(&camionG,&camionSP95,&camionSP98,&cuveG1,&cuveG2,&cuveSP951,&cuveSP952,&cuveSP981);
                    break;
                case 8:
                    FILE *sauvegarde;
                    sauvegarde = (fopen("./sauvegardePompe.txt", "a+"));
                    
                    fprintf(sauvegarde )
                default :
                    printf("Erreur de saisi\n");
                    break;
            }
        }
        
        Vider(&cuveG1);
        Vider(&cuveG2);
        Vider(&cuveSP951);
        Vider(&cuveSP952);
        Vider(&cuveSP981);
        getchar();
    }
}


int main(int argc, const char * argv[]) {
    
    Cuve();
    
    return 0;
    
}
*/   // DEMOLI.textColor= (UIColor colorWithRed:(160/255.0) green:(97/255.0) blue:(5/255.0) alpha:1) ; Expression qui pourrais ptet trouver des couleurs mais pas sûr

#define LONGUEUR 24
#define HAUTEUR 18
#define ETAT 2
#define CORVETTE 1
#define DESTROYER 2
#define CROISEUR 3
#define PORTE_AVION 4
#define DEMOLI 8
#define RATEY 7


void placement_DESTROYER (int plateau[LONGUEUR][HAUTEUR][ETAT]){    //fonction pour caler aléatoirement un bateau de 3 en colonne
    
    int posY_dep_DESTROYER = doRand(0,HAUTEUR-1);
    int posX_dep_DESTROYER = doRand(0, LONGUEUR-1);
    int i = 0;
    
    while ((plateau[posY_dep_DESTROYER][posX_dep_DESTROYER][0] != 0) && (plateau[posY_dep_DESTROYER + 1][posX_dep_DESTROYER][0] != 0) && (plateau[posY_dep_DESTROYER + 2][posX_dep_DESTROYER][0] != 0)){
        posY_dep_DESTROYER = doRand(0,HAUTEUR-1);
        posX_dep_DESTROYER = doRand(0, LONGUEUR-1);
    }
           
    for(i = 0; i < 3; i++){
        plateau[posY_dep_DESTROYER + i][posX_dep_DESTROYER][0] = DESTROYER;
    }
}




void placement_CORVETTE (int plateau[LONGUEUR][HAUTEUR][ETAT]){    //fonction pour caler aléatoirement un bateau de 1

    int posY_dep_CORVETTE = doRand(0, HAUTEUR-1);
    int posX_dep_CORVETTE = doRand(0, LONGUEUR-1);
    
    while (plateau[posY_dep_CORVETTE][posX_dep_CORVETTE][0] != 0){      //while pour éviter de caler le bateau sur un déja existant
        posY_dep_CORVETTE = doRand(0, HAUTEUR-1);
        posX_dep_CORVETTE = doRand(0, LONGUEUR-1);
    }
    
    plateau[posY_dep_CORVETTE][posX_dep_CORVETTE][0] = CORVETTE;
}




void placement_CROISEUR (int plateau[LONGUEUR][HAUTEUR][ETAT]){
    
    int posY_dep_CROISEUR = doRand(0, HAUTEUR-1);
    int posX_dep_CROISEUR = doRand(0, LONGUEUR-1);
    int i = 0;
    
    while ((plateau[posY_dep_CROISEUR][posX_dep_CROISEUR][0] != 0) && (plateau[posY_dep_CROISEUR + 1][posX_dep_CROISEUR][0] != 0) && (plateau[posY_dep_CROISEUR + 2][posX_dep_CROISEUR][0] != 0) && (plateau[posY_dep_CROISEUR + 3][posX_dep_CROISEUR][0] != 0)){   // while pour éviter d'empiéter sur un bateau déja existant
        
        posY_dep_CROISEUR = doRand(0, HAUTEUR-1);
        posX_dep_CROISEUR = doRand(0, LONGUEUR-1);
    }
    
    for(i = 0; i < 4; i++){
    plateau[posY_dep_CROISEUR + i][posX_dep_CROISEUR][0] = CROISEUR;
    }
}



void placement_PORTE_AVION (int plateau[LONGUEUR][HAUTEUR][ETAT]){
    
    int posY_dep_PORTE_AVION = doRand(0, HAUTEUR-1);
    int posX_dep_PORTE_AVION = doRand(0, HAUTEUR-1);
    int i = 0;
    
    while((plateau[posY_dep_PORTE_AVION][posX_dep_PORTE_AVION][0] != 0) && (plateau[posY_dep_PORTE_AVION + 1][posX_dep_PORTE_AVION][0] != 0) && (plateau[posY_dep_PORTE_AVION + 2][posX_dep_PORTE_AVION][0] != 0) && (plateau[posY_dep_PORTE_AVION + 3][posX_dep_PORTE_AVION][0] != 0) && (plateau[posY_dep_PORTE_AVION + 4][posX_dep_PORTE_AVION][0] != 0) && (plateau[posY_dep_PORTE_AVION + 5][posX_dep_PORTE_AVION][0] != 0)){
        
        posY_dep_PORTE_AVION = doRand(0, HAUTEUR-1);
        posX_dep_PORTE_AVION = doRand(0, LONGUEUR-1);
}
    for(i = 0; i < 6; i++){
        plateau[posY_dep_PORTE_AVION + i][posX_dep_PORTE_AVION][0] = PORTE_AVION;
    }
}




void tirer(int plateau[LONGUEUR][HAUTEUR][ETAT]){
    
    int y = 0;
    int x = 0;
    
    printf("\n\nSur quelle ligne voulez-vous tirer ? (en nombre pas en lettre wsh)\n");
    scanf("%d",&y);
    printf("\nEt quelle colonne ?\n");
    scanf("%d", &x);
    
    if(plateau[y-1][x-1][0] != 0){      //avec -1 aux coordonnées pour que l'utilisateur puisse tirer le bon numéro sans décaler
        printf("\nToucheeeey !\n");
        plateau[y-1][x-1][0] = DEMOLI;       //remplace la case touchée par un 8
        
    }else{
        printf("\nDans l'eau hi hi !\n");
        plateau[y-1][x-1][0] = RATEY;
    }
}


void afficher_plateau(int plateau[LONGUEUR][HAUTEUR][ETAT]){
    
    int i = 0;
    int j = 0;
    int k = 0;
    char alph[]= "ABCDEFGHIJKLMNOPKRSTUVWX";
    
        printf("\n\n\nPlateau : \n\n");
        printf ("• _1__2__3__4__5__6__7__8__9__10_11_12_13_14_15_16_17_18") ;
            for(i = 0; i <24; i++){
                          
            printf(" \n%c| ", alph[i]);
                          
            for(j = 0; j < 18; j++){                                          //affichage de tout le tableau
                              
            for(k = 0; k < 1; k++){
                                  
                printf("%d  ", plateau[i][j][k]);
            }
        }
    }
}



int main(int argc, const char * argv[]) {
    
    
    int plateau[LONGUEUR][HAUTEUR][ETAT] = {0}; //initialisation du tableau

    
    placement_DESTROYER(plateau);
    placement_DESTROYER(plateau);
    placement_CORVETTE(plateau);            //placement en aléatoire de tous les bateaux puis affichage
    placement_CROISEUR(plateau);
    placement_CROISEUR(plateau);
    placement_PORTE_AVION(plateau);
    afficher_plateau(plateau);
    
    tirer(plateau);                 //le joueur tire puis le tableau modifier lui est affiché
    afficher_plateau(plateau);
    
    
}