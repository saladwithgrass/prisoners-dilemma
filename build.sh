find . -name "*.gch" -delete

T4T_FILES="players/tit_for_tat/*cpp"
TESTER_FILES="players/tester/*cpp"
HEADER_FILES="players/generic_player.h players/players.h"
USED_FILES="core.cpp $T4T_FILES $TESTER_FILES"

g++ $USED_FILES &> logs/build.log