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
    BinOp(Expr *left, Expr *right) : left(left), right(right) {}

protected:
    unique_ptr<Expr> left;
    unique_ptr<Expr> right;
};

class AddExpr : public BinOp {
public:
    AddExpr(Expr *left, Expr *right) : BinOp(left, right) {}
    virtual void Affiche();
    virtual int eval() const;
};

class MulExpr : public BinOp {
public:
    MulExpr(Expr *left, Expr *right) : BinOp(left, right) {}
    virtual void Affiche();
    virtual int eval() const;
};
