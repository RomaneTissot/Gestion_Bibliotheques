#include "../include/Poesie.h"
#include <iostream>

static string formeToString(Forme f)
{
    switch (f) {
        case Forme::PROSE:
            return "prose";
        case Forme::VERS:
            return "vers";
        case Forme::LES_DEUX:
            return "vers et prose";
        default:
            return "forme inconnue";
    }
}

Poesie::Poesie(int c, string a, string t, string e, string i, Public p, Forme f)
    : Livre(c, a, t, e, i, p){
    forme = f;
}

string Poesie::getType() const {
    return "Poésie";
}

void Poesie::afficher() const {
    cout << "[Poésie] " << titre << " écrit par " << auteur << " en " << formeToString(forme) << endl;
}
