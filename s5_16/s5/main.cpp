//
//  main.cpp
//  s5
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
vector<bool> list;
map <vector<bool>, big_int> done;
big_int m;
bool y = false;
void dp(big_int left){
    for (big_int i = left; i >= 0;i--){
        if (i == 0) {
            fori(list.size()){
                cout << list[i];
            }return;
        }
        //cout << endl<<double(clock())/CLOCKS_PER_SEC;
        
        
        /*
         T=15
         13 -> map
         7 -> 13
         left =7%(13-7)
         left = 1
         
         b[0]
         b[1]
         b[2]
         ...
         b[i] ****
         ...
         b[j] = b[j]
         
         T-=firstOccur
         
         b[T]
         */
    if (done.count(list) && !y) {
        big_int val = done[list];
        i = i%(val-i)+1;
        y =true;
        continue;
        //return;
    }
    
     done[list] = i;
        bool prevm =false;
        bool prev = false;
    
        if (list[list.size()-1] != list[1])
            prev = true;
        if (list[0] != list[list.size()-2])
            prevm = true;
    
        for (big_int i = 1; i < list.size()-1; i++) {
            if (list[i-1] != list[i+1]){
                list[i-1] = prev;
                prev = true;
                continue;
            }
            list[i-1] = prev;
            prev = false;
            
        }
        list[list.size()-2] = prev;
        list[list.size()-1] = prevm;
    }
   //dp(left-1);
}

int main(void)
{
    input;
    big_int num;
    cin >> num >> m;
    
    list = vector<bool>(num ,false);
    fori(num){
        char t;
        cin >> t;
        if(t == '1')
            list[i] = true;
    }
    //cout << "df";
    dp(m);
}

