#ifndef POESIE_H
#define POESIE_H

#include "Livre.h"

enum class Forme { VERS, PROSE, LES_DEUX };

class Poesie : public Livre {
private:
    Forme forme;

public:
    Poesie(int c, string a, string t, string e, string i, Public p, Forme f);

    string getType() const;
    void afficher() const;
};

#endif
