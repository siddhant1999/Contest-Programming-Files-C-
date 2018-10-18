//
//  main.cpp
//  Game Show Math
//
//  Created by Siddhant Jain on 2016-02-15.
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
int target;
vector<char> used;
char cache [101][64002];

bool dp(int x, int curt){//index of number
    if (curt > 32000 || curt < -32000) {
        return false;
    }
    if (x == 0) {
        return list[0] == curt;
    }
    if (cache[x][curt+32000]!=-1) {
        return cache[x][curt+32000];
    }
    //12 256 6   12 == 4
    if (dp(x-1, curt-list[x])) {
        used.push_back('+');
        return cache[x][curt+32000]= true;
    }
    if (dp(x-1, curt+list[x])) {
        used.push_back('-');
        return cache[x][curt+32000]= true;
    }
   
        if (dp(x-1, curt*list[x])) {
            used.push_back('/');
            return cache[x][curt+32000]= true;
        }
    
    if (curt%list[x] == 0) {
         if (dp(x-1, curt/list[x])) {
             used.push_back('*');
             return cache[x][curt+32000]= true;
         }
    }
    return cache[x][curt+32000]= false;
}

int main(void)
{
    input;
    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        list.clear();
        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < num; i++) {
            int temp;
            cin >> temp;
            list.push_back(temp);
        }
        cin >> target;
        if(dp(num-1, target)){
            cout << list[0];
            for(int i = 1; i <list.size();i++){
                cout << used[i-1] <<list[i];
            }
            cout << '=' << target << endl;
        }else cout << "NO EXPRESSION" << endl;
        used.clear();
    }
}

