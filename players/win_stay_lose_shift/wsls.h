#pragma once
#include "../generic_player.h"

class Win_Stay_Lose_Shift : public Generic_Player{
    // this one cooperates if it and
    // its opponent moved alike in previous round
    // otherwise defects
public:
    Win_Stay_Lose_Shift(bool* self_table_init, bool* other_table_init);
    bool select() override;

};