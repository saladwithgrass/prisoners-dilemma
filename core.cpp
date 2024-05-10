#include <iostream>
#include <stdio.h>

#include "players/players.h"

#define ROUNDS 200

// if both cooperate, they both get 3 points
// if both fuck each other over they both get 1 point
// if player1 fucks player2 over, player1 gets 5 points, player2 gets 0
// and vice versa

#define COOPERATION 3
#define MUTUAL_FUCKOVER 1
#define FUCKOVER_WINNER 5
#define FUCKOVER_LOSER 0

int current_round = 0;
bool player1_table[ROUNDS];
bool player2_table[ROUNDS];

void round(Generic_Player* player1, Generic_Player* player2) {
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

void print_tables() {
    printf("p1 | p2\n");
    char p1_answer_char, p2_answer_char;
    for (int i = 0; i < ROUNDS; ++i) {
        p1_answer_char = player1_table[i] ? 'C' : 'F';
        p2_answer_char = player2_table[i] ? 'C' : 'F';
        printf(" %c | %c\n", p1_answer_char, p2_answer_char);
    }
}

int main() {
    // create players
    Tit_For_Tat t4t(player1_table, player2_table);
    Tester tester(player2_table, player1_table);
    Generic_Player* p1 = dynamic_cast<Generic_Player*>(&t4t);
    Generic_Player* p2 = dynamic_cast<Generic_Player*>(&tester);
    for (int i = 0; i < ROUNDS; ++i) {
        round(p1, p2);
    }
    print_tables();
    return 0;
}