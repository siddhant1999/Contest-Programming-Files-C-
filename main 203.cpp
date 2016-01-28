//
//  main.cpp
//  Rebrick
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



int isWinning(bool x, int itt){
    cout << x << " " << itt  << "   ***********************"<< endl;
    if (itt >= bricks.size()) {
        return 0;
    }
    int maxi = 0, maxref = 0;
    for (int i = 1; i <= 3 && (i+itt) < bricks.size(); i++) {
        cout << "i: " << i << endl;
        int curmax = 0;
        for (int j = 0; j < i; j++) {
            curmax += bricks[j+itt];//if curmax plus all the recursion is max then recurse it and only return that value
        }
        int recur = curmax + isWinning(!x, itt + i+1);// isWinning doesnt return anything so this is stupid
        if (recur > maxi) {
            maxi = recur;
            maxref = i+1;
        }
    }
    m[x] += maxi;
    //return curmax + isWinning(!x, itt + maxref);
    //return maxi;
    return isWinning(!x, itt + maxref);
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
            cout << isWinning(true, 0) << endl;
        
        bricks.clear();
        
    }
    
}

