#include "botlow.h"

int bot_low(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int botChoice = wybory1[round-1];
    if(round == 0){
        return 220;
    }

    if(botChoice == 280 || botChoice == 300)
        return 250;
    else if (botChoice < 200)
        return 300;

    if(botChoice > enemyChoice)
    {
        if(botChoice - 5 >= 180)
             return botChoice - 5;
        else
            return 180;
    }
    else if (botChoice == enemyChoice)
    {
        if(enemyChoice - 5 >= 180)
            return enemyChoice - 5;
        else
            return 280;
    }
    else
    {
        return 300;
    }


    return 300;
}
