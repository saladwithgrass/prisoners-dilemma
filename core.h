#include <iostream>
#include <stdio.h>

#include "players/players.h"
#include <string>

#define COOPERATION 3
#define MUTUAL_FUCKOVER 1
#define FUCKOVER_WINNER 5
#define FUCKOVER_LOSER 0
#define MAX_ROUNDS 200
// if both cooperate, they both get 3 points
// if both fuck each other over they both get 1 point
// if player1 fucks player2 over, player1 gets 5 points, player2 gets 0
// and vice versa

class Core {
public:
    enum class Player_Name {tit_for_tat, win_stay_lose_shift, tester, random};

    void game(Player_Name player1, Player_Name player2, int rounds = MAX_ROUNDS);
private:
    void round(Generic_Player* player1, Generic_Player* player2);
    void print_tables();
    void print_scores();
    int current_round = 0;
    bool player1_table[MAX_ROUNDS];
    bool player2_table[MAX_ROUNDS];
    std::string players[4] = {
        "tit for tat",
        "win-stay lose-shift",
        "tester",
        "random"
    };

    Generic_Player* create_player_by_name(Player_Name name, int player_id); 

};