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

vector<int> primes;

bool isprime(int n){
    if (n == 3)
        return true;
    if (n < 3)
        return false;
    if (primes.size() > 0) {
        for (int i = 0; primes[i] <= n; i++) {
            if (n == primes[i])
                return true;
        }
    }
    int coun = 0;
    if (n%2 == 0) {
        return false;
    }
    for (int j = 3; j < n; j+= 2) {
        if (n%j == 0) {
            coun++;
            return false;
        }
        
    }
    if (coun == 0){
        primes.push_back(n);
        return true;
    }
    else
        return false;
}

vector<int> subseq(vector<int> seq){
    for (int i = 2; i <= seq.size(); i++) {
        for (int j = 0; j <= (seq.size() - i); j++) {
            int end = j + i - 1;
            int tempsum = 0;
            vector<int> finalsubseq;
            for (int k = j; k <= end; k++) {
                //cout << seq[k] << " ";
                tempsum += seq[k];
                finalsubseq.push_back(seq[k]);
            }
            //cout << endl << endl << tempsum<< endl << endl;
            if (isprime(tempsum) == true) {
                //cout << "got a prime ";
                return finalsubseq;
                break;
            }
        }
    }
    vector<int> anti;
    return anti;
}

void precompute(int sum){
    if (primes.empty()){
        primes.push_back(3);
        cout << '3' << endl;
    }
    
    for (int i = primes[primes.size() - 1] + 2; i <= sum; i+=2) {
        int counter = 0;
        for (int j = 0; j < primes.size(); j++) {
            if (i%primes[j] == 0 && i != primes[j]) {
                counter++;
                break;
            }
        }
        if (counter == 0) {
            primes.push_back(i);
            cout << i << endl;
        }
    }
}


int main(void)
{
    precompute(100000000);
    int cases;
    cin >> cases;
    //cout << cases;
    while (cases--) {
        vector<int> sequence;
        int num;
        cin >> num;
        //int totalsum = 0;
        //cout << " " << num;
        while (num--) {
            int temp;
            cin >> temp;
            //cout << ":" << temp;
            sequence.push_back(temp);
            //totalsum += temp;
        }
        //vector<int> primes;
        //precompute(totalsum);
        vector<int> myvec = subseq(sequence);
        if (myvec.size() == 0)
            cout << "This sequence is anti-primed.";
        else
            cout << "Shortest primed subsequence is length " << myvec.size() << ':';
            for (int i = 0; i < myvec.size(); i++) {
                cout << " " << myvec[i];
            }
        cout << endl;
    }
}

