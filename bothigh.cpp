#include "bothigh.h"

int bot_high(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int botChoice = wybory1[round-1];
    if(round == 0){
        return 220;
    }
    if(botChoice > enemyChoice){
        if(enemyChoice > 190)
            return enemyChoice - 10;
        if(enemyChoice > 185)
            return enemyChoice - 5;
        if(enemyChoice > 180)
            return enemyChoice - 1;
        return 180;
    }
    else{
        if(((enemyChoice - botChoice)/2) + botChoice > 300)
            return 300;
        return ((enemyChoice - botChoice)/2) + botChoice;
    }
    return 300;
}