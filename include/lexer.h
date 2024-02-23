#pragma once

#include "symbole.h"
#include <string>

class Lexer {

public:
    Lexer(std::string s) : flux(s), tete(0), tampon(nullptr) {}
    ~Lexer() {}

    Symbole *Consulter();
    void Avancer();

protected:
    std::string flux;
    int tete;
    Symbole *tampon;
};
