//
//  main.cpp
//  Counting Subsequences
//
//  Created by Siddhant Jain on 2015-11-12.
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

long long MAX = 1000000000;
vcc board;
vc sum;
vector<int> charoc (26, -1);
string str;

void dp(int x){
    if (charoc[str[x]-'a'] == -1) {
        sum[x] = (sum[x-1]*2)%10007;
    }
    else {
        int a = charoc[str[x]-'a'];
        sum[x] = ((sum[x-1]*2)%10007 - sum[a-1] + 10007)%10007;
        sum[x] %= 10007;
        
    }
    charoc[str[x]-'a'] = x;
}

int main(void)
{
    
    cin >> str;
    str = " " + str;
    //cout << str;
    sum = vc(str.length()+1, 0);
    sum[0] = 1;
    //cout << str[1-1]-'a' << endl;
    for(int i = 1; i < str.length(); i++)
        dp(i);//one index
    
    cout << (sum[str.length()-1] - 1)%10007;
}
/*
 
 ways(1) = {NULL, a}
 ways(2) = {a,b,ab,NULL}
 ways(3) = {a,b,ab,NULL,    aa,ba,aba}
 
 ways(n-1)
 w[1]
 w[2]
 w[3]
 ...
 w[t]
 
 
 w[1]+'a'
 w[2]+'a'
 w[3]+'a'
 ...
 w[t]+'a'
 
 
 
 if cur letter hasn't happened:
 ways(k)=2*way(k-1)
 
 xyzaba    c bc
 
 
 
 this problem requires a clever recurrence relation, think about special cases:
 -if all letters are different, then the answer has to be 2^N - 1  (N is the length of the whole string)
 -if a certain letter repeats, then how do we properly count the # of subseqs ?
 
 let ways(n) be the number of subseqs of the the first n letters only, now analyze 2 possible cases:
 -the n'th letter hasn't occurred before in the string
 -the n'th letter occurred already (ie. repeated at least once)
 
 how can we define ways(n) in terms of ways(n-1) and other ways(k) where k<n ?
 */