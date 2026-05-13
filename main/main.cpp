#include <iostream>
#include <string>
#include <limits>
#include <vector>

#include "../include/BD_Data.h"

using namespace std;

vector<Livre*> livresSupplementaires;
vector<Adherent*> adherentsSupplementaires;

void afficherMenu() {
    cout << endl;
    cout << "      SYSTEME DE GESTION BIBLIOTHEQUE" << endl;
    cout<< endl;
    cout << "1. Afficher les livres" << endl;
    cout << "2. Ajouter un livre" << endl;
    cout << "3. Inscrire un adherent" << endl;
    cout << "4. Emprunter un livre" << endl;
    cout << "5. Rendre un livre" << endl;
    cout << "6. Supprimer un livre" << endl;
    cout << "7. Emprunt inter-bibliotheques" << endl;
    cout << "8. Rendre les livres empruntes (inter-bib)" << endl;
    cout << "0. Quitter" << endl;
    cout << endl;
    cout << "Votre choix: ";
}

void afficherBibliotheques(BaseDeDonnees& db) {
    cout << "\nBibliotheques disponibles:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << i << ". " << db.bibliotheques[i]->getNom() << endl;
    }
}

void afficherAdherents(BaseDeDonnees& db) {
    cout << "\nAdherents:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << ". ";
        db.adherents[i]->afficher();
    }
    int idx = 5;
    for (auto* adh : adherentsSupplementaires) {
        cout << idx++ << ". ";
        adh->afficher();
    }
}

void afficherLivres(BaseDeDonnees& db) {
    cout << "\nLivres:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << ". ";
        cout << (db.livres[i]->getEtat() == Etat::LIBRE ? "[LIBRE] " : "[EMPRUNTE] ");
        db.livres[i]->afficher();
    }
    int idx = 10;
    for (auto* livre : livresSupplementaires) {
        cout << idx++ << ". ";
        cout << (livre->getEtat() == Etat::LIBRE ? "[LIBRE] " : "[EMPRUNTE] ");
        livre->afficher();
    }
}

int lireEntier(const string& message) {
    int valeur;
    cout << message;
    while (!(cin >> valeur)) {
        cout << "Entree invalide. " << message;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valeur;
}

string lireChaine(const string& message) {
    string valeur;
    cout << message;
    getline(cin, valeur);
    return valeur;
}

Livre* getLivre(BaseDeDonnees& db, int index) {
    if (index < 10) return db.livres[index];
    if (index - 10 < (int)livresSupplementaires.size()) return livresSupplementaires[index - 10];
    return nullptr;
}

Adherent* getAdherent(BaseDeDonnees& db, int index) {
    if (index < 5) return db.adherents[index];
    if (index - 5 < (int)adherentsSupplementaires.size()) return adherentsSupplementaires[index - 5];
    return nullptr;
}

int main() {
    BaseDeDonnees db;
    
    int choix;
    do {
        afficherMenu();
        cin >> choix;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        switch (choix) {
            case 1: {
                afficherBibliotheques(db);
                int numBib = lireEntier("Bibliotheque (0-2): ");
                if (numBib >= 0 && numBib < 3) {
                    db.bibliotheques[numBib]->afficher();
                }
                break;
            }
            
            case 2: {
                cout << "\nType de livre:" << endl;
                cout << "1. Roman  2. BD  3. Theatre  4. Poesie  5. Album" << endl;
                int type = lireEntier("Type: ");
                
                int code = lireEntier("Code: ");
                string auteur = lireChaine("Auteur: ");
                string titre = lireChaine("Titre: ");
                string editeur = lireChaine("Editeur: ");
                string isbn = lireChaine("ISBN: ");
                
                cout << "Public: 1.Adulte 2.Ado 3.Jeunesse 4.Tout public: ";
                int pub = lireEntier("");
                Public publicCible = (pub == 1) ? Public::ADULTE : (pub == 2) ? Public::ADO : (pub == 3) ? Public::JEUNESSE : Public::TOUT_PUBLIC;
                
                Livre* nouveau = nullptr;
                switch (type) {
                    case 1: {
                        string genre = lireChaine("Genre: ");
                        nouveau = new Roman(code, auteur, titre, editeur, isbn, publicCible, genre);
                        break;
                    }
                    case 2: {
                        string dessinateur = lireChaine("Dessinateur: ");
                        nouveau = new BD(code, auteur, titre, editeur, isbn, publicCible, dessinateur);
                        break;
                    }
                    case 3: {
                        int siecle = lireEntier("Siecle: ");
                        nouveau = new Theatre(code, auteur, titre, editeur, isbn, publicCible, siecle);
                        break;
                    }
                    case 4: {
                        cout << "Forme: 1.Vers 2.Prose 3.Les deux: ";
                        int f = lireEntier("");
                        Forme forme = (f == 1) ? Forme::VERS : (f == 2) ? Forme::PROSE : Forme::LES_DEUX;
                        nouveau = new Poesie(code, auteur, titre, editeur, isbn, publicCible, forme);
                        break;
                    }
                    case 5: {
                        cout << "Illustration: 1.Photos 2.Dessins 3.Les deux: ";
                        int ill = lireEntier("");
                        Illustration illustration = (ill == 1) ? Illustration::PHOTOS : (ill == 2) ? Illustration::DESSINS : Illustration::PHOTOS_ET_DESSINS;
                        nouveau = new Album(code, auteur, titre, editeur, isbn, publicCible, illustration);
                        break;
                    }
                }
                
                if (nouveau) {
                    afficherBibliotheques(db);
                    int numBib = lireEntier("Ajouter a quelle bibliotheque (0-2): ");
                    if (numBib >= 0 && numBib < 3) {
                        db.bibliotheques[numBib]->acheter(nouveau);
                        livresSupplementaires.push_back(nouveau);
                    }
                }
                break;
            }
            
            case 3: {
                string nom = lireChaine("Nom: ");
                string prenom = lireChaine("Prenom: ");
                string adresse = lireChaine("Adresse: ");
                
                afficherBibliotheques(db);
                int numBib = lireEntier("Inscrire a quelle bibliotheque (0-2): ");
                
                if (numBib >= 0 && numBib < 3) {
                    Adherent* nouvelAdh = new Adherent(nom, prenom, adresse);
                    db.bibliotheques[numBib]->inscrire(nouvelAdh);
                    adherentsSupplementaires.push_back(nouvelAdh);
                }
                break;
            }
            
            case 4: {
                afficherAdherents(db);
                int numAdh = lireEntier("Numero adherent: ");
                Adherent* adh = getAdherent(db, numAdh);
                
                if (adh) {
                    afficherLivres(db);
                    int numLivre = lireEntier("Numero livre: ");
                    Livre* livre = getLivre(db, numLivre);
                    
                    if (livre) {
                        try {
                            adh->emprunter(livre);
                        } catch (const exception& e) {
                            cout << "Erreur: " << e.what() << endl;
                        }
                    }
                }
                break;
            }
            
            case 5: {
                afficherAdherents(db);
                int numAdh = lireEntier("Numero adherent: ");
                Adherent* adh = getAdherent(db, numAdh);
                
                if (adh) {
                    afficherLivres(db);
                    int numLivre = lireEntier("Numero livre: ");
                    Livre* livre = getLivre(db, numLivre);
                    
                    if (livre) {
                        adh->rendre(livre);
                    }
                }
                break;
            }
            
            case 6: {
                afficherBibliotheques(db);
                int numBib = lireEntier("De quelle bibliotheque (0-2): ");
                
                if (numBib >= 0 && numBib < 3) {
                    afficherLivres(db);
                    int codeLivre = lireEntier("Code du livre a supprimer: ");
                    db.bibliotheques[numBib]->supprimer(codeLivre);
                }
                break;
            }
            
            case 7: {
                afficherBibliotheques(db);
                int bibDemandeur = lireEntier("Bibliotheque demandeuse (0-2): ");
                int bibSource = lireEntier("Bibliotheque source (0-2): ");
                
                if (bibDemandeur >= 0 && bibDemandeur < 3 && bibSource >= 0 && bibSource < 3) {
                    int codeLivre = lireEntier("Code du livre a emprunter: ");
                    db.bibliotheques[bibDemandeur]->demanderLivre(codeLivre, *db.bibliotheques[bibSource]);
                }
                break;
            }
            
            case 8: {
                afficherBibliotheques(db);
                int numBib = lireEntier("Bibliotheque qui rend ses emprunts (0-2): ");
                if (numBib >= 0 && numBib < 3) {
                    db.bibliotheques[numBib]->rendreLivresPretes();
                }
                break;
            }
            
            case 0:
                cout << "\nAu revoir!" << endl;
                break;
                
            default:
                cout << "\nChoix invalide." << endl;
        }
        
    } while (choix != 0);

    for (auto* livre : livresSupplementaires) delete livre;
    for (auto* adh : adherentsSupplementaires) delete adh;

    return 0;
}
