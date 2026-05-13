#include "../include/Roman.h"
#include <iostream>

Roman::Roman(int c, string a, string t, string e, string i, Public p, string g)
    : Livre(c, a, t, e, i, p){
    genre = g;
    }

string Roman::getType() const {
    return "Roman";
}

void Roman::afficher() const {
    cout << "[Roman] " << titre << " écrit par " << auteur
         << " appartient au genre " << genre << endl;
}
