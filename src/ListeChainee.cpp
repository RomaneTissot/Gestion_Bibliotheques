#ifndef LISTECHAINEE_CPP
#define LISTECHAINEE_CPP

#include "../include/ListeChainee.h"

template <typename T>
ListeChainee<T>::ListeChainee() : tete(nullptr) {}

template <typename T>
ListeChainee<T>::~ListeChainee() {
  while (tete != nullptr) {
    Noeud *temp = tete;
    tete = tete->suivant;
    delete temp;
  }
}

template <typename T>
void ListeChainee<T>::ajouter(T *element) {
  Noeud *nouveau = new Noeud(element);
  if (tete == nullptr) {
    tete = nouveau;
  }
  else {
    Noeud *temp = tete;
    while (temp->suivant != nullptr) {
      temp = temp->suivant;
    }
    temp->suivant = nouveau;
  }
}

template <typename T>
void ListeChainee<T>::supprimer(T *element) {
  if (tete == nullptr)
    return;

  if (tete->data == element) {
    Noeud *temp = tete;
    tete = tete->suivant;
    delete temp;
    return;
  }

  Noeud *temp = tete;
  while (temp->suivant != nullptr && temp->suivant->data != element) {
    temp = temp->suivant;
  }

  if (temp->suivant != nullptr) {
    Noeud *aSupprimer = temp->suivant;
    temp->suivant = temp->suivant->suivant;
    delete aSupprimer;
  }
}

template <typename T>
bool ListeChainee<T>::contient(T *element) const {
  Noeud *temp = tete;
  while (temp != nullptr) {
    if (temp->data == element)
      return true;
    temp = temp->suivant;
  }
  return false;
}

template <typename T>
void ListeChainee<T>::afficher() const {
  Noeud *temp = tete;
  while (temp != nullptr) {
    std::cout << *(temp->data) << std::endl;
    temp = temp->suivant;
  }
}

template <typename T>
T *ListeChainee<T>::operator[](int index) {
  if (index < 0)
    throw std::out_of_range("Index negatif");

  Noeud *temp = tete;
  int count = 0;
  while (temp != nullptr) {
    if (count == index)
      return temp->data;
    count++;
    temp = temp->suivant;
  }
  throw std::out_of_range("Index hors limites");
}

template <typename T>
bool ListeChainee<T>::estVide() const {
  return tete == nullptr;
}

#endif
