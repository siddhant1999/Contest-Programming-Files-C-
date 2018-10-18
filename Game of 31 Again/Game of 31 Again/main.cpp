//
//  main.cpp
//  Game of 31 Again
//
//  Created by Siddhant Jain on 2015-07-23.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1000000000;
vcc board;
vc list;
vc game(38, -1);

bool isWinning(vc done, int tot){
    /*fori(done.size()){
        cout << "i: " << i << " " <<done[i] << endl;
    }*/
    cout << endl << "tot " << tot << endl;
    if (tot == 31) {
        return false;
    }
    if (tot >= 31) {
        return true;
    }
    for (int i = 1; i <= 6 ; i++) {
        if (done[i] < 4) {
            done[i]++;
            if (!isWinning(done, tot+i)) {
                return true;
            }
        }
    }
    return false;
}

int main(void)
{
    int num;
    cin >> num;
    
    fori (num) {
        vc done;
        string temp;
        cin >> temp;
        int sum = 0;
        vc used(7, 0);
        forj(temp.length()) {
            done.push_back(temp[j]-'0');
            sum += temp[j]-'0';
            used[temp[j]-'0']++;
        }
        fori(used.size()){
            cout << "i: " << i << " " <<used[i] << endl;
        }
        cout << endl << endl;
        bool store= isWinning(used, sum);
        if (temp.length()%2 == 0) {
            if (store) {
                cout << "A" << endl;
            }else cout << "B" << endl;
            
        }
        if (temp.length()%2 == 1) {
            if (store) {
                cout << "B" << endl;
            }else cout << "A" << endl;
        }
        //cout << " " << temp.length() << endl;
    }
}









