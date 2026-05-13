#include "../include/Album.h"
#include <iostream>


static string illustrationToString(Illustration ill)
{
    switch (ill) {
        case Illustration::PHOTOS:
            return "photos";
        case Illustration::DESSINS:
            return "dessins";
        case Illustration::PHOTOS_ET_DESSINS:
            return "photos et dessins";
        default:
            return "illustrations inconnues";
    }
}

Album::Album(int c,
             string a,
             string t,
             string e,
             string i,
             Public p,
             Illustration ill)
    : Livre(c, a, t, e, i, p)
{
    illustration = ill;
}

string Album::getType() const
{
    return "Album";
}

void Album::afficher() const
{
    cout << "[Album] " << titre << " écrit par " << auteur << " avec pour illustration des " << illustrationToString(illustration) << endl;
}
