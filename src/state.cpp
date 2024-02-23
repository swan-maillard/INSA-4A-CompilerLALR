
#include "automate.h"
#include "expr.h"
#include "state.h"
#include "symbole.h"
#include <iostream>
#include <memory>

void State::print() const { std::cout << this->name << std::endl; }

bool State0::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    switch (*s) {
    case INT:
        automate.decalage(std::move(s), new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(std::move(s), new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(std::move(s), new State1);
        break;
    default:
        automate.error(*s);
        // automate.invalid();
        std::cout << "Expected \"value\" or \"(\", but found \"" << Repr[*s]
                  << "\"\n";
    }
    return false;
}

bool State1::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    switch (*s) {
    case PLUS:
        automate.decalage(std::move(s), new State4); // 4
        break;
    case MULT:
        automate.decalage(std::move(s), new State5); // 5
        break;
    case FIN:
        automate.accepter();
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"+\" or \"*\" or nothing, but found \""
                  << Repr[*s] << "\"\n";
    }
    return false;
}

bool State2::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    switch (*s) {
    case INT:
        automate.decalage(std::move(s), new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(std::move(s), new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(std::move(s), new State6);
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"val\" or \"(\" but found \"" << Repr[*s]
                  << "\"\n";
    }
    return false;
}

bool State3::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    std::unique_ptr<Entier> entier;
    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
        (void)s.release();
        entier = std::unique_ptr<Entier>(
            dynamic_cast<Entier *>(automate.popSymbol().release()));
        automate.reduction(1, std::make_unique<ValExpr>(std::move(entier)));
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"+\" or \"*\" or \")\" or nothing but found \""
                  << Repr[*s] << "\"\n";
    }
    return false;
}

bool State4::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    switch (*s) {
    case INT:
        automate.decalage(std::move(s), new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(std::move(s), new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(std::move(s), new State7);
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"val\" or \"(\" but found \"" << Repr[*s]
                  << "\"\n";
    }
    return false;
}

bool State5::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    switch (*s) {
    case INT:
        automate.decalage(std::move(s), new State3); // 3
        break;
    case OPENPAR:
        automate.decalage(std::move(s), new State2); // 2
        break;
    case EXPR:
        automate.transitionSimple(std::move(s), new State8);
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"val\" or \"(\" but found \"" << Repr[*s]
                  << "\"\n";
        automate.invalid();
    }
    return false;
}

bool State6::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    switch (*s) {
    case PLUS:
        automate.decalage(std::move(s), new State4);
        break;
    case MULT:
        automate.decalage(std::move(s), new State5);
        break;
    case CLOSEPAR:
        automate.decalage(std::move(s), new State9);
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"+\" or \")\" or \"*\" but found \"" << Repr[*s]
                  << "\"\n";
    }
    return false;
}

bool State7::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case FIN:
        (void)s.release();
        right = std::unique_ptr<Expr>(
            dynamic_cast<Expr *>(automate.popSymbol().release()));
        automate.popAndDestroySymbol();
        left = std::unique_ptr<Expr>(
            dynamic_cast<Expr *>(automate.popSymbol().release()));
        automate.reduction(
            3, make_unique<AddExpr>(std::move(left), std::move(right)));
        break;
    case MULT:
        automate.decalage(std::move(s), new State5);
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"+\" or \")\" or \"*\" or nothing but found \""
                  << Repr[*s] << "\"\n";
    }
    return false;
}

bool State8::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case MULT:
    case FIN:
        (void)s.release();
        right = std::unique_ptr<Expr>(
            dynamic_cast<Expr *>(automate.popSymbol().release()));
        automate.popAndDestroySymbol();
        left = std::unique_ptr<Expr>(
            dynamic_cast<Expr *>(automate.popSymbol().release()));
        automate.reduction(
            3, std::make_unique<MulExpr>(std::move(left), std::move(right)));
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"+\" or \")\" or \"*\" or nothing but found \""
                  << Repr[*s] << "\"\n";
    }
    return false;
}

bool State9::transition(Automate &automate, std::unique_ptr<Symbole> s) {
    std::unique_ptr<Symbole> in;
    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case MULT:
    case FIN:
        (void)s.release();
        automate.popAndDestroySymbol();
        in = automate.popSymbol();
        automate.popAndDestroySymbol();
        automate.reduction(3, std::move(in));
        break;
    default:
        automate.error(*s);
        std::cout << "Expected \"+\" or \")\" or \"*\" or nothing but found \""
                  << Repr[*s] << "\"\n";
    }
    return false;
}
