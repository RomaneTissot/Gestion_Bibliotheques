#ifndef ALBUM_H
#define ALBUM_H

#include "Livre.h"
#include <string>

using namespace std;

enum class Illustration {
    PHOTOS,
    DESSINS,
    PHOTOS_ET_DESSINS
};

class Album : public Livre {
private:
    Illustration illustration;

public:
    Album(int c, string a, string t, string e, string i, Public p, Illustration ill);

    string getType() const;
    void afficher() const;
};

#endif
