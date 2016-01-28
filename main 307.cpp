//
//  main.cpp
//  Cookies
//
//  Created by Siddhant Jain on 2/17/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <set>
#include <map>
using namespace std;

vector<int> xcord;
vector<int> ycord;

// a > b ==== a^2 > b^2

double maxDist( double x, double y ){
    double ans=0.0;
    
    for (int i = 0; i < xcord.size(); i++) {
        
        double xdelta = xcord[i] - x;
        double ydelta = ycord[i] - y;
        double dist = xdelta * xdelta + ydelta * ydelta;
        
        ans=max( ans, dist );
    }
    
    return ans;
}

int main(void)
{
    double left=1000.0, right=0.0, top=1000.0, bottom=0.0;
    
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        xcord.push_back(x);
        ycord.push_back(y);
        
        left=min( left, double(x) );
        right=max( right, double(x) );
        top=min( top, double(y) );
        bottom=max( bottom, double(y) );
    }
    double minimum = 9999999;
    double x, y;
    //int tmp=0;
    for ( x=left; x<=right; x+=0.01 ){
        for ( y=top; y<=bottom; y+=0.01 ){
            minimum = min(minimum, maxDist(x, y));
            //tmp++;
            //if ( tmp%50000==0 )
                //printf( "best so far = %lf\n", sqrt(minimum) );
        }
    }
    minimum = sqrt(minimum) * 2;
    printf( "%.2lf", minimum );
    //cout << minimum;
}