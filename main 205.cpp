//
//  main.cpp
//  Game Brick
//
//  Created by Siddhant Jain on 2015-01-23.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vc;
typedef vector<vector<int> > vvc;
/*


void play(bool x, int itt, int me, int u){
    if (itt == bricks.size()-1) {
        tmax = max(me, tmax);
    }
    for (int i = 1; i <= 3; i++) {
        int cur = 0;
        for (int j = 0; j < i && (itt + j) < bricks.size(); j++) {
            tstor[i] += bricks[itt + j];
        }
        if (x)
            play(!x, itt + i, cur+me, u);
        if (!x)
            play(!x, itt + i,me, u+cur);
    }
}

int main(void)
{
    int num;
    cin >> num;
    
    while (num--) {
        int temp;
        cin >> temp;
        for (int i = 0; i < temp; i++) {
            int x;
            cin >> x;
            bricks.push_back(x);
        }
        
        play(true, 0, 0, 0);
        cout << tmax;
    }
}*/

vc bricks;
vc curmax;
vc tstor (4);

int tmax= 0;
int nmax = 0;

map<int, bool> states;
int N;

bool isWinning(int k){
    if (k >= N) {
        return false;
    }
    if (states.count(k) == 1) {
        return states[k];
    }
    cout << k << endl;

    for (int i = 2; i <= 9; i++)
        if ( isWinning(i * k)==false )
            return states[k] = true;
    
    return states[k] = false;
}

int main(void)
{
    cin >> N;
    while (N--) {
        int temp;
        cin >> temp;
        for (int i = 0; i < temp; i++) {
            int x;
            cin >> x;
            bricks.push_back(x);
        }
        cout << isWinning(1) << endl;
        cout << states.size();
        bricks.clear();
    }
    
}

