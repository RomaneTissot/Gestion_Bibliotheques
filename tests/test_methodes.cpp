#include <iostream>
#include <string>
#include "../include/Livre.h"
#include "../include/BD.h"
#include "../include/Poesie.h"
#include "../include/Roman.h"
#include "../include/Theatre.h"
#include "../include/Album.h"
#include "../include/Bibliotheque.h"
#include "../include/Adherent.h"

using namespace std;

int main(){
    Bibliotheque biblio("Bibliotheque", "Adresse", "Code");
    
    Roman rom(1, "Auteur", "Titre", "Editeur", "Isbn", Public::ADULTE, "sci-fi");
    Theatre the(2, "Shake", "Ph", "edi Hall", "Isbn", Public::ADULTE, 15);
    biblio.acheter(&rom);
    biblio.acheter(&the);

    Bibliotheque biblio2("biblio2", "34443", "Code2");
    BD bd1(3, "Herge","tintin en amerique", "casterman", "220300102X", Public::JEUNESSE, "Herge");
    Poesie p1(4, "Baudelaire", "Les fleurs du mal", "Belin Education", "1035805316", Public::ADULTE, Forme::LES_DEUX);
    biblio2.acheter(&bd1);
    biblio2.acheter(&p1);
    biblio2.supprimer(3);
    biblio2.afficher();

    biblio2.demanderLivre(1, biblio);
    biblio2.rendreLivresPretes();

    Adherent adherent("Plaisir", "Titouan", "la P");
    biblio.inscrire(&adherent);
    biblio.afficher();

    adherent.emprunter(&rom);
    adherent.afficher();
    adherent.rendre(&rom);
    adherent.afficher();

    return 0;
}