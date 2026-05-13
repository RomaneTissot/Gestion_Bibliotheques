#ifndef ADHERENT_H
#define ADHERENT_H

#include "ListeChainee.h"
#include "Livre.h"
#include <iostream>
#include <string>


class Bibliotheque;

class Adherent {
private:
  std::string nom;
  std::string prenom;
  std::string adresse;
  int numeroAdherent;
  Bibliotheque *bibliothequeInscrite;
  ListeChainee<Livre> livresEmpruntes;
  int maxEmprunts;

  static int compteurAdherents;

public:
  Adherent(std::string n, std::string p, std::string a,
           Bibliotheque *biblio = nullptr);
  ~Adherent();

  void emprunter(Livre *livre);
  void rendre(Livre *livre);
  void afficher() const;

  int getNumero() const { return numeroAdherent; }
  void setBibliotheque(Bibliotheque *biblio) { bibliothequeInscrite = biblio; }

  friend std::ostream &operator<<(std::ostream &os, const Adherent &ad);
};

#endif
