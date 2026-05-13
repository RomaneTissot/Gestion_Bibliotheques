#include "../include/Bibliotheque.h"
#include "../include/Exceptions.h"

Bibliotheque::Bibliotheque(std::string n, std::string a, std::string c)
    : nom(n), adresse(a), code(c) {}

Bibliotheque::~Bibliotheque() {

}

void Bibliotheque::acheter(Livre *nouveauLivre) {
  listeLivres.ajouter(nouveauLivre);
  std::cout << "Bibliotheque " << nom << " a achete le livre "
            << nouveauLivre->getCode() << std::endl;
}

void Bibliotheque::supprimer(int codeLivre) {

  try {
    Livre *cible = nullptr;
    int i = 0;
    while (true) {
      try {
        Livre *l = listeLivres[i];
        if (l->getCode() == codeLivre) {
          cible = l;
          break;
        }
        i++;
      }
      catch (std::out_of_range &) {
        break;
      }
    }

    if (cible) {
      if (cible->getEtat() == Etat::EMPRUNTE) {
        std::cout << "Impossible de supprimer le livre " << codeLivre
                  << " : il est actuellement emprunte." << std::endl;
        return;
      }
      listeLivres.supprimer(cible);
      std::cout << "Livre " << codeLivre << " supprime de la bibliotheque "
                << nom << std::endl;
    }
    else {
      std::cout << "Livre introuvable pour suppression." << std::endl;
    }
  }
  catch (...) {
    std::cerr << "Erreur lors de la suppression" << std::endl;
  }
}

void Bibliotheque::inscrire(Adherent *nouvelAdherent) {
  if (nouvelAdherent) {
    nouvelAdherent->setBibliotheque(this);
    listeAdherents.ajouter(nouvelAdherent);
    std::cout << "Nouvel adherent inscrit: " << nouvelAdherent->getNumero()
              << std::endl;
  }
}

void Bibliotheque::afficher() const {
  std::cout << "=== Inventaire Bibliotheque " << nom << " ===" << std::endl;
  listeLivres.afficher();
  std::cout << "========================================" << std::endl;
}

void Bibliotheque::demanderLivre(int codeLivre, Bibliotheque &autreBiblio) {
  std::cout << "Demande de transfert inter-bibliotheque..." << std::endl;
  try {
    Livre *cible = nullptr;
    int i = 0;
    ListeChainee<Livre> &livresAutre = autreBiblio.getLivres();

    while (true) {
      try {
        Livre *l = livresAutre[i];
        if (l->getCode() == codeLivre) {
          cible = l;
          break;
        }
        i++;
      }
      catch (std::out_of_range &) {
        break;
      }
    }

    if (cible && cible->getEtat() == Etat::LIBRE) {
      livresAutre.supprimer(cible);
      
      this->acheter(cible); 
      
      EmpruntDistant* emprunt = new EmpruntDistant(cible, &autreBiblio);
      livresEmpruntesExternes.ajouter(emprunt);

      std::cout << "Transfert reussi du livre " << codeLivre << " de "
                << autreBiblio.nom << " vers " << this->nom << std::endl;
    }
    else {
      std::cout
          << "Livre non disponible ou introuvable dans l'autre bibliotheque."
          << std::endl;
    }

  }
  catch (...) {
    std::cerr << "Erreur lors du transfert" << std::endl;
  }
}

void Bibliotheque::rendreLivresPretes() {
  std::cout << "--- Retour des livres empruntes aux autres bibliotheques ---" << std::endl;
  
  bool actionFaite = true;
  while(actionFaite) {
      actionFaite = false;
      int i = 0;
      while(true) {
          try {
              EmpruntDistant* emprunt = livresEmpruntesExternes[i];
              Livre* l = emprunt->livre;
              Bibliotheque* prop = emprunt->proprietaire;
              
              if(l->getEtat() == Etat::LIBRE) {
                  std::cout << "Retour du livre " << l->getCode() << " a son proprietaire." << std::endl;
                  
                  this->supprimer(l->getCode());
                  
                  prop->acheter(l); 
                  
                  livresEmpruntesExternes.supprimer(emprunt);
                  delete emprunt;
                  
                  actionFaite = true; 
                  break;
              }
              else {
                  std::cout << "Livre " << l->getCode() << " est actuellement emprunte par un adherent, retour impossible." << std::endl;
              }
              i++;
          }
          catch(std::out_of_range&) {
              break;
          }
      }
  }
}
