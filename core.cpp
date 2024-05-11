#include "core.h"

void Core::round(Generic_Player* player1, Generic_Player* player2) {
    // get players answers
    bool p1_answer = player1->select();
    bool p2_answer = player2->select();
    // write answers down
    player1_table[current_round] = p1_answer;
    player2_table[current_round] = p2_answer;
    // add scores accordingly
    if (p1_answer == COOPERATE && p2_answer == COOPERATE) { // both cooperate
        player1->finish_round(COOPERATION);
        player2->finish_round(COOPERATION);
    } else if (p1_answer == COOPERATE && p2_answer == FUCK_OVER) { // p2 fucks p1
        player1->finish_round(FUCKOVER_LOSER);
        player2->finish_round(FUCKOVER_WINNER);
    } else if (p1_answer == FUCK_OVER && p2_answer == COOPERATE) { // p1 fucks p2
        player1->finish_round(FUCKOVER_WINNER);
        player2->finish_round(FUCKOVER_LOSER);
    } else {    // they try to fuck each other over
        player1->finish_round(MUTUAL_FUCKOVER);
        player2->finish_round(MUTUAL_FUCKOVER);
    }
    current_round += 1;
}

void Core::print_tables() {
    printf("p1 | p2\n");
    char p1_answer_char, p2_answer_char;
    for (int i = 0; i < MAX_ROUNDS; ++i) {
        p1_answer_char = player1_table[i] ? 'C' : 'F';
        p2_answer_char = player2_table[i] ? 'C' : 'F';
        printf(" %c | %c\n", p1_answer_char, p2_answer_char);
    }
}

Generic_Player* Core::create_player_by_name(Player_Name name, int player_id) {
        Generic_Player* result;
        bool* self_table;
        bool* other_table;
        if (player_id == 1) {
            self_table = player1_table;
            other_table = player2_table;
        } else if (player_id == 2) {
            self_table = player2_table;
            other_table = player1_table;
        } else {
            throw std::logic_error("unexpected player id");
        }
        switch (name) {
            case Player_Name::tit_for_tat:
                result = new Tit_For_Tat(self_table, other_table);
                break;
            case Player_Name::tester:
                result = new Tester(self_table, other_table);
                break;
            case Player_Name::random:
                result = new Random(self_table, other_table);
                break;
            case Player_Name::win_stay_lose_shift:
                result = new Win_Stay_Lose_Shift(self_table, other_table);
                break;
            default:
                throw std::logic_error("unexpected player name");

        }
        // result will be deleted after game
        return result;
}

void Core::game(Player_Name player1_startegy, Player_Name player2_strategy, int rounds) {
    Generic_Player* player1 = create_player_by_name(player1_startegy, 1); // to be deleted
    Generic_Player* player2 = create_player_by_name(player2_strategy, 2); // to be deleted
    
    current_round = 0;
    for (int i = 0; i < rounds; ++i) {
        round(player1, player2);
    }

    printf("%s score: %d\n", player1->get_name(), player1->get_score());
    printf("%s score: %d\n", player2->get_name(), player2->get_score());

    delete player1;
    delete player2;
}