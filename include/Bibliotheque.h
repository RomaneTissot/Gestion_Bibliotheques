#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include "Adherent.h"
#include "ListeChainee.h"
#include "Livre.h"
#include <iostream>
#include <string>



class Bibliotheque {
private:
  std::string nom;
  std::string adresse;
  std::string code;

  ListeChainee<Livre> listeLivres;
  ListeChainee<Adherent> listeAdherents;

  struct EmpruntDistant {
      Livre* livre;
      Bibliotheque* proprietaire; 
      
      EmpruntDistant(Livre* l, Bibliotheque* p) : livre(l), proprietaire(p) {}
      
      friend std::ostream& operator<<(std::ostream& os, const EmpruntDistant& e) {
          return os << "Livre " << e.livre->getCode() << " (Prop: " << (void*)e.proprietaire << ")";
      }
  };
  
  ListeChainee<EmpruntDistant>  livresEmpruntesExternes;

public:
  Bibliotheque(std::string n, std::string a, std::string c);
  ~Bibliotheque();

  void acheter(Livre *nouveauLivre);
  void supprimer(int codeLivre);
  void inscrire(Adherent *nouvelAdherent);

  void afficher() const;

  void demanderLivre(int isbn, Bibliotheque &autreBiblio);
  void rendreLivresPretes();

  std::string getNom() const { return nom; }
  ListeChainee<Livre> &getLivres() { return listeLivres; }
};

#endif
