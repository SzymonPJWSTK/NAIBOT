#include "botlow.h"

int bot_low(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int botChoice = wybory1[round-1];

    int max = 0;
    for(int i = round-1; i > 0; i--){
        int tMax = wybory2[i] - wybory1[i-1];
        if (tMax > max){
            max = tMax;
        }
    }

    if(round == 0){
        return 180;
    }

    if(botChoice == 280 || botChoice == 300)
        return 220;
    else if (botChoice < 200)
        return 180;

    int ranValue = (rand() % 20);

    int tact = enemyChoice-(max + 1);
    if(botChoice > enemyChoice)
    {
          if(tact >= 180)
            return tact;
        return 300;
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
        return 230;
    }


    return 300;
}
