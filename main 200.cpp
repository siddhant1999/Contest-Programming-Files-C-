//
//  main.cpp
//  Brick 4
//
//  Created by Siddhant Jain on 2015-01-27.
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

int N;
vc bricks;
vc m(2,0);
bool curval = true;
map<int, int> cache;
map<int, int> ind;//how many did you take


void isWinning(int itt){
    if (itt < 3) {
        for (int i = 0; i <= itt; i++)
            cache[itt] += bricks[i];
    }
    
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
        //cout << isWinning(0) << endl;
        cout << endl << m[0];
        cout << endl << m[1];
        bricks.clear();
        
    }
    
}