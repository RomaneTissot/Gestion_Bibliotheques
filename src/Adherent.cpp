#include "../include/Adherent.h"
#include "../include/Bibliotheque.h"
#include "../include/Exceptions.h"


int Adherent::compteurAdherents = 0;

Adherent::Adherent(std::string n, std::string p, std::string a, Bibliotheque *biblio) :
nom(n), prenom(p), adresse(a), bibliothequeInscrite(biblio), maxEmprunts(3) {
  numeroAdherent = ++compteurAdherents;
}

Adherent::~Adherent() {
}

void Adherent::emprunter(Livre *livre) {
  if (livre == nullptr)
    return;

  int count = 0;
  try {
    int i = 0;
    while (true) {
      livresEmpruntes[i];
      count++;
      i++;
    }
  }
  catch (std::out_of_range &) {}

  if (count >= maxEmprunts) {
    throw ExceptionQuotaAtteint("Quota d'emprunt atteint pour " + nom);
  }

  if (livre->getEtat() != Etat::LIBRE) {
    throw ExceptionLivreNonDispo("Le livre " + std::to_string(livre->getCode()) + " n'est pas disponible.");
  }

  livresEmpruntes.ajouter(livre);
  livre->setEtat(Etat::EMPRUNTE);
  std::cout << nom << " a emprunte le livre " << livre->getCode() << std::endl;
}

void Adherent::rendre(Livre *livre) {
  if (livresEmpruntes.contient(livre)) {
    livresEmpruntes.supprimer(livre);
    livre->setEtat(Etat::LIBRE);
    std::cout << nom << " a rendu le livre " << livre->getCode() << std::endl;
  }
  else {
    std::cout << "Ce livre n'est pas emprunte par cet adherent." << std::endl;
  }
}

void Adherent::afficher() const {
  std::cout << "Adherent: " << nom << " " << prenom
            << " (No: " << numeroAdherent << ")" << " ("<< bibliothequeInscrite->getNom()<< ")" << std::endl;
  std::cout << "Livres empruntes: " << std::endl;
  livresEmpruntes.afficher();
}

std::ostream &operator<<(std::ostream &os, const Adherent &ad) {
  ad.afficher();
  return os;
}
