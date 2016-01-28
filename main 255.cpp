//
//  main.cpp
//  Nukit
//
//  Created by Siddhant Jain on 2014-10-11.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
using namespace std;

map<vector<int>, bool> states;
// if from there they can win| true = you win from there| false = you lose from there
// you want true
// if nextint is > 31, x = true

bool isWinning(vector<int> gamestate){
    if (states.count(gamestate) == 1)
        return states[gamestate];
    
    //AABDD
    if (gamestate[0] >= 2 && gamestate[1] >= 1 && gamestate[3] >= 2) {
        vector<int> temp = gamestate;
        temp[0] -= 2;
        temp[1]--;
        temp[3] -= 2;
        //cout << "AABDD: gamestate" << gamestate[0] << gamestate[1] << gamestate[2] << gamestate[3] << endl;
        if (isWinning(temp) == false)
            return states[gamestate] = true;
    }
    //ABCD
    if (gamestate[0] >= 1 && gamestate[1] >= 1 && gamestate[2] >= 1 && gamestate[3] >= 1) {
        vector<int> temp = gamestate;
        temp[0]--;
        temp[1]--;
        temp[2]--;
        temp[3]--;
        //cout << "ABCD: gamestate" << gamestate[0] << gamestate[1] << gamestate[2] << gamestate[3] << endl;
        if (isWinning(temp) == false)
            return states[gamestate] =true;
    }
    //CCD
    if (gamestate[2] >= 2 && gamestate[3] >= 1) {
        vector<int> temp = gamestate;
        temp[2] -= 2;
        temp[3]--;
        //cout << "CCD: gamestate" << gamestate[0] << gamestate[1] << gamestate[2] << gamestate[3] << endl;
        if (isWinning(temp) == false)
            return states[gamestate] = true;
    }
    //BBB
    if (gamestate[1] >= 3) {
        vector<int> temp = gamestate;
        temp[1] -= 3;
        //cout << "BBB: gamestate" << gamestate[0] << gamestate[1] << gamestate[2] << gamestate[3] << endl;
        if (isWinning(temp) == false)
            return states[gamestate] = true;
    }
    //AD
    if (gamestate[0] >= 1 && gamestate[3] >= 1) {
        vector<int> temp = gamestate;
        temp[0]--;
        temp[3]--;
        //cout << "AD: gamestate" << gamestate[0] << gamestate[1] << gamestate[2] << gamestate[3] << endl;
        if (isWinning(temp) == false)
            return states[gamestate] = true;
    }
    //cout << "false: gamestate" << gamestate[0] << gamestate[1] << gamestate[2] << gamestate[3] << endl;
    return states[gamestate] = false;
}

int main(void)
{
    int cases;
    cin >> cases;
    
    while (cases--) {
        vector<int> particles (4,0);
        
        for (int i = 0; i < 4; i++)
            cin >> particles[i];
        bool var = isWinning(particles);
        if (var == 1)
            cout << "Patrick" <<endl;
        
        else if(var == 0)
            cout << "Roland" << endl;
    }
}

