#pragma once
#include <stdexcept>

#define COOPERATE 1
#define FUCK_OVER 0

// prototype class for all players
// cannot be used
class Generic_Player{
public:

    virtual bool select() {
        throw std::logic_error("Generic_Player::select() should never be called");
        return -1;
    };
    void finish_round(int points) {
        current_round++;
        score += points;
    }

protected:

    Generic_Player(bool* self_table_init, bool* other_table_init) {
        self_table = self_table_init;
        other_table = other_table_init;
    }

    // different strategies need a different amount of 
    // previous results so count tells how far into the 
    // past we look
    bool get_others_previous_result(int count = 0) {
        if (count > current_round)
            throw std::out_of_range("trying to get nonexistent result");
        return other_table[current_round - count];
    };

    bool get_self_previous_result(int count = 0) {
        if (count > current_round)
            throw std::out_of_range("trying to get nonexistent result");
        return self_table[current_round - count];
    };

    // to keep track of how many rounds 
    // have already been played
    int current_round = 0;
    
    // player's score
    // note that all the addition is done in core game
    int score = 0;

    // previous choices of this player
    bool* self_table;

    // previous choices of the other player
    bool* other_table;
};