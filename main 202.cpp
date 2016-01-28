//
//  main.cpp
//  Brick 3
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


int isWinning(bool x, int itt){
    cout <<"bool: " <<x << " itt: " << itt  << "   ***********************"<< endl;
    if (itt >= bricks.size()) {
        return 0;
    }
    int mini = 999999999, minref = 0, maxi = 0;
    for (int i = 1; i <= 3 && (i+itt) < bricks.size(); i++) {
        cout << "i: " << i << endl;
        int curmax = 0;
        for (int j = 0; j < i; j++) {
            curmax += bricks[j+itt];
        }
        cout << "curmax: " << curmax << endl;
        int recur = isWinning(!x, itt + i+1);
        maxi = max(curmax,maxi);
        if (recur < mini) {
            mini = recur;
            minref = i+1;
        }
    }
    m[x] += maxi;
    //isWinning(!x, minref + itt);
        return maxi;
}
// lets try to minimize the other person instead
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
        cout << endl << m[0];
        cout << endl << m[1];
        bricks.clear();
        
    }
    
}
