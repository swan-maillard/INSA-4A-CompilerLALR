#pragma once

#include <iostream>
#include <string>

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPR };

const std::string Etiquettes[] = {"OPENPAR", "CLOSEPAR", "PLUS",   "MULT",
                                  "INT",     "FIN",      "ERREUR", "EXPR"};
const std::string Repr[] = {"(", ")", "+", "*", "number", "$", "error", "expr"};

class Symbole {
public:
    Symbole(int i, int spanStart, int spanEnd)
        : ident(i), spanStart(spanStart), spanEnd(spanEnd) {}
    virtual ~Symbole() {}
    operator int() const { return ident; }
    virtual void Affiche();
    // virtual const std::string &repr() const;
    std::pair<int, int> getSpan() const;

protected:
    int ident;
    int spanStart;
    int spanEnd;
};

class Entier : public Symbole {
public:
    Entier(int v, int spanStart, int spanEnd)
        : Symbole(INT, spanStart, spanEnd), valeur(v) {}
    ~Entier() {}
    virtual void Affiche();
    int getVal();

protected:
    int valeur;
};
