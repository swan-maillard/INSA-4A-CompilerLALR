
#include "automate.h"
#include "state.h"
#include "symbole.h"
#include <iostream>
#include <memory>

void State::print() const { std::cout << this->name << std::endl; }

bool State0::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case INT:
        automate.decalage(s, new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(s, new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(s, new State1);
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State1::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case PLUS:
        automate.decalage(s, new State4); // 4
        break;
    case MULT:
        automate.decalage(s, new State5); // 5
        break;
    case FIN:
        automate.accepter();
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State2::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case INT:
        automate.decalage(s, new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(s, new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(s, new State6);
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State3::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        automate.reduction(
            1, new Expr(((Entier *)automate.popSymbol())->getVal()));
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State4::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case INT:
        automate.decalage(s, new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(s, new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(s, new State7);
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State5::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case INT:
        automate.decalage(s, new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(s, new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(s, new State8);
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State6::transition(Automate &automate, Symbole *s) {
    switch (*s) {
    case PLUS:
        automate.decalage(s, new State4);
        break;
    case MULT:
        automate.decalage(s, new State5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new State9);
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State7::transition(Automate &automate, Symbole *s) {
    int left;
    int right;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case FIN:
        left = unique_ptr<Expr>((Expr *)automate.popSymbol())->getVal();
        automate.popAndDestroySymbol();
        right = unique_ptr<Expr>((Expr *)automate.popSymbol())->getVal();
        automate.reduction(3, new Expr(left + right));
        break;
    case MULT:
        automate.decalage(s, new State5);
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State8::transition(Automate &automate, Symbole *s) {
    int left;
    int right;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case MULT:
    case FIN:
        left = unique_ptr<Expr>((Expr *)automate.popSymbol())->getVal();
        automate.popAndDestroySymbol();
        right = unique_ptr<Expr>((Expr *)automate.popSymbol())->getVal();
        automate.reduction(3, new Expr(left * right));
        break;
    default:
        automate.invalid();
    }
    return false;
}

bool State9::transition(Automate &automate, Symbole *s) {
    Expr *val;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case MULT:
    case FIN:
        automate.popAndDestroySymbol();
        val = (Expr *)automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3, val);
        break;
    default:
        automate.invalid();
    }
    return false;
}
