#include "automate.h"
#include "symbole.h"
#include <iostream>

Automate::Automate(std::string s) : lexer(s) {
    State0 *state = new State0;
    statestack.push_back(state);
    lexer.Avancer();
    state->transition(*this, lexer.Consulter());
};
void Automate::decalage(Symbole *s, State *e) {
    this->symbolstack.push_back(s);
    this->statestack.push_back(e);
    lexer.Avancer();
    cout << "deca";
    lexer.Consulter()->Affiche();
    e->transition(*this, lexer.Consulter());
}
void Automate::transitionSimple(Symbole *s, State *e) {
    this->symbolstack.push_back(s);
    this->statestack.push_back(e);
    e->transition(*this, lexer.Consulter());
}
void Automate::reduction(int n, Symbole *s) {
    for (int i = 0; i < n; ++i) {
        delete statestack.back();
        statestack.pop_back();
    }
    statestack.back()->transition(*this, s);
}
void Automate::accepter() { statestack.back()->print(); }

Symbole *Automate::popSymbol() {
    Symbole *s = symbolstack.back();
    symbolstack.pop_back();
    return s;
}

void Automate::popAndDestroySymbol() {
    Symbole *s = symbolstack.back();
    symbolstack.pop_back();
    delete s;
}
