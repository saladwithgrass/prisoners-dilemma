#pragma once
#include "tester.h"

Tester::Tester(bool* self_table_init, bool* other_table_init) : 
            Generic_Player(self_table_init, other_table_init) {
                can_opponent_retaliate = 0;
            }

bool Tester::select() {
    // test if opponent will retaliate
    if (current_round == 0)
        return FUCK_OVER;
    
    if (current_round == 1) {
        return COOPERATE;
    }

    if (current_round == 2) {
        can_opponent_retaliate = !get_others_previous_result();
    }
    return can_opponent_retaliate;
}