//
//  main.cpp
//  A Game
//
//  Created by Siddhant Jain on 2014-10-18.
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

map<vector<int>, bool> states;// if from there they can win| true = you win from there| false = you lose from there
// you want true
// if nextint is > 31, x = true
int totalsum = 0;
int curmax = 0;
bool isWinning(vector<int> line, int ascore, int iseven){
    if (states.count(line) == 1)
        return states[line];
    bool check = false;
    for (int k = 0; k < line.size(); k++) {
        if (line[k] != 0) {
            check = true;
            break;
        }
    }
    if (line.size() == 0 || check == false) {//Remember to pop_back for numbers above then
        if (ascore >= (totalsum - ascore)){
            if (ascore > curmax) {
                curmax = ascore;
            }
            return states[line] = true;
        }
        else
            return states[line] = false;
    }
    
    int itt = 0;
    iseven++;
    while (1) {
        int maintain = line[itt];
        if (line[itt] != 0) {
            if (iseven%2 == 0)
                ascore += line[itt];
                
            line[itt] = 0;
            if (isWinning(line, ascore, iseven) == false)
                return states[line] = true;
            
            if (iseven%2 == 0)
                ascore -= line[itt];
            line[itt] = maintain;
            break;
        }
        itt++;
    }
    int maintain =line[line.size()-1];
    if (iseven%2 == 0) {
        ascore += maintain;
    }
    line.pop_back();
    if (isWinning(line, ascore, iseven) == false)
        return states[line] = true;
    
    line.push_back(maintain);
    ascore -= maintain;
    return states[line] = true;
}

int main(void)
{
    int num;
    cin >> num;
    vector<int> coins;
    while (num--) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
    }
    for (int i = 0; i < coins.size(); i++)
        totalsum += coins[i];
    
    cout << isWinning(coins, 0, 2) << endl;
    cout << curmax;
}









