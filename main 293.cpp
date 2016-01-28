//
//  main.cpp
//  Chances of Winning
//
//  Created by Siddhant Jain on 1/19/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

// 1 is between 1 and 2
// 2 is between 1 and 3
// 3 is between 1 and 4
// 4 is between 2 and 3
// 5 is between 2 and 4
// 6 is between 3 and 4

vector<vector <int> > outcome(5, vector<int>(5, -9));
int fav = 3;
int favwins = 0;

bool finalscore(void){
    vector<int> scores(5, 0);
    for (int i = 1; i <= 4 ; i++) {
        for (int j = i+1; j<= 4; j++) {
            if (outcome[i][j] == -1)
                scores[j] +=3;
            if (outcome[i][j] == 0){
                scores[j] +=1;
                scores[i] +=1;
            }
            if (outcome[i][j] == 1)
                scores[i] +=3;
        }
    }
    //for (int i = 1; i <=4; i++) {
    //    cout << scores[i] << " ";
    //}
    //cout << endl;
    int favscore = scores[fav];
    sort(scores.begin(), scores.end());
    if (scores[4] == favscore && scores[3] < favscore)
        return true;
    
    return false;
}
void debug(int gamesdone){
    cout << gamesdone << ": ";
    for (int i = 1; i <= 4 ; i++)
        for (int j = i+1; j<= 4; j++)
            cout <<  outcome[i][j] << " ";
    cout << endl;
}
void recurse(int gamesdone){
    //debug(gamesdone);
    //all outcomes are determined and final scores are figured out
    if (gamesdone == 6) {
        if (finalscore() == true) {
            favwins++;
        }
        return;
    }
    //at least one outcome not determined and so we simulate all possible remaining games
    for (int i = 1; i <= 4 ; i++) {
        for (int j = i+1; j<= 4; j++) {
            
            if (outcome[i][j] == -9) {
                outcome[i][j] = -1; //i lost, j won
                recurse(gamesdone + 1);
                outcome[i][j] = 0; //tie
                recurse(gamesdone + 1);
                outcome[i][j] = 1; //i won, j lost
                recurse(gamesdone + 1);
                outcome[i][j] = -9;
                return;
            }
        }
    }
}

int main(void)
{
    int games, A, B, SA, SB, expo = 3;
    cin >> fav >> games;
    int g = games;

    while (g--) {
        cin >> A >> B >> SA >> SB;
        
        if (SA > SB)
            outcome[A][B] = 1;
        if (SA < SB)
            outcome[A][B] = -1;
        if (SA == SB) {
            outcome[A][B] = 0;
        }
    }
    recurse(games);
    cout << favwins;
}