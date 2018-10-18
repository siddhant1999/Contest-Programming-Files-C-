//
//  main.cpp
//  Cheesecake
//
//  Created by Siddhant Jain on 2015-12-08.
//  Copyright © 2015 Siddhant Jain. All rights reserved.
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
#define fori(lim) for(long long (i) = (0); (i) < (lim);(i)++ )
#define forj(lim) for(long long (j) = (0); (j) < (lim);(j)++ )
#define fork(lim) for(long long (k) = (0); (k) < (lim);(k)++ )

typedef pair<long long, long long> pii;
typedef pair<long long, pair<long long, long long> > piii;
typedef vector<long long> vc;
typedef vector<vector<long long> > vcc;
typedef priority_queue<long long> pq;

long long MAX = 2147483647;
vcc board;
vc list, cake;

int main(void)
{
    pq x;
    x.push(6);
    x.push(8);
    x.pop();
    cout << x.top();
    long long num;
    cin >> num;
    
    long long mxi = 0, sum =0;
    for (long long i = 0; i < num; i++) {
        long long temp;
        cin >> temp;
        list.push_back(temp);
        if (temp > mxi) {
            mxi = temp;
        }
        sum += temp;
    }
    if (sum %num) {
        cout << "Impossible";
        return 0;
    }
    long long done = sum/num;//index quotient should equal the sum
    
    cake = vc(mxi+1, 0);
    
    for (long long i = 0; i < list.size(); i++) {
        cake[list[i]]++;
    }
    long long count = 0;
        for (long long i = mxi; i > 0; i--) {
            //cout << i<< endl;
            if (cake[done] == num) {
                break;
            }
            count++;
            if (count > 999999) {
                cout << "Impossible" << endl;
                return 0;
            }
            if (cake[i]>0) {
                cake[i]--;
                cake[i-1]++;
                for (long long j = 0; j < i; j++) {
                    if (cake[j] > 0) {
                        cake[j]--;
                        cake[j+1]++;
                        break;
                    }
                }
                if (cake[i] > 0) {
                    i++;
                }
            }
            
        }cout << count;
}