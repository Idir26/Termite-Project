#include <iostream>
#include <vector>
#include "Termites.hpp"
#include "PlaceAbstr.hpp"
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <windows.h>

using namespace std;


float densiteB = 0.05; //probabilité de présence d'une brindille dans une case
float densiteT = 0.01; //probabilité de présence d'un termite dans une case
const int taille = 40; // taille du terrain

int nbtermites = 0; // Nombre de termites initialisé à 0
termite tabT[taille*taille]; //tableau de termites
place terrain[taille][taille]; //terrain de 1600 cases


bool laVoieEstlibre(termite t){
   Coordonnees c;
   c = CoordDevant(t);
   return(TermiteDansGrille(c) and estVide(terrain[c.x][c.y]));
}

void InitialiseTerrain () { // Initialisation du terrain
    termite t;
    for (int i = 0; i <taille; i++) {
        for (int j = 0; j < taille; j++) {
            if (Hasard(densiteT)) {
                    creerTermit(t, i, j ,nbtermites);
                    poserTermite(terrain[i][j], nbtermites);
                    tabT[nbtermites] = t;
                    terrain[i][j].indT= nbtermites;
                    nbtermites++;
            } else {
                if (Hasard(densiteB)) {
                    poserBrindille(terrain[i][j]);
                 } else
                    placeVide(terrain[i][j]);
            }
        }
    }
}


void ColorTextConsole(int chiffre){ // Couleur de la présentation
  HANDLE  hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole, chiffre);
}


void AfficheTerrain(){ // Affichage du terrain
 ColorTextConsole(23); // ajouter des couleurs a notre triste console
 cout << "** Simulation de la vie des Termites ** "<< endl<<endl<<endl<<endl;

 ColorTextConsole(15);
   for(int i=0; i<taille; i++){
     for(int j=0; j<taille; j++){
         AffichePlace(terrain[i][j], tabT[terrain[i][j].indT].dir);
     }
      cout<<endl;
  }
}


void Avancer(termite &t) { // Le termite avance
    Coordonnees Cn = CoordDevant(t);
    poserTermite(terrain[Cn.x][Cn.y], terrain[t.c.x][t.c.y].indT);
    placeVide(terrain[t.c.x][t.c.y]);
    t.c.x = Cn.x;
    t.c.y = Cn.y;
}

void tournerAleatoir(termite &t){ // le termite tourne aléatoirement
    if(Hasard(0.5) ){
        tourneDroite(t);

    }else {
        tourneGauche(t);
    }
}


void MarcheAleatoire(termite &t){ // le termite prend des direcrtions aléatoires
    if(Hasard(0.1)){
        tournerAleatoir(t);
    }
    if (laVoieEstlibre(t)){
        Avancer(t) ;

    } else{
        tourneDroite(t);
    }

}


 bool Impasse(termite &t){ // le termite peut bouger ou pas
     tourneDroite(t) ;
     bool temp = laVoieEstlibre(t);
     tourneGauche(t) ;
     return temp ;
 }

void decharger(termite &t){ // décharger une brindille
   Coordonnees c= CoordDevant(t);
   if(estVide(terrain[c.x][c.y])){
     poserBrindille(terrain[c.x][c.y]);
     t.brindille = false;
      t.sablier = 7;
    }
}

bool brindilleDevant(termite &t) { // brindille devant le termite ou pas
   Coordonnees C = CoordDevant(t);
   if (C.x >= 0 and C.x < taille and C.y >= 0 and C.y < taille and contientBrindille(terrain[C.x][C.y]) == true)
        return true;
    return false;
}

void charger(termite &t){ // charger une brindille
   Coordonnees c= CoordDevant(t);
   placeVide(terrain[c.x][c.y]);
   t.brindille = true;
   t.sablier = 7;
}

void rassemblerBrindille (termite &t) { // Rassemble les brindilles en formant des tas

    if(t.tourne_sur_place){
        if(not laVoieEstlibre(t)){
            tourneDroite(t) ;

        }else {
           t.tourne_sur_place= false ;
           if(Impasse(t)){ // si le termite pas dans une impasse
            decharger(t);
           }
           t.sablier=7 ;
             }
    }else
         if(t.sablier== 0 and brindilleDevant(t)){
            if(not t.brindille){

               charger(t);
               t.sablier =7 ;

            }else {
               t.tourne_sur_place= true ;
             }
         } else {
            MarcheAleatoire(t) ;

         }
         if(t.sablier> 0){
        t.sablier-- ;
    }

}


int main (){

    srand (time(NULL));
    InitialiseTerrain();
    AfficheTerrain();
    int i = 0 ;
    int x;
    bool terminer = false ;
    int nbiterations = 1 ;

 while (!terminer){

        ColorTextConsole(9);
        cout<<endl<<endl;
        puts ("Tapez: Entrer pour Continuer | '.' pour Quitter :");
        ColorTextConsole(15);
        x = getchar();
          if(x == '.')
            terminer = true ;
          if (x=='*'){
               terminer= false ;
               nbiterations=nbiterations*2;
           }
          if(x =='/'){
               terminer= false ;
               nbiterations=nbiterations/2;
               }

        for(int i=0 ; i<nbiterations; i++){
             for(int i=0; i < taille; i++){

                for(int j=0; j<taille; j++){


                   if (contientTermite(terrain[i][j]))

                      rassemblerBrindille(tabT[terrain[i][j].indT]) ;

                 }

              }
         }
         system("CLS");
         AfficheTerrain();


  }

return 0;

}


