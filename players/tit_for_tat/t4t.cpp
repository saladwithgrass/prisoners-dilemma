#pragma once
#include "t4t.h"

Tit_For_Tat::Tit_For_Tat(bool *self_table_init, bool *other_table_init)  : Generic_Player(self_table_init, other_table_init) {}

bool Tit_For_Tat::select() {
    if (current_round == 0) return COOPERATE;
    // printf("%d\n", get_others_previous_result());
    return get_others_previous_result();
}