#include "automate.h"
#include "expr.h"
#include "symbole.h"
#include <iostream>
#include <iterator>
#include <memory>

// Automate::Automate(std::string s) : lexer(s) {
//     statestack.push_back(std::make_unique<State0>());
//     lexer.Avancer();
//     statestack.back()->transition(*this,
//                                   std::unique_ptr<Symbole>(lexer.Consulter()));
// }

void Automate::run() {
    statestack.push_back(std::make_unique<State0>());
    lexer.Avancer();
    statestack.back()->transition(*this,
                                  std::unique_ptr<Symbole>(lexer.Consulter()));
}

void Automate::decalage(std::unique_ptr<Symbole> s, State *e) {
    this->symbolstack.push_back(std::move(s));
    this->statestack.push_back(std::unique_ptr<State>(e));
    lexer.Avancer();
    e->transition(*this, std::unique_ptr<Symbole>(lexer.Consulter()));
}

void Automate::transitionSimple(std::unique_ptr<Symbole> s, State *e) {
    this->symbolstack.push_back(std::move(s));
    this->statestack.push_back(std::unique_ptr<State>(e));
    e->transition(*this, std::unique_ptr<Symbole>(lexer.Consulter()));
}

void Automate::reduction(int n, std::unique_ptr<Symbole> s) {
    for (int i = 0; i < n; ++i) {
        statestack.pop_back();
    }
    statestack.back()->transition(*this, std::move(s));
}

void Automate::accepter() {
    auto expr = std::unique_ptr<Expr>(
        dynamic_cast<Expr *>(std::move(symbolstack.back()).release()));
    expr->Affiche();
    std::cout << " = " << expr->eval() << std::endl;
}

void Automate::invalid() { std::cout << "Ce calcul est invalide" << std::endl; }

void Automate::error(const Symbole &symbole) const {
    std::cout << lexer.getString() << '\n';
    for (int i = 0; i <= symbole.getSpan().second; ++i) {
        if (i < symbole.getSpan().first) {
            std::cout << ' ';
        } else {
            std::cout << '^';
        }
    }
    std::cout << '\n';
}

std::unique_ptr<Symbole> Automate::popSymbol() {
    auto s = std::move(symbolstack.back());
    symbolstack.pop_back();
    return s;
}

void Automate::popAndDestroySymbol() { symbolstack.pop_back(); }
