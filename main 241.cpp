//
//  main.cpp
//  Maximum Distance
//
//  Created by Siddhant Jain on 2014-10-26.
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

vector<int> x;
vector<int> y;

int binary(int low, int high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        //if ( y[mid] == k ) return mid;
        if (low==high) return low;
        if ( y[mid] > k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;

}

int main(void)
{
    int cases;
    cin >> cases;
    
    while (cases--) {
        x.clear();
        y.clear();
        int size1;
        cin >> size1;
        int size2 = size1;
    
        int temp;
    
        while (size1--) {
            cin >> temp;
            x.push_back(temp);
        }
        while (size2--) {
            cin >> temp;
            y.push_back(temp);
        }
    
        int max_dist=0;
        for (int i =0; i < x.size(); i++) {
            int low=i;
            int high=y.size();
            int k=x[i]-1;
        
            int lowest_index=binary( low, high, k );
            int dist=lowest_index-i-1;
            if (lowest_index<i) dist=0;
            max_dist=max( max_dist, dist );
            //cout << "i: " << i << " lowest: " << lowest_index << " dist: " << dist << endl;
        }
    
        cout << "The maximum distance is " << max_dist <<endl;
    }
}







