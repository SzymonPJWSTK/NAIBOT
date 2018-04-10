#include "bothigh.h"

int x_de(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
 if(round == 0){
        return 180;
    }
    int enemyChoice = wybory2[round-1];
    int previousEnemyChoice = wybory2[round-2];
    int botChoice = wybory1[round-1];
    int previousBotChoice = wybory1[round-2];
    int max = 0;
    int limit = 0;
    if(round < 10)
        limit = round;
    else
        limit = 10;
    for(int i = round-1; i > round - limit; i--){
        int tMax = previousBotChoice - enemyChoice;
        if (tMax > max && tMax != 120){
            max = tMax;
        }
    }

    if(botChoice > 250)
        return 200;

    if (max == 120)
        max--;
    int tact = enemyChoice - (max + 1);
    if(enemyChoice == 180)
        return 300 - max - 1;
    if(botChoice == 180)
        return 300;
    if(tact >= 180)
        return tact;
    return 180;
}