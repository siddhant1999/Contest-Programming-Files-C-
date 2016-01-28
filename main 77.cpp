//
//  main.cpp
//  Contest Creation
//
//  Created by Siddhant Jain on 2016-01-16.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;
vc x, y;

int main(void)
{
    //input;
    //ifstream in("test.txt");
    //freopen("out.txt", "w", stdout);
    
    int num;
    cin >> num;
    
    for (int z = 1; z <= num; z++) {
        int n;
        cin >> n;
        
        int prev;
        cin >> prev;
        int remain = 3;
        int tot= 0;
       
        for (int i = 1; i<n; i++) {
            int cur;
            cin >> cur;
            if (remain == 0) {
                prev = cur;
                remain = 3;
                continue;
            }
            if (cur <= prev) {//add all remaining
                tot+= remain;
                remain = 3;
            }
            else if ((cur-10) <= prev) {//no need to add
                remain--;
            }
            else if (((cur-prev)-1)/10+1 < remain) {
                remain-= (1+(cur-prev-1)/10)+1;
                tot += ((cur-prev)-1)/10+1;
            }
            else {
                tot += remain;
                remain =3;
            }
            prev = cur;
        }
        cout << "Case #" << z << ": " << tot+remain << endl;
    }
}