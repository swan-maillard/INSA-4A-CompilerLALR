#pragma once

#include "symbole.h"
#include <memory>
#include <string>

class Automate;

class State {
public:
    State(std::string name) : name(name){};
    virtual ~State() {}
    void print() const;
    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s) = 0;

protected:
    std::string name;
};

class State0 : public State {
public:
    State0() : State("Etat 0"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State1 : public State {
public:
    State1() : State("Etat 1"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State2 : public State {
public:
    State2() : State("Etat 2"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State3 : public State {
public:
    State3() : State("Etat State3"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State4 : public State {
public:
    State4() : State("Etat State4"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State5 : public State {
public:
    State5() : State("Etat State5"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State6 : public State {
public:
    State6() : State("Etat State6"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State7 : public State {
public:
    State7() : State("Etat State7"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State8 : public State {
public:
    State8() : State("Etat State8"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};

class State9 : public State {
public:
    State9() : State("Etat State9"){};

    virtual bool transition(Automate &automate, std::unique_ptr<Symbole> s);
};
