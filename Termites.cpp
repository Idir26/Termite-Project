#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "Termites.hpp"
#include "PlaceAbstr.hpp"

using namespace std;
const int taille = 40;

void creerTermit(termite &t, int x, int y, int indT){ //initialisation du termite
    t.c.x = x;
    t.c.y = y;
    t.indT = indT;
    t.sablier = 0;
    t.dir = rand()%8;
    t.tourne_sur_place = false;
}

Coordonnees newcoord(int x, int y) {
   Coordonnees c;
   c.x = x;
   c.y = y;
}

bool Hasard (float p){
   return rand()<p*RAND_MAX;
}


void tourneGauche(termite &t){ // Aller à gauche
   t.dir = (t.dir+1)%8;
}

void tourneDroite(termite &t){ // Aller à droite
   t.dir = (t.dir+7)%8;
}


bool TermiteDansGrille(Coordonnees c){ // Verifie que le termite se trouve bien dans le terrain ou pas
   return (c.x >= 0 and c.x <taille and c.y >= 0 and c.y <taille);
}


void setcoord(termite &t, Coordonnees co){ // Permet de fixer des coordonnées
   t.c.x = co.x;
   t.c.y = co.y;
}


Coordonnees CoordDevant(termite t){
    Coordonnees p;
    if(t.dir == 0){
            p.x=t.c.x;
            p.y=t.c.y+1;
            }else if(t.dir==1){
                p.x=t.c.x-1;
                p.y=t.c.y+1;
                }else if(t.dir==2){
                    p.x=t.c.x-1;
                    p.y=t.c.y;
                    }else if(t.dir==3){
                        p.x=t.c.x-1;
                        p.y=t.c.y-1;
                        }else if(t.dir==4){
                            p.x=t.c.x;
                            p.y=t.c.y-1;
                            }else if(t.dir==5){
                                p.x=t.c.x+1;
                                p.y=t.c.y-1;
                                }else if(t.dir==6){
                                    p.x=t.c.x+1;
                                    p.y=t.c.y;
                                    }else if(t.dir==7){
                                        p.x=t.c.x+1;
                                        p.y=t.c.y+1;
                                       }
                                       return p;
                                       }







