//
//  main.cpp
//  Tin Can
//
//  Created by Siddhant Jain on 2016-02-05.
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

int main(void)
{
    input;
    double x1, y1, x2, y2, num;
    cin >> x1 >> y1 >> x2 >> y2 >> num;
    double dy = y2-y1;
    double dx = x2-x1;
    double slope = dy/dx;
    double i_int = y2-(slope * x2);
    //cout << slope << " " << i_int;
    int count=0;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        double xi, yi, xfirst, yfirst;
        cin >> xi >> yi;
        bool does = false;
        xfirst = xi, yfirst= yi;
        
        double x,y;
        for (int j= 1; j < temp; j++) {
            //cout << "#" << j << endl;
            
            cin >> x >> y;
            
            if (does) {
                continue;
            }
            
            if (x*slope + i_int == y) {
                count++;
                does=true;
                continue;
            }
            
            if (xi-x == 0) {
                
                double tempy = x*slope + i_int;
                if (tempy <= max(y,yi) && tempy >= min(y,yi)) {
                    count++;
                    does = true;
                }
                xi=x, yi=y;
                continue;
            }
            double tslope;
            if (x > xi) {
                tslope = (yi-y)/(xi-x);
            }
            else {
                tslope = (y-yi)/(x-xi);
            }
            double t_int = yi-(tslope * xi);
            double interX = (t_int - i_int)/(slope-tslope);
            //cout << interX << endl;
            if (interX >= min(x,xi) && interX <= max(x,xi)) {
                count++;
                does = true;
            }
            xi=x,yi=y;
        }
        
        if (xfirst-x == 0 && !does) {
            
            double tempy = x*slope + i_int;
            if (tempy <= max(y,yi) && tempy >= min(y,yi)) {
                count++;
                does = true;
            }
        }
        if (!does) {
            if (xfirst*slope + i_int == yfirst || x*slope + i_int == y) {
                count++;
                does=true;
            }
        }
        if (!does) {
            double tslope;
            if (x > xfirst) {
                tslope = (yfirst-y)/(xfirst-x);
            }
            else {
                tslope = (y-yfirst)/(x-xfirst);
            }
            double t_int = yfirst-(tslope * xfirst);
            double interX = (t_int - i_int)/(slope-tslope);
            //cout << interX << endl;
            if (interX >= min(x,xfirst) && interX <= max(x,xfirst)) {
                count++;
            }
        }
    }
    cout << count;
}