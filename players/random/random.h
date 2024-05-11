#include "../generic_player.h"
#include <cstdlib>
#include <ctime>

class Random : public Generic_Player {
public:
    Random(bool* self_table_init, bool* other_table_init);
    bool select() override;

};