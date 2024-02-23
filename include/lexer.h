#pragma once

#include "symbole.h"
#include <string>

class Lexer {

public:
    Lexer(std::string s) : flux(s), tete(0), tampon(nullptr) {}
    ~Lexer() {}

    Symbole *Consulter();
    void Avancer();

    const std::string &getString() const;

protected:
    std::string flux;
    int tete;
    Symbole *tampon;
};
