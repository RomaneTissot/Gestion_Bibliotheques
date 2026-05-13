#include "../include/Livre.h"
#include <iostream>

Livre::Livre(int c, string a, string t, string e, string i, Public p)
{
    code = c;
    auteur = a;
    titre = t;
    editeur = e;
    isbn = i;
    publicCible = p;
    if (p == Public::ADULTE ||
        p == Public::ADO ||
        p == Public::JEUNESSE ||
        p == Public::TOUT_PUBLIC)
    {
        publicCible = p;
    };
    etat = Etat::LIBRE;
}

Livre::~Livre() {}

int Livre::getCode() const { return code; }
Etat Livre::getEtat() const { return etat; }
void Livre::setEtat(Etat e) { etat = e; }

std::ostream& operator<<(std::ostream& os, const Livre& livre) {
    livre.afficher();
    return os;
}
