#include "../include/Theatre.h"
#include <iostream>

Theatre::Theatre(int c, string a, string t, string e, string i, Public p, int s)
    : Livre(c, a, t, e, i, p){
    siecle = s;
    }

string Theatre::getType() const {
    return "Théâtre";
}

void Theatre::afficher() const {
    cout << "[Théâtre] " << titre << " écrit par " << auteur << " au " << siecle << " ème siècle " << endl;
}
