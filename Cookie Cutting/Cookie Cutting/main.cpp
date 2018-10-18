//
//  main.cpp
//  Cookie Cutting
//
//  Created by Siddhant Jain on 2016-02-06.
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

#define MAX 1147483647;

vcc board;
vc x,y;

double maxDist( double a, double b ){
    double ans=0.0;
    
    for (int i = 0; i < x.size(); i++) {
        
        double xdelta = x[i] - a;
        double ydelta = y[i] - b;
        double dist = xdelta * xdelta + ydelta * ydelta;
        
        ans=max( ans, dist );
    }
    
    return ans;
}
int main(void)
{
    input;
    int num;
    cin >> num;
    
    double curx = 0, cury = 0;
    for (int i = 0; i < num; i++) {
        int a, b;
        cin >> a >> b;
        curx += a;
        cury += b;
        x.push_back(a);
        y.push_back(b);
    }
    curx /= num;
    cury /= num;
    
    double jump = 1000;
    while (jump > 0.0001) {
        double curdist = maxDist(curx, cury);
        //cout << curx << " " << cury << " " << curdist << " " << jump << endl;
        double newx = curx, newy = cury;
        if (maxDist(curx + jump, cury) < curdist) {
            newx = curx + jump;
            newy = cury;
            curdist = maxDist(curx + jump, cury);
        }
        if (maxDist(curx - jump, cury) < curdist) {
            newx = curx - jump;
            newy = cury;
            curdist = maxDist(curx - jump, cury);
        }
        if (maxDist(curx, cury + jump) < curdist) {
            newx = curx;
            newy = cury + jump;
            curdist = maxDist(curx, cury + jump);
        }
        if (maxDist(curx, cury - jump) < curdist) {
            newx = curx;
            newy = cury - jump;
            curdist = maxDist(curx, cury - jump);
        }
        
        jump *= 0.9;
        curx= newx;
        cury = newy;
    }
    printf( "%.2f\n", sqrt(maxDist(curx, cury))*2);
    
    //printf( "%.2f\n", sqrt(md) );
}