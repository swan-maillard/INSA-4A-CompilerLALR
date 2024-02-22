#include "automate.h"
#include "lexer.h"
#include "state.h"
#include "symbole.h"
#include <iostream>
#include <memory>

int main(void) {
    string chaine("(1+34)*123");

    Automate automate(chaine);
    return 0;
}
