#include "symbole.h"
#include <iostream>

void Symbole::Affiche() { std::cout << Etiquettes[ident]; }

void Entier::Affiche() {
    Symbole::Affiche();
    std::cout << "(" << valeur << ")";
}

int Entier::getVal() { return this->valeur; }
