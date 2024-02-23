#include "expr.h"
#include <iostream>

void ValExpr::Affiche() { cout << this->val; }

int ValExpr::eval() const { return this->val; }

void AddExpr::Affiche() {
    cout << "(";
    this->left->Affiche();
    cout << "+";
    this->right->Affiche();
    cout << ")";
}

int AddExpr::eval() const { return this->left->eval() + this->right->eval(); }

void MulExpr::Affiche() {
    cout << "(";
    this->left->Affiche();
    cout << "*";
    this->right->Affiche();
    cout << ")";
}

int MulExpr::eval() const { return this->left->eval() * this->right->eval(); }
