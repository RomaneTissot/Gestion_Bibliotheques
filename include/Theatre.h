#ifndef THEATRE_H
#define THEATRE_H

#include "Livre.h"

class Theatre : public Livre {
private:
    int siecle;

public:
    Theatre(int c, string a, string t, string e, string i, Public p, int s);

    string getType() const;
    void afficher() const;
};

#endif
