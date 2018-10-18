//
//  main.cpp
//  Factor Solitaire
//
//  Created by Siddhant Jain on 2016-01-28.
//  Copyright Â© 2016 Siddhant Jain. All rights reserved.
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
vcc board;
vc list;
int num;

/*vc factors(int n){
 vc l;
 for (int i =1; i*i <= n; i++) {
 if (n%i == 0) {
 l.push_back(i);
 }
 }
 //sort(l.begin(), l.end());
 return l;
 }*/

int dp (int c){
    /*if (double(clock())/CLOCKS_PER_SEC > 2.8) {
        cout << 333;
        exit(0);
    }*/
    if (c > num) {
        return MAX;
    }
    if (c==num) {
        return 0;
    }
    if (list[c] != -1) {
        return list[c];
    }
    int mini = MAX;
    for (int i =1; i*i <= c; i++) {
        if (c%i == 0) {
            int a = dp(c+i)+ c/i;
            int b = dp(c+c/i)+ i;
            mini = min(mini, min(a,b));
        }
    }
    return list[c] = mini;
}

int main(void)
{
    input;
    
    cin >> num;
    list = vc(num+1, -1);
    cout << dp(1);
    
}
/*
 
 In the game of Factor Solitaire, you start with the number 1, and try to change it to some given target number n by repeatedly using the following operation. In each step, if c is your current number, you split it into two positive factors a, b of your choice such that c = a * b. You then add a to your current number c to get your new current number. Doing this costs you b points. You continue doing this until your current number is n, and you try to achieve this at the cost of a minimum total number of points.
 
 For example, here is one way to get to 15:
 
 start with 1
 change 1 to 1+1=2â€”cost so far is 1
 change 2 to 2+1=3â€”cost so far is 1+2
 change 3 to 3+3=6â€”cost so far is 1+2+1
 change 6 to 6+6=12â€”cost so far is 1+2+1+1
 change 12 to 12+3=15â€”cost so far is 1+2+1+1+4=9.
 
 */