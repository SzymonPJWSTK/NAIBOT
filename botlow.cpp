#include "botlow.h"

int bot_low(int points_bot1, int points_bot2, int round, int wybory1[], int wybory2[])
{
    int tactic = 0;
    int enemyTactic = 0;
    int testData[20] = {180, 180, 200, 210, 220, 210, 200, 195, 190, 185, 190, 195, 200, 251, 252, 253, 252, 251, 250, 300};
   
    //WYSLANIE DANYCH "TESTOWYCH"
    if((round < 15) || (round >= 35 && round < 50)){
        return rand() % 120 + 180;
    }
    else if(round >= 15 && round < 35){
        return testData[round-15];
    }
 
    //TABLICA Z REAKCJAMI PRZECIWNIKA NA DANE TESTOWE
    int enemyData[20];
    for(int i = 16; i <=35; i++){
        enemyData[i-16] = wybory2[i];
    }
    //SPRAWDZENIE "TAKTYKI"
    if(enemyData[14]-enemyData[13] == enemyData[15]-enemyData[14]){
        enemyTactic = enemyData[14]-enemyData[13];
        tactic = enemyTactic + (rand() % 2 + enemyTactic/2);
    }
    else if(enemyData[12]-enemyData[11]==enemyData[11]-enemyData[10]){
        enemyTactic = enemyData[12]-enemyData[11];
        tactic = enemyTactic + (rand() % 5 + enemyTactic/2);
    }
    else if(enemyData[3]-enemyData[2] == enemyData[4]-enemyData[3]){
        enemyTactic = enemyData[4]-enemyData[3];
        tactic = enemyTactic + (rand() % 10 + enemyTactic/2);
    }
    //WYSLANIE ODPOWIEDNICH DANYCH
    if(round == 50 || round == 51 || (round > 51 && wybory1[round-1] == 300 && wybory1[round-2] != 300) || wybory1[round-1]-tactic < 180){
        return 300;
    }
    else{
        return wybory1[round-1] - tactic;
    }
}