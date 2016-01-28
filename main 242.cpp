//
//  main.cpp
//  Primed Sequence
//
//  Created by Siddhant Jain on 2014-10-21.
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

vector<int> sequence;
vector<int> sums;

vector<bool> ifprime (100000001, true);
//vector<vector<bool>> cache(10001, vector<bool>(10001,-1));

int done = 0;
int sumof(int i, int j){
    if(i > 0){
        return (sums[j] - sums[i - 1]);
    }
    else
        return sums[j];
}

/* 0  1  2  3  4  5  6 <-index
   5  6  2  3  9  5  1 <-nums
   5 11 13 16 25 30 31 <-sums
*/
bool isprime(int x)
{
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x;i+= 2)
        if (x % i == 0)
            return false;
    return true;
}

void subseq(){
    for (int i = 2; i <= sequence.size(); i++) {//length
        for (int j = 0; j <= (sequence.size() - i); j++) {
            int end = j + i - 1;
            // j = i
            // end = j
            //done++;
            int tempsum = sumof(j, end);
            //cout << endl << endl << tempsum<< endl << endl;
            //if (isprime(tempsum) == true) {
            if (ifprime[tempsum] == true && tempsum %2 != 0) {
                //cout << "got a prime " << tempsum << endl;
                cout << "Shortest primed subsequence is length " << i << ':';
                for (int i = j; i <= end; i++) {
                    cout << " " << sequence[i];
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "This sequence is anti-primed.";
}


// sieve
void precompute(int sum){
    
    ifprime[0] = false;
    ifprime[1] = false;
    
    for (int i = 3; i < sum; i+= 2) {
        if (ifprime[i] == true)
            for (int j = 3; j*i <= sum; j+= 2) {
                ifprime[j*i] = false;
        }
    }
    //for (int i = 0; i < 100; i++) {
        //cout << i << ": " << ifprime[i] << endl;
    //}
}


int main(void)
{
    //time_t start = time(0);
    
    //precompute(10000000);
    //cout << ifprime[ifprime.size() - 77];
    //for (int i = 0; i < ifprime.size(); i++) {
     //   cout << i << ": " << ifprime[i] << endl;
    //}
    //double seconds_since_start = difftime( time(0), start);
    //cout << seconds_since_start;
    int cases;
    cin >> cases;
    //cout << cases;
    
    while (cases--) {
        sums.clear();
        sequence.clear();
        
        int cursum = 0;
        //vector<vector<int>> sequence (n, vector<int>(m,-1));
        int num;
        cin >> num;
        int totalsum = 0;
        //cout << " " << num;
        while (num--) {
            int temp;
            cin >> temp;
            //cout << ":" << temp;
            sequence.push_back(temp);
            cursum += temp;
            sums.push_back(cursum);
            //cout << temp << " " << cursum << endl;
            totalsum += temp;
        }
        //vector<int> primes;
        precompute(totalsum);
        //cout << done;
        subseq();
    }
    
}

