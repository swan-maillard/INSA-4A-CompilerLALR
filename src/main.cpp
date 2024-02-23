#include "automate.h"
#include "lexer.h"
#include "state.h"
#include "symbole.h"
#include <iostream>
#include <memory>

int main(void) {
    std::string chaine;
    while (1) {
        std::cout << ">>";
        getline(std::cin, chaine);
        if (chaine == "q" || std::cin.eof()) {
            break;
        }
        Automate automate(chaine);
        automate.run();
    };
    std::cout << "bye\n";
    return 0;
}
