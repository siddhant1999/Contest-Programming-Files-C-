//
//  main.cpp
//  Golf
//
//  Created by Siddhant Jain on 1/1/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
using namespace std;

/*vector<int> fibcache(100, -1);
int fib( int n )
{
    if (fibcache[n] != -1) {
        return fibcache[n];
    }
    //cout << n << endl;
    if (n<1) return 0;
    if (n==1) return 1;
    int sum= fib(n-2) + fib(n-1);
    fibcache[n] = sum;
    return sum;
}

int main(void){
    cout << fib(48) << endl;
}
*/

vector<int> clubs;
//vector<int> best(6000,-1);
//vector<int> prev(6000,-1);
int best[6000];

// getbest(k)=optimal number of club strokes to get exactly k
int getbest(int k){
    if (k ==0) {
        return 0;
    }
    if ( k<0 ) return 50000000;
    
    
    if (best[k] != -1) {
        return best[k];
    }
    
    int minclubs = 5000000;
    int prevclub = 0;
    
    for (int i =0; i < clubs.size(); i++) {
        int cur_club=clubs[i];
        int num_strokes=getbest(k-cur_club)+1;
        
        if (num_strokes < minclubs) {
            minclubs = num_strokes;
            prevclub = cur_club;
        }
    }
    
    //prev[k] = prevclub;
    best[k]= minclubs;
   // cout << "k=" << k << " best=" << best[k] << " prev=" << prevclub << endl;
    if (minclubs == 5000000) {
        return 0;
    }
    return minclubs;
}

// getbest(100) --> best(99), (3), (50)

int main(void){
    for (int i = 0; i < 6000; i++) {
        best[i] = -1;
    }
    int target;
    cin >> target;
    int number;
    cin >> number;
    while (number--) {
        int twmp;
        cin >> twmp;
        clubs.push_back(twmp);
    }
    if (getbest(target) != 0)
    cout << "Roberta wins in "<< getbest(target) <<" strokes.";
    else
        cout << "Roberta wins in ";
    //recursion(amount);
}