#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <fstream>
#include <set>
#include <map>
#include <bitset>
#include <iomanip>
#include <ctime>

using namespace std;

typedef vector<long long> vc;
typedef long long ll;
long long counter = 0;
vector<pair<long long, long long> > x;
long long n, m;


int interPoint (int r1, int c1, int r2, int c2){
    return (c2-c1) + r1;
}
ll comparea (int row){
    if(row > n) return 0;
    int diff = n-row+1;
    return (diff+1)*diff/2;
}

int main(){
    //freopen("text.txt", "r", stdin);
    cin >> n >> m;
    
    for(long long i =0; i < m; i++){
        
        long long a, b;
        cin >> a >> b;
        pair<long long , long long> q;
        q.first = a;
        q.second = b;
        x.push_back(q);
    }
    sort(x.begin(), x.end());
    int area = comparea(x[0].first);
    for(long long i = 1; i < x.size();i++){
        //starting with leftmost
        int r1 = x[i-1].first;
        int c1 = x[i-1].second;
        int r2 = x[i].first;
        int c2 = x[i].second;
        int newrow = interPoint(r1,c1,r2,c2);
        if(newrow <= r2){
            continue;
        }
        area -= comparea(newrow);
        area += comparea(r2);
        //cout << area << "*" << endl;
    }
    cout << area;
    /*for (long long i = 0; i < board.size(); i++) {
     for (long long j = 0; j < board[i].size(); j++) {
     cout << board[i][j] << ' ';
     }cout << endl;
     }*/
    
}