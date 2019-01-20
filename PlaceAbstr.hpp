#ifndef PLACEABSTR_HPP_INCLUDED
#define PLACEABSTR_HPP_INCLUDED

struct place {
    bool brindille;// présence d'une brindille ou pas
    bool t;// présence d'un termite ou pas
    int indT;// indice du termite dans le tableau de termites
} ;

/**************************************************************************************
//                          Fonctions du type abstrait place                         //
**************************************************************************************/

void placeVide (place &p);
void poserBrindille (place &p);
void poserTermite (place &p, int t);
bool contientBrindille(place p);
bool contientTermite (place p);
bool estVide(place p);
void afficherPlace(place p);

#endif // PLACEABSTR_HPP_INCLUDED















