//
//  main.cpp
//  q2
//
//  Created by Siddhant Jain on 2016-03-08.
//  Copyright © 2016 Siddhant Jain. All rights reserved.
//

/*#include <iostream>
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
pii z;

int reach = 0;
map<pii, int> where;
vector<pii> dp;
map<pii, int> wgoto;
int abc = 0;

int camef = 0;
int best(int node, int comefrom){
    //cout << node << ":";
    if (node == reach) {
        camef = comefrom;
        return 1;
    }
    pii p;
    p.first = node;
    p.second = comefrom;
    int index = where[p];
    
    if (dp[node] !=z) {
        if (comefrom == dp[node].second) {
            abc = dp[node].first;
            return 0;//be sure to check in for loop
        }
        if (wgoto[dp[node]] != comefrom) {
            p.second = dp[node].second;
            index = where[p];
            if (index == 0) {
                int val = best(board[node][board[node].size()-1], node)+1;
                return val+dp[node].first;
            }
            else {
                return best(board[node][index-1], node)+1+ dp[node].first;
            }
        }
        //cout << node << " " << comefrom << endl;
    }
    if (index == 0) {
        int val = best(board[node][board[node].size()-1], node)+1;
        return val;
    }
    return best(board[node][index-1], node)+1;
}

int main(void)
{
    input;
    int num;
    cin >> num;
    board = vcc(num+1);
    z.first = -1;
    z.second= -1;
    
    dp = vector<pii>(num+1, z);
    
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            int a;
            cin >> a;
            board[i].push_back(a);
            pii p;
            p.first = i;
            p.second = a;
            int kk = board[i].size()-1;
            where[p] = kk;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int cq;
        cin >> cq;
        if (dp[cq] != z) {
            cout << dp[cq].first << endl;
            continue;
        }
        
        int maxi = 0;
        for (int i =0; i < board[cq].size(); i++) {
            
            reach = cq;
            int val = best(board[cq][i], cq);
            if (abc != 0) {
                val = abc-val;
                abc = 0;
            }
            maxi = max(maxi , val);
            
            pii o;
            o.first = val;
            o.second = camef;
            
            wgoto[o] = board[cq][i];
            dp[cq] = o;
            
            //cout << endl;
        }
        cout << maxi << endl;
    }
}
*/

//
//  main.cpp
//  q2
//
//  Created by Siddhant Jain on 2016-03-08.
//  Copyright Â© 2016 Siddhant Jain. All rights reserved.
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

int reach = 0;
map<pii, int> where;

int best(int node, int comefrom){
    //cout << node << ":";
    if (node == reach) {
        return 1;
    }
    pii p;
    p.first = node;
    p.second = comefrom;
    int index = where[p];
    if (index == 0) {
        return best(board[node][board[node].size()-1], node)+1;
    }
    return best(board[node][index-1], node)+1;
}

int main(void)
{
    input;
    int num;
    cin >> num;
    board = vcc(num+1);
    vc done;
    done = vc(num+1, -1);
    for (int i = 1; i <= num; i++) {
        int temp;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            int a;
            cin >> a;
            board[i].push_back(a);
            pii p;
            p.first = i;
            p.second = a;
            int kk = board[i].size()-1;
            where[p] = kk;
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int cq;
        cin >> cq;
        if (done[cq] != -1) {
            cout << done[cq] << endl;
            continue;
        }
        int maxi = 0;
        for (int i =0; i < board[cq].size(); i++) {
            reach = cq;
            maxi = max(maxi , best(board[cq][i], cq));
            if (done[cq] != -1) {
                done[cq] = maxi;
            }
            //cout << endl;
        }
        cout << maxi << endl;
    }
}
