#include "wsls.h"

Win_Stay_Lose_Shift::Win_Stay_Lose_Shift(bool*self_table_init, bool* other_table_init) :
                     Generic_Player(self_table_init, other_table_init) {}

bool Win_Stay_Lose_Shift::select() {
    if (current_round == 0) 
        return COOPERATE;
    return get_self_previous_result() == get_others_previous_result();
}