//
//  main.cpp
//  Game Revised
//
//  Created by Siddhant Jain on 2014-10-19.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <iostream>
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
vector<int> coins;
vector<int> sums;
int best[1001][1001];

int sum(int i, int j){
    if (i == 0) {
        return sums[j];
    }
    return sums[j]-sums[i - 1];
}

int getbest(int i, int j){
    if (best[i][j] != -1) {
        return best[i][j];
    }
    if (i == j) {
        return best[i][j] = coins[i];
    }
    
    
    int takej =coins[j] + sum(i,j-1) - getbest(i, j-1);
    int takei = coins[i] + sum(i+1,j) - getbest(i+1,j);
    
    return best[i][j] = max(takei, takej);
}

int main(void)
{
    memset( best, -1, sizeof(best) );
    //cout << best[45][34];
    
    int num;
    cin >> num;
    int cursum = 0;
    while (num--) {
        int temp;
        cin >> temp;
        coins.push_back(temp);
        cursum += temp;
        sums.push_back(cursum);
    }
    
    
    
    cout << getbest(0 , coins.size()-1);
}

/*
a[] = 3,5,1,8,12,...6
sums  3,8,9,17...
 
 getsum(i,j)
    sums[i]-sums[j-1] == total sum of [i,...j]
*/
/*
There are a bunch of coins on a table, laid out in a straight line.
Each coin has a (positive) value from 1 to 1000. Now, you're going to play a game with a friend.

At every turn, you must remove a coin from one end of the line.
Turns alternate, so your friend goes immediately after you're done.
The game ends when there are no coins remaining.

An example game:
The coins start like this:
 
index= 1 2 3 4
coins= 4 4 9 4
 
 best(i,j) == max score for cur player when coins are [i,..j]
 only 2 choices:
 -take coin j --> coin[j] + sums(i,j-1) - best(i,..,j-1)
 -take coin i --> coin[i] + sums(i+1...j) - best(i+1,...j)
 max of both coices
 for any game state (i,j)  myScore + opScore = sums(i,j)
 best(1,n)
 
You always go first, so you take the 4 from the left side:
4 9 4
Your friend takes any of the 4s (it doesn't matter)
                                 9 4
                                 Now you can take the 9, and your friend takes the remaining 4.
                                 
                                 Your score, in this case, is 4+9 = 13.
                                 (In this case you can always beat your friend.)
                                 Find the maximum possible score you can achieve.
 */
