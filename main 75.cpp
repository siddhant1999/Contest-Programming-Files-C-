//
//  main.cpp
//  Prime
//
//  Created by Siddhant Jain on 2015-02-22.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <queue>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <ctime>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;
int MAX = 999999999;
vcc board;
vector<bool> ifprime(900000002, true);

void precompute(long sum){
    
    ifprime[0] = false;
    ifprime[1] = false;
    
    for (int i = 3; i < sum; i+= 2) {
        if (ifprime[i] == true)
            for (int j = 3; j*i <= sum; j+= 2) {
                ifprime[j*i] = false;
            }
    }

}

int main(void)
{
    cout << "start" << endl;
    precompute(100000001);
    for (int i = 1; i < 100000001; i++) {
  
            if (ifprime[i] && i%2 != 0)
                cout << i << endl;
        if(i==2) cout << 2 << endl;
        
    }
    cout << "done";
    
    for (int i = 0; i < 100000; i++) {
        cout << i << " " << ifprime[i] << endl;
    }
    int s;
    cin >> s;
    int x = 0;
    for (int k = 0; x < s; k++) {
        if (ifprime[k] && k%2 != 0) {
            cout << k << endl;
            x++;
        }
        if (k == 2){
            cout << 2 << endl;
            x++;
        }
    }
}

