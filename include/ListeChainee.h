#ifndef LISTECHAINEE_H
#define LISTECHAINEE_H

#include <iostream>
#include <stdexcept>

template <typename T> class ListeChainee {
private:
  struct Noeud {
    T *data;
    Noeud *suivant;

    Noeud(T *d) : data(d), suivant(nullptr) {}
  };

  Noeud *tete;

public:
  ListeChainee();
  ~ListeChainee();

  void ajouter(T *element);
  void supprimer(T *element);
  bool contient(T *element) const;
  void afficher() const;

  friend std::ostream &operator<<(std::ostream &os, const ListeChainee &liste) {
    typename ListeChainee<T>::Noeud *temp = liste.tete;
    while (temp != nullptr) {
      os << *(temp->data) << "\n";
      temp = temp->suivant;
    }
    return os;
  }

  T *operator[](int index);

  bool estVide() const;
};

#include "ListeChainee.cpp"

#endif
