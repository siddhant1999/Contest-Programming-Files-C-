//
//  main.cpp
//  Quicksort without Priority Queue
//
//  Created by Siddhant Jain on 2016-04-12.
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


#define x0 first
#define y0 second.first
#define z0 second.second

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

int pivot;

void part(int left, int right){
    if (left >= right) {
        return;
    }
    if (right-left == 1 && list[right] >= list[left]) {
        return;
    }
    
    int pivval = list[pivot];
    
    int i = left;
    int j = right;
    
    while (i<j) {
        if (list[i] >= pivval && list[j] <= pivval) {
            swap(list[i], list[j]);
            i++;
            j--;
            continue;
        }
    
        if (list[i] <= pivval) {
            i++;
        }
        if (list[j] > pivval) {
            j--;
        }
    }
    pivot = left;
    part(left, i);
    pivot = j;
    part(j, right);
}


int main(void)
{
    input;
    int num;
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    
    pivot = 0;
    part(0, num-1);
    fori(list.size()){
        cout << list[i] << " ";
    }
}