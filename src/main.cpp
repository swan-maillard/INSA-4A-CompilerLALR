#include "automate.h"
#include "lexer.h"
#include "state.h"
#include "symbole.h"
#include <iostream>
#include <memory>

int main(void) {
    // string chaine("(1+34)*123");
    std::string chaine;
    while (1) {
        std::cout << ">>";
        getline(std::cin, chaine);
        if (chaine == "q") {
            break;
        }
        Automate automate(chaine);
    };
    std::cout << "bye\n";
    return 0;
}
