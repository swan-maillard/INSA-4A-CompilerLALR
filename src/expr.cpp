#include "expr.h"
#include <iostream>

void ValExpr::Affiche() { std::cout << this->val; }

int ValExpr::eval() const { return this->val; }

void AddExpr::Affiche() {
    std::cout << "(";
    this->left->Affiche();
    std::cout << "+";
    this->right->Affiche();
    std::cout << ")";
}

int AddExpr::eval() const { return this->left->eval() + this->right->eval(); }

void MulExpr::Affiche() {
    std::cout << "(";
    this->left->Affiche();
    std::cout << "*";
    this->right->Affiche();
    std::cout << ")";
}

int MulExpr::eval() const { return this->left->eval() * this->right->eval(); }
