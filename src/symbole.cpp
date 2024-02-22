#include "symbole.h"
#include <iostream>

void Symbole::Affiche() { cout << Etiquettes[ident]; }

void Entier::Affiche() {
    Symbole::Affiche();
    cout << "(" << valeur << ")";
}

int Entier::getVal() { return this->valeur; }
int Expr::getVal() { return this->valeur; }
