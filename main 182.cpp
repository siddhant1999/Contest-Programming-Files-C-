//
//  main.cpp
//  s2
//
//  Created by Siddhant Jain on 2015-02-11.
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

map<char, char> board;
int main(void)
{
    int num;
    cin >> num;
    while (num--) {
        char a, b;
        cin >> a;
        cin >> b;
        board[a] = b;
        board[b] = a;
        //cout << a << "is mapped to: " << b <<endl;
    }
    int n;
    cin >> n;
    while (n--) {
        string a, b;
        cin >> a;
        cin >> b;
        int t = 0;
        for (int i= 0; i < a.length(); i++) {
            if (board[a[i]] == b[i]) {
                t++;
            }
            else break;
        }
        if (t == a.length()) {
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}
