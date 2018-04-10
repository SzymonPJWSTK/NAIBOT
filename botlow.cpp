#include "botlow.h"

int bot_low(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int enemyChoice = wybory2[round-1];
    int botChoice = wybory1[round-1];

    int max = 0;
    for(int i = round-1; i > 1; i--){
        int tMax = abs(wybory2[i] - wybory2[i-1]);
        if (tMax > max){
            max = tMax;
        }
    }

    

     if(round == 0){
        return 220;
    }
    

    int tact = enemyChoice-max - 1;

    if(!(botChoice > enemyChoice)){
        return rand() % 120 + 180;;
    }
    else{
          if(tact > 180 && tact < 300)
             return tact;
        return 180;
    }
    return 300;
}
