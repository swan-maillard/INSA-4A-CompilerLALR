#include "automate.h"
#include "lexer.h"
#include "state.h"
#include "symbole.h"
#include <iostream>
#include <memory>

int main(void) {
    // string chaine("(1+34)*123");
    string chaine;
    while (1) {
        cout << ">>";
        getline(cin, chaine);
        if (chaine == "q") {
            break;
        }
        Automate automate(chaine);
    };
    cout << "bye\n";
    return 0;
}
