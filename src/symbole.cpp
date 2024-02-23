#include "symbole.h"
#include <iostream>
#include <utility>

void Symbole::Affiche() { std::cout << Etiquettes[ident]; }

void Entier::Affiche() {
    Symbole::Affiche();
    std::cout << "(" << valeur << ")";
}

int Entier::getVal() { return this->valeur; }

std::pair<int, int> Symbole::getSpan() const {
    return std::make_pair(this->spanStart, this->spanEnd);
}
