#include <iostream>
#include <cmath>
#include <cstdlib>
#include "PlaceAbstr.hpp"
using namespace std;


void placeVide(place &p) {
    p.brindille = false;
    p.t = false;
    p.indT = -1;
}


void poserBrindille (place &p) {
    p.brindille = true;
    p.t = false;
}


void poserTermite (place &p, int ind) {
    p.brindille = false;
    p.t = true;
    p.indT = ind;
}

bool contientBrindille (place p) {
    return p.brindille;
}

bool contientTermite (place p) {
    return p.t;
}

bool estVide (place p) {
    if (ContientBrindille(p) == false and ContientTermite(p) == false)
        return true;
    return false;
}

void afficherPlace(place p, int &direction) {
    if (p.brindille)
        cout << '0';
    else {
        if (p.T and p.indiceT != -1) {

                cout << 'T';

}



