#pragma once

#include "symbole.h"
#include <memory>

class Expr : public Symbole {
public:
    Expr() : Symbole(EXPR) {}
    ~Expr() {}
    virtual int eval() const = 0;
};

class ValExpr : public Expr {
public:
    ValExpr(int val) : val(val){};
    virtual void Affiche();
    virtual int eval() const;

protected:
    int val;
};

class BinOp : public Expr {
public:
    BinOp(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
        : left(std::move(left)), right(std::move(right)) {}

protected:
    std::unique_ptr<Expr> left;
    std::unique_ptr<Expr> right;
};

class AddExpr : public BinOp {
public:
    AddExpr(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
        : BinOp(std::move(left), std::move(right)) {}
    virtual void Affiche();
    virtual int eval() const;
};

class MulExpr : public BinOp {
public:
    MulExpr(std::unique_ptr<Expr> left, std::unique_ptr<Expr> right)
        : BinOp(std::move(left), std::move(right)) {}
    virtual void Affiche();
    virtual int eval() const;
};
