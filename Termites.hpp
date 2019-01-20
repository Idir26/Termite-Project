#ifndef TERMITEABSTR_HPP_INCLUDED
#define TERMITEABSTR_HPP_INCLUDED


struct Coordonnees {
    int x;
    int y;
};

struct termite {
    int dir; // direction du termite
    int indT; // INDICE DU TERMITE
    bool brindille; // porte une brindille ou pas
    bool tourne_sur_place;
    int sablier; // termite peut poser(ou prendre) la brindille qu'après un certain temps
    Coordonnees c; // Position du termite
};


/**************************************************************************************
//                          Fonctions du type termite                      //
**************************************************************************************/

void creerTermit(termite &t, int x, int y, int indT);
Coordonnees CoordDevant(termite t);
Coordonnees newcoord(int x, int y);
bool Hasard(float p);
void tourneGauche(termite &t);
void tourneDroite(termite &t);
void Avancer(termite &t);
void charger(termite &t);
void decharger(termite &t);
bool VoieEstLibre(termite t);
bool TermiteDansGrille(Coordonnees c);
bool brindilleDevant(termite &t);
void tournerAleatoir(termite &t);
void MarcheAleatoire(termite &t);
void setcoord(termite &t, Coordonnees co);
void ModifierDirection (termite &t);
void rassemblerBrindille (termite &t) ;

#endif // TERMITEABSTR_HPP_INCLUDED
