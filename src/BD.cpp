#include "../include/BD.h"
#include <iostream>

using namespace std;

BD::BD(int c, string a, string t, string e, string i, Public p, string d)
    : Livre(c, a, t, e, i, p){
    dessinateur = d;
}

string BD::getType() const {
    return "Bande Dessinée";
}

void BD::afficher() const {
    cout << "[BD] " << titre << " écrite par " << auteur
         << " et illustrée par " << dessinateur << endl;
}
