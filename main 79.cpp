//
//  main.cpp
//  Triangle Sums
//
//  Created by Siddhant Jain on 2014-07-27.
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

int tri[101][101];
int cache[101][101];
int n;

int maxsum( int row, int col ){
    if ( row==n )
       return tri[row][col];
    
    if (cache[row][col] != -1)
        return cache[row][col];
    
    int x = maxsum(row+1, col);
    int y = maxsum(row +1, col + 1);
    
    int ans=max( x,y );
    return cache[row][col]= tri[row][col]+ ans;
    
}

int main(void)
{
    
    cin >> n;
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j<=i; j++){
            cache[i][j]=-1;
            cin >> tri[i][j];
        }
    
    cout << maxsum(1,1);
    
}

/*
n= 5
 7   <-- row 1
 3 8    row 2
 8 1 0
 2 7 4 4
 4 5 2 6 5    row 5
*/