//
//  main.cpp
//  2017s3
//
//  Created by Siddhant Jain on 2017-02-22.
//  Copyright © 2017 Siddhant Jain. All rights reserved.
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


#define f0 first
#define s0 second
#define sf0 second.first
#define ss0 second.second

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
#define input ios::sync_with_stdio(false)
typedef pair<long long, long long> pii;
typedef pair<long long, pair<long long, long long> > piii;
typedef vector<long long> vc;
typedef vector<vector<long long> > vcc;
typedef priority_queue<long long> pq;

long long MAX = 1147483647;
vcc board;
vc list;
vc isthere;

long long makethis(long long n){
    vector<int> q;
    long long count= 0;
    cout << n;
    for (long long i = 0; i < 2001; i++) {
        if (n-i > 2000 || n-i < 0) {
            continue;
        }
        if (isthere[i] && isthere[n-i]) {
            q.push_back(i);
            q.push_back(n-i);
            isthere[i]--;
            isthere[n-i]--;
            i--;
            count++;
        }
    }
    fori(q.size()){
        isthere[q[i]]++;
    }
    return count;
}

/*long long makethis(long long n, vector<long long> myq){
    long long count= 0;
        for (long long i = 0; i < myq.size() && myq.size(); i++) {
            long long o = n-myq[i];
            vector<long long>::iterator low;
            low=lower_bound (myq.begin(), myq.end(), o);
            
            if (double(clock())/CLOCKS_PER_SEC > 1.9) {
                return count;
            }
            if (myq[(low-myq.begin())] == o && low-myq.begin() != i) {
                myq.erase(max(low, myq.begin()+i));
                myq.erase(min(low, myq.begin()+i));
                //cout << "got it" << endl;
                if (i > low-myq.begin()) {
                    i = low-myq.begin();
                }
                count++;
            }
        }
    return count;
}*/


int main(void)
{
    input;
    long long num;
    cin >> num;
    
    isthere = vc (2000, 0);
    for (long long i = 0; i < num; i++) {
        long long temp;
        cin >> temp;
        isthere[temp]++;
    }
    
    cout << "fdsfds";
    long long maci= -1;
    long long cou = 0;
    
    for (long long i = 2; i <= 4000; i++) {
        cout << i;
        long long abc = makethis(i);
        /*if (abc) {
            cout << i << endl;
        }*/
        
        if (abc > maci) {
            maci = abc;
            cou = 1;
        }
        else if (abc == maci) {
            cou++;
        }
       /* if (double(clock())/CLOCKS_PER_SEC > 1.9) {break;
        }*/
    }
    
    cout << maci << " " << cou;
    
}
