//
//  main.cpp
//  Contagion
//
//  Created by Siddhant Jain on 2015-12-09.
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
typedef priority_queue<pii> pq;

long long MAX = 8223372036854775807;
vcc board;
vc list, x, y, dist;
vector<bool> visit;
long long vcount =1;
pq tovis;
map<long long, long long> indexing;

long long binary(long long low, long long high, long long k)
{
    long long mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if ( dist[mid] <= k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

void dij(long long node){
    
    for (long long i = 0; i < x.size(); i++) {
        if (node == i) continue;
        
        dist[i] = min(dist[i], dist[node] + board[node][i]);
    }
    visit[node] = true;
    vcount++;
}

int main(void)
{
    /*list.push_back(0);
    list.push_back(5);
    list.push_back(8);
    list.push_back(10);*/
    //cout << binary(0, 3, 7);
    //itterate over both sides of that number to determine max
    
    long long nodes;
    cin >> nodes;
    board = vcc (nodes, vc (nodes, MAX));
    for (long long i = 0; i < nodes; i++) {
        long long a, b;
        scanf("%lld%lld", &a, &b);
        x.push_back(a);
        y.push_back(b);
    }
    long long site;
    cin >> site;
    site--;
    
    for (long long i = 0; i < x.size(); i++) {
        for (long long j = 0; j < x.size(); j++) {
            if (i==j) continue;
            if (board[i][j] != MAX) continue;
            long long d = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            board[i][j] = d;
            board[j][i] = d;
        }
    }
    
    
    dist = vc (nodes, MAX);//shortest dists
    visit = vector<bool> (nodes, false);
    dist[site] = 0;
    
    
    
    while(true){
        if (vcount >= visit.size()) {
            break;
        }
    long long minimize = MAX;
    long long min_index = 0;
        
    for (long long i = 0; i < dist.size(); i++) {
        if (dist[i] < minimize && !visit[i]) {
            minimize = dist[i];
            min_index = i;
        }
    }
    
    dij(min_index);
    }
    
    sort(dist.begin(), dist.end());
    
    
    
    //binary search
    long long q;
    scanf("%lld", &q);
    while(q--){
        long long qu;
        scanf("%lld", &qu);
        long long x = binary(0, dist.size()-1, qu);//index
        //cout << qu << " " << p << " **" << endl;
        
        printf("%lld\n", x);
    }
    
}