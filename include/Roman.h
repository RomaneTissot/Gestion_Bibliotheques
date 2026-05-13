#ifndef ROMAN_H
#define ROMAN_H

#include "Livre.h"

class Roman : public Livre {
private:
    string genre;

public:
    Roman(int c, string a, string t, string e, string i, Public p, string g);

    string getType() const;
    void afficher() const;
};

#endif
