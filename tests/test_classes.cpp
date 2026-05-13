#include <iostream>
#include <string>
#include "../include/Livre.h"
#include "../include/BD.h"
#include "../include/Poesie.h"
#include "../include/Roman.h"
#include "../include/Theatre.h"
#include "../include/Album.h"

using namespace std;

int main()
{
    BD bd(001, "Hergé", "Tintin en Amérique", "Casterman", "220300102X", Public::JEUNESSE, "Hergé");
    bd.getType();
    bd.afficher();

    Poesie p(002, "Baudelaire", "Les fleurs du mal", "Belin Éducation", "1035805316", Public::ADULTE, Forme::LES_DEUX);
    p.getType();
    p.afficher();

    Roman r(003, "Sir Arthur Conan Doyle", "Sherlock Holmes", "Hauteville", "2381228721", Public::TOUT_PUBLIC, "Roman policier");
    r.getType();
    r.afficher();

    Theatre t(004, "Molière", "Le malade imaginaire", "Belin Éducation", "1035807157", Public::TOUT_PUBLIC, 17);
    t.getType();
    t.afficher();

    Album a(005, "Lélia Wanick Salgado", "Le malade imaginaire", "Taschen", "3836542617", Public::TOUT_PUBLIC, Illustration::PHOTOS);
    a.getType();
    a.afficher();

    return 0;
}
