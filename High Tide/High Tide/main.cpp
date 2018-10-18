//
//  main.cpp
//  High Tide
//
//  Created by Siddhant Jain on 2016-01-28.
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



double lcm(double a, double b){
    //if (int(a) == a && int(b) == b) {
     /*
    cout << a << " " << b << endl;
    for (int i = 1; i <b; i++) {
        if (fmod((a*i),b) == 0) {
            return i*a;
        }
    }*/
    //}
    return a*b;
}

double cross(int a, int b){
    double t = double(b)/double((b-a));
    return t*a;
    
    
    
}
double vel[1000]; // the velocity of each moon in degrees per day.
int n;
double limit;

#define abs(x) ( (x)<(0)?(-(x)):(x) )

void find_align( void ){
    
    int i,j;
    double k;
    
    // brute force:
    // check if the moons align at every possible day ( or 0.0001 of a day )
    for ( k=1.0; k<100000.0; k+=0.0001 ){
        double p=fmod( vel[0]*k, 360.0 ); // find where the first moon is located
        
        // now compare if the first moon is lined up with every other moon
        for ( j=1; j<n; j++ )
            if ( abs( fmod( vel[j]*k,360.0 )-p )>0.01 )
                break;
        
        // they lined up, so print and return.
        if ( j==n ){
            printf( "martin=%.2f\n", k );
            return;
        }
        
    }
    
}

int main(void)
{
    input;
    int num;
    cin >> num;
    n= num;
    double cur =1, pre = 1;
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        if (i>0) {
            cur = cross(min(temp,list[list.size()-1]), max(temp,list[list.size()-1]));
            pre = lcm(cur, pre);
        }
        list.push_back(temp);
        vel[i]=360.0/(double)(temp);
    }
    cout << setprecision(2) << fixed <<  pre << endl;
    find_align();
}




