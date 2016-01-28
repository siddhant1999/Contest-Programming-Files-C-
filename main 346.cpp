//
//  main.cpp
//  Binary Practice
//
//  Created by Siddhant Jain on 2015-02-17.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;

vc board;

int binary(int low, int high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (board[mid] == k ) return mid;//
        if (low==high) return low;
        if ( board[mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}//upper bound
int main(void)
{
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        board.push_back(temp);
    }
    sort(board.begin(), board.end());
    cout << binary(0, (int) board.size()-1, 17);
}
