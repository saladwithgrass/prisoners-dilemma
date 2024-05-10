#pragma once
#include "../generic_player.h"

class Tester : public Generic_Player{
public:
    Tester(bool* self_table, bool* other_table);
    bool select() override;
private:
    // always fucks over in the first round
    // if opponent retaliates, apologises and 
    // cooperates for the rest of the game
    // otherwise continues to fuck over

    bool can_opponent_retaliate;
};