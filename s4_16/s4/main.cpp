//
//  main.cpp
//  s4
//
//  Created by Siddhant Jain on 2016-02-17.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
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
#include <bitset>
#include <iomanip>
#include <ctime>
using namespace std;
//board = vcc (num+1, vc (num+1, 0));


#define x0 first
#define y0 second.first
#define z0 second.second

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define mpp(one,two,three) make_pair( one,  make_pair( two, three ) )
#define tp(one) cout << (one).first << " " << (one).second << endl;
#define ms(thing, val) memset( (thing), (val), sizeof(thing) )
#define mt make_tuple
#define fori(lim) for(int (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(int (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(int (k) = (0); (k) < (lim);(k)++ )
#define input ios::sync_with_stdio(false)
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vc list;

int maxi = 0;

void dp(void){
    /*fori(list.size()){
        cout << list[i] << " ";
    }cout << endl;*/
    if (double(clock())/CLOCKS_PER_SEC > 2.8) {
        cout << maxi;
        exit(0);
    }
    maxi = max(maxi, list[0]);
    for (int i = 0; i < list.size()-1; i++) {
        maxi = max(maxi, max(list[i],list[i+1]));
                   
        if (list[i] == list[i+1]) {
            int val = list[i];
            list.erase(list.begin()+i);
            list[i] = val*2;
            dp();
            list[i] = val;
            list.insert(list.begin() +i, val);
        }
        if (i+2 < list.size()) {
            if (list[i] == list[i+2]) {
                int v, b;
                v= list[i];
                b=list[i+1];
                
                int sum = list[i] + list[i+1] + list[i+2];
                list.erase(list.begin()+i);
                list.erase(list.begin()+i);
                list[i] = sum;
                dp();
                list[i] = v;
                list.insert(list.begin() +i, b);
                list.insert(list.begin() +i, v);
            }
        }
    }
    return;
}


int main(void)
{
    input;
    
    int num;
    cin >> num;
    
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    dp();
    cout << maxi;
}

