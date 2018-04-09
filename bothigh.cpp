#include "bothigh.h"

int bot_high(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int previousEnemyChoice = wybory2[round-2];
    int botChoice = wybory1[round-1];
    if(round == 0){
        return rand() % 120 + 180;
    }
    if(botChoice > enemyChoice){
        if(enemyChoice - 20 >= 180)
            return rand() % 20 - enemyChoice;
        return 300;
    }
    else{
        if(((enemyChoice - botChoice)/2) + botChoice > 300)
            return 300;
        return ((enemyChoice - botChoice)/2) + botChoice;
    }
    return 300;
}