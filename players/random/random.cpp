#include "random.h"

Random::Random(bool* self_table_init, bool* other_table_init) :
        Generic_Player(self_table_init, other_table_init) {
            std::srand(std::time(0));
            name = "random";
        }

bool Random::select() {
    return std::rand() % 2;
}