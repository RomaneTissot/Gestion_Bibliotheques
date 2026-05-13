#ifndef LIVRE_H
#define LIVRE_H

#include <string>
#include <iostream>
using namespace std;

enum class Public { ADULTE, ADO, JEUNESSE, TOUT_PUBLIC };
enum class Etat { LIBRE, EMPRUNTE, PRETE };

class Livre {
protected:
    int code;
    string auteur;
    string titre;
    string editeur;
    string isbn;
    Public publicCible;
    Etat etat;

public:
    Livre(int c, string a, string t, string e, string i, Public p);
    virtual ~Livre();

    int getCode() const;
    Etat getEtat() const;
    void setEtat(Etat e);

    virtual string getType() const = 0;
    virtual void afficher() const = 0;
};

std::ostream& operator<<(std::ostream& os, const Livre& livre);

#endif
