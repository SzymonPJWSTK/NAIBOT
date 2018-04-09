#include <iostream>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "botlow.h"
#include "bothigh.h" 

using namespace std;
 
void game(int choice_bot1, int choice_bot2, int *w);
 
const int R = 25;
const int ilosc_gier = 1000;
int wybory1 [ilosc_gier];
int wybory2 [ilosc_gier];
 
int main()
{
    int j=0;
    int choice1 = 0, choice2 = 0;
    int SCORE[2] = {0, 0};
    int *s;
    s = SCORE;
 
    srand(time(NULL));
    do{
        cout << "Runda " << j+1 << endl;
        choice1 = bot_low(SCORE[0], SCORE[1], j, wybory1, wybory2);
        choice2 = bot_high(SCORE[1], SCORE[0], j, wybory2, wybory1);
        cout << "GoodCop  wybral: " << choice1 << "\t";
        cout << "BadCop  wybral: " << choice2 << "\t" << endl;
        wybory1[j] = choice1;
        wybory2[j] = choice2;
        game(choice1, choice2, s);
        cout << endl << "Punktacja: \n\t" << SCORE[0] << "\n\t" << SCORE[1] << endl << endl << endl;
        j++;
    }
    while(j<ilosc_gier);
    cout << "Ncisnij ENTER aby kontynuowac...";
    getchar();
    system("clear");
    cout << "Koniec gry!\n\t GoodCop  uzyskal: "  << SCORE[0] << "\n\t BadCop  uzyskal: "
    << SCORE[1] << endl;
    getchar();
    return 0;
}
 
void game(int choice_bot1, int choice_bot2, int *w)
{
    bool flag=0;
    if((choice_bot1 < 180) || (choice_bot1 > 300)){
        if((choice_bot2 >= 180) && (choice_bot2 <= 300))
            w[1] += choice_bot2 + R;
        flag = 1;
    }
    if(!flag && ((choice_bot2 < 180) || (choice_bot2 > 300))){
        if((choice_bot1 >= 180) && (choice_bot1 <= 300))
            w[0] += choice_bot1 + R;
        flag = 1;
    }
   
    if (!flag) {
    if(choice_bot1 == choice_bot2){
           w[0] += choice_bot1;
        w[1] += choice_bot1;
    }
    else{
        if(choice_bot1 > choice_bot2){
            w[0] += choice_bot2 - R;
            w[1] += choice_bot2 + R;
        }          
        else{
            w[0] += choice_bot1 + R;
            w[1] += choice_bot1 - R;
        }          
    }
    }
}