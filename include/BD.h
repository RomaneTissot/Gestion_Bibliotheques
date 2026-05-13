#ifndef BD_H
#define BD_H

#include "Livre.h"

class BD : public Livre {
private:
    string dessinateur;

public:
    BD(int c, string a, string t, string e, string i, Public p, string d);

    string getType() const;
    void afficher() const;
};

#endif