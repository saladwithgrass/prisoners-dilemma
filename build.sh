find . -name "*.gch" -delete

T4T_FILES="players/tit_for_tat/*cpp"
TESTER_FILES="players/tester/*cpp"
WSLS_FILES="players/win_stay_lose_shift/*cpp"
RANDOM_FILES="players/random/*"

HEADER_FILES="players/generic_player.h players/players.h"
USED_FILES="core.cpp $T4T_FILES $TESTER_FILES $WSLS_FILES $RANDOM_FILES"

rm -rf logs
mkdir logs

g++ $USED_FILES &> logs/build.log