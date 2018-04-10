#include "botlow.h"

int bot_low(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int botChoice = wybory1[round-1];
    if(round == 0){
        return 180;
    }

    if(botChoice == 280 || botChoice == 300)
        return 250;
    else if (botChoice < 200)
        return 300;

    int ranValue = (rand() % 20);

    if(botChoice > enemyChoice)
    {
        if(botChoice - ranValue >= 180)
             return botChoice - ranValue;
        else
            return 180;
    }
    else if (botChoice == enemyChoice)
    {
        if(enemyChoice - ranValue >= 180)
            return enemyChoice - ranValue;
        else
            return 280;
    }
    else
    {
        return 300;
    }


    return 300;
}
