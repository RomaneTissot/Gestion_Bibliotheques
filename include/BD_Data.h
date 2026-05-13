#ifndef BD_DATA_H
#define BD_DATA_H

#include "Bibliotheque.h"
#include "Roman.h"
#include "Album.h"
#include "BD.h"
#include "Theatre.h"
#include "Poesie.h"
#include "Adherent.h"

struct BaseDeDonnees {
    Bibliotheque* bibliotheques[3];
    Livre* livres[10];
    Adherent* adherents[5];
    
    BaseDeDonnees() {
        bibliotheques[0] = new Bibliotheque("Bibliotheque Centrale", "1 Place de la Republique", "BIB001");
        bibliotheques[1] = new Bibliotheque("Mediatheque du Quartier Nord", "25 Rue des Lilas", "BIB002");
        bibliotheques[2] = new Bibliotheque("Bibliotheque Universitaire", "Campus Universitaire", "BIB003");
        
        livres[0] = new Roman(1, "Victor Hugo", "Les Miserables", "Gallimard", "978-2070409228", Public::ADULTE, "Historique");
        livres[1] = new Roman(2, "Albert Camus", "L'Etranger", "Folio", "978-2070360024", Public::ADO, "Philosophique");
        livres[2] = new BD(3, "Goscinny", "Asterix le Gaulois", "Dargaud", "978-2012101333", Public::TOUT_PUBLIC, "Uderzo");
        livres[3] = new BD(4, "Herge", "Tintin au Tibet", "Casterman", "978-2203001152", Public::TOUT_PUBLIC, "Herge");
        livres[4] = new Theatre(5, "Moliere", "Le Malade Imaginaire", "Flammarion", "978-2080712875", Public::ADULTE, 17);
        livres[5] = new Theatre(6, "Racine", "Phedre", "Larousse", "978-2035861566", Public::ADULTE, 17);
        livres[6] = new Poesie(7, "Baudelaire", "Les Fleurs du Mal", "Gallimard", "978-2070411825", Public::ADULTE, Forme::VERS);
        livres[7] = new Poesie(8, "Rimbaud", "Une Saison en Enfer", "Gallimard", "978-2070319558", Public::ADO, Forme::PROSE);
        livres[8] = new Album(9, "Collectif", "Animaux du Monde", "National Geographic", "978-1234567890", Public::JEUNESSE, Illustration::PHOTOS);
        livres[9] = new Album(10, "Auteur Inconnu", "Contes Illustres", "Hachette", "978-0987654321", Public::JEUNESSE, Illustration::DESSINS);
        
        bibliotheques[0]->acheter(livres[0]);
        bibliotheques[0]->acheter(livres[1]);
        bibliotheques[0]->acheter(livres[2]);
        bibliotheques[0]->acheter(livres[3]);
        
        bibliotheques[1]->acheter(livres[4]);
        bibliotheques[1]->acheter(livres[5]);
        bibliotheques[1]->acheter(livres[6]);
        
        bibliotheques[2]->acheter(livres[7]);
        bibliotheques[2]->acheter(livres[8]);
        bibliotheques[2]->acheter(livres[9]);
        
        adherents[0] = new Adherent("Dupont", "Jean", "12 Rue de Paris");
        adherents[1] = new Adherent("Martin", "Marie", "45 Avenue des Champs");
        adherents[2] = new Adherent("Bernard", "Pierre", "8 Boulevard Central");
        adherents[3] = new Adherent("Petit", "Sophie", "33 Impasse du Lac");
        adherents[4] = new Adherent("Moreau", "Lucas", "77 Rue du Commerce");
        
        bibliotheques[0]->inscrire(adherents[0]);
        bibliotheques[0]->inscrire(adherents[1]);
        bibliotheques[1]->inscrire(adherents[2]);
        bibliotheques[1]->inscrire(adherents[3]);
        bibliotheques[2]->inscrire(adherents[4]);
    }
    
    ~BaseDeDonnees() {
        for (int i = 0; i < 3; i++) {
            delete bibliotheques[i];
        }
    }

};

#endif
