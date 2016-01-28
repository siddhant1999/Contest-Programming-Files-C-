//
//  main.cpp
//  Game of 31
//
//  Created by Siddhant Jain on 2014-09-23.
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
/*
6
356656

35665
3566
111126666
552525
 Sample Output
 
 B
 B
 A
 A
 A
 POS is the current game state of the CURRENT PLAYER
 boolean isWinning(position pos) {
 moves[] = possible positions to which I can move from the position pos;
 for (all x in moves)
    if ( !isWinning(x) )
        return true;
 
 return false;
 }
 */

map<vector<int>, bool> states;
// if from there they can win| true = you win from there| false = you lose from there
// you want true
// if nextint is > 31, x = true

bool isWinning(vector<int> state){
    int sum_vec = 0;
    
    for (int i = 1; i <=6; i++) {
        sum_vec += i * state[i];
    }
    if (sum_vec > 31)
        return true;
    
    if (sum_vec == 31)
        return false;

    if (states.count(state) == 1)
        return states[state];
    
    for (int i = 1; i <=6; i++)
        if (state[i] < 4){
            state[i]++;
            if (isWinning(state) == false)
                return states[state] = true;
            state[i]--;
        }
    return states[state] = false;
}

int main(void)
{
    int cases;
    cin >> cases;
    //cin.ignore();
    //getchar( );
    //char nothing; cin >> nothing;
    
    while (cases--) {
        vector<int> curstate(7, 0);
        string str="";
        cin >> str;
        //getline(cin, str);
        /*if (str == "") {
            cout << 'A' << endl;
            continue;
        }*/
        for (int i = 0; i < str.size(); i++){
            curstate[ str[i] - '0' ]++;
        }
        char cur='A'; char opp='B';
        if (str.size()%2 == 1) {
            cur='B'; opp='A';
        }
        
        //cout << '[' << str << ']' << endl;
        if ( isWinning(curstate) )
            cout << cur << endl;
        else
            cout << opp << endl;
    }
}

