#ifndef T4T_HPP
#define T4T_HPP
#pragma once
#include "../generic_player.h"

class Tit_For_Tat : public Generic_Player {
public:
    Tit_For_Tat(bool *self_table_init, bool *other_table_init);
    bool select() override;
};

#endif