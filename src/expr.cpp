#include "expr.h"
#include <iostream>
#include <memory>

void ValExpr::Affiche() { std::cout << this->val; }

int ValExpr::eval() const { return this->val; }

BinOp::BinOp(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
    : Expr(left->getSpan().first, left->getSpan().second) {
    this->left = std::move(left);
    this->right = std::move(right);
}

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
