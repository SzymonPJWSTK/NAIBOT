#include "bothigh.h"

int bot_high(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int previousEnemyChoice = wybory2[round-2];
    int botChoice = wybory1[round-1];
    int previousBotChoice = wybory1[round-2];
    int max = 0;
    for(int i = round-1; i > 0; i--){
        int tMax = previousBotChoice - enemyChoice;
        if (tMax > max){
            max = tMax;
        }
    }
    if (max == 120)
        max--;
    std::cout << max << std::endl;
    int tact = enemyChoice-(max + 1);
    if(round == 0){
        return 220;
    }
    if((botChoice == 300 && previousBotChoice != 300 )|| botChoice == 180)
        return 300;
    if(botChoice >= enemyChoice){
        if(tact >= 180)
            return tact;
        return 180;
    }
    else{
        if(((enemyChoice - botChoice)/2) + botChoice > 300)
            return 300;
        return ((enemyChoice - botChoice)/2) + botChoice;
    }
    return 300;
}