#pragma once

#include <string>

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const std::string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS",   "MULT",
                                  "INT",     "FIN",      "ERREUR", "EXPR"};

class Symbole {
public:
    Symbole(int i) : ident(i) {}
    virtual ~Symbole() {}
    operator int() const { return ident; }
    virtual void Affiche();

protected:
    int ident;
};

class Entier : public Symbole {
public:
    Entier(int v) : Symbole(INT), valeur(v) {}
    ~Entier() {}
    virtual void Affiche();
    int getVal();

protected:
    int valeur;
};
