#pragma once

#include "lexer.h"
#include "state.h"
#include "symbole.h"
#include <vector>
class Automate {
public:
    Automate(std::string s);
    void decalage(Symbole *s, State *e);
    void transitionSimple(Symbole *s, State *e);
    void reduction(int n, Symbole *s);
    void accepter();
    Symbole *popSymbol();
    void popAndDestroySymbol();

protected:
    std::vector<Symbole *> symbolstack;
    std::vector<State *> statestack;
    Lexer lexer;
};
