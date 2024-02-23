#pragma once

#include "lexer.h"
#include "state.h"
#include "symbole.h"
#include <memory>
#include <vector>
class Automate {
public:
    Automate(std::string s);
    void decalage(Symbole *s, State *e);
    void transitionSimple(Symbole *s, State *e);
    void reduction(int n, Symbole *s);
    void accepter();
    void invalid();
    std::unique_ptr<Symbole> popSymbol();
    void popAndDestroySymbol();

protected:
    std::vector<std::unique_ptr<Symbole>> symbolstack;
    std::vector<std::unique_ptr<State>> statestack;
    Lexer lexer;
};
