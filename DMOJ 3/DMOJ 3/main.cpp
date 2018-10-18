//
//  main.cpp
//  DMOJ 3
//
//  Created by Siddhant Jain on 2016-01-12.
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
#define input ios::sync_with_stdio(false);
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;

int MAX = 1147483647;
vcc board;
vc list;

int dp(int val) {
    //cout << val << "^^^"<< endl;
    if (val <= 0) {
        return val;
    }
    int curmin = -MAX;
    int mini = -MAX;
    
    fori(list.size()){
        //cout << list[i] << "**********" << endl;
        if(list[i] == MAX){
            continue;
        }
        if (list[i]>= val) {
            curmin = val - list[i];
            //cout << list[i] << " " << val << endl;
            break;
        }
        int o =list[i];
        list[i] = MAX;
        mini =max(mini, dp(val-o));
        if (mini == 0) {
            return 0;
        }
        list[i] = o;
    }
    return max(curmin, mini);
}

int main(void)
{
    input;
    int num;
    cin >> num;
    
    
    while(num--) {
        list.clear();
        int temp;
        cin >> temp;
        int maxi = 0;
        int sum = 0;
        
        fori(temp){
            int x;
            cin >> x;
            maxi = max(maxi, x);
            sum+= x;
            list.push_back(x);
        }
        sort(list.begin(), list.end());
        int a, b;
        cin >> a >> b;
        if (sum < b || sum < (a+b)) {
            cout << "NOT LETHAL" << endl;
            continue;
        }
        int kkk =dp(b);
        //cout << kkk;
        sum -= b-kkk;
        if (sum >= a) {
            cout << "LETHAL" << endl;
        }
        else cout << "NOT LETHAL" << endl;
        /*int cur = 0;
        for (unsigned long i =list.size()-1; i >=0; i--) {
            int minim = -MAX;
            for (int j = 0; j < list.size(); j++) {
                minim = max(minim, b-list[i]);
            }
            if (minim <= 0 && minim!= -MAX) {
                cur= cur+b+minim;
                b=0;
                break;
            }
            cur += list[i];
            b-= list[i];
            
            if (b <= 0) {
                break;
            }
        }
        if (b>0) {
            cout << "NOT LETHAL" << endl;
            continue;
        }
        sum-= cur;
        if (sum >= a) {
            cout << "LETHAL" << endl;
        }else cout << "NOT LETHAL" << endl;*/
    }
}