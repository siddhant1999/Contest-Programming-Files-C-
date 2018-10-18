//
//  main.cpp
//  Pinball Rankings
//
//  Created by Siddhant Jain on 2016-02-03.
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

int binary(int low, int high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (list[mid] == k ) return mid;//
        if (low==high) return low;
        if ( list[mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}//upper bound

int main(void)
{
    input;
    int num;
    cin >> num;
    //list = {1,7,9,12,14};
    //list.insert(list.begin()+2, 33);
    
    //cout << binary(0, list.size()-1, 1);
    // you have to check the border cases
    //sice with repeats it will give the smallest index of the occurance we may need to add a map to store the max index of the val
    double sum = 0;
    int temp;
    cin >> temp;
    list.push_back(temp);
    sum += 1;
    for (int i = 0; i < num-1; i++) {
        cin >> temp;
        int index = binary(0, int(list.size()-1), temp);
        cout << temp << ',' << index << endl;
        if (index == 0) {
            if (temp > list[0]) {
                index++;
            }
        }
        else if (index==list.size()-1) {
            if (temp > list[index]) {
                index++;
            }
        }
        list.insert(list.begin()+index, temp);
        sum += list.size()-index;
    }
    
    fori(list.size()){
        cout << list[i] << ',';
    }
    printf( "%.2f\n", sum/num );
    
    //1,2,3,4,3,6
}