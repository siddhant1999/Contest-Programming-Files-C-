//
//  main.cpp
//  Power of 3
//
//  Created by Siddhant Jain on 2016-02-09.
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
vc p3;

//generate all 2^19 combos

/*int binary(int low, int high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (p3[mid] == k ) return mid;
        if (low==high) return low;
        if ( p3[mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}//upper bound

*/
int main(void)
{
    p3.push_back(1);
    while (true) {
        p3.push_back(p3[p3.size()-1]*3);
        if (p3[p3.size()-1] > 1000000000) {
            break;
        }
    }
    p3.pop_back();
    
    cout << binary(0, p3.size()-1, 4);
    input;
    int num;
    cin >> num;
    
   
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        for (; a < b; a++) {
            while (true) {
                int x = binary(0, p3.size()-1, a);
            }
        }
    }
}