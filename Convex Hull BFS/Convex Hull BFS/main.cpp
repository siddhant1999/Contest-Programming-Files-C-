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
typedef vector<vector<vector<int> > > vccc;
typedef priority_queue<piii> pq;

int MAX = 1147483647;
map<pii, vector<pii> > board;
vcc paths;
int hull, nodes, routes;
vc cities, times, hulls;
int tr;
int curmini = MAX;
int start, e;

best[2000][200]

void add(int c, int ti, int hu){
    if (hu >= hull) {
        return;
    }
    cities.push_back(c);
    times.push_back(ti);
    hulls.push_back(hu);
    
}

void bfs(int c, int ti, int hu){
    tr++;
    if (tr>1000000) {
        cout << curmini;
        exit(0);
    }
    if (c == e) {
        if (hu < hull) {
            curmini = min(curmini, ti);
        }
        return;
    }
    
    for (int i =0; i < paths[c].size(); i++) {
        int newi = paths[c][i];
        pii q;
        q.first = c;
        q.second = newi;
        if (!board.count(q)) {
            continue;
        }
        for (int j = 0; j < board[q].size(); j++) {
            int ntime = board[q][j].first+ti;
            int ndam = board[q][j].second + hu;
            add(newi, ntime, ndam);
        }
    }
}

int main(void)
{
    input;
    //to optimize we can remove duplicates from paths
    
    cin >> hull >> nodes >> routes;
    paths = vcc(nodes+1);
    
    for (int i = 0; i < routes; i++) {
        int a,b,t,h;
        cin >> a >> b >> t >> h;
        pii q,w;
        q.first = a;
        q.second = b;
        w.first = t;
        w.second = h;
        
        board[q].push_back(w);
        swap(q.first, q.second);
        board[q].push_back(w);
        
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    
    
    cin >> start >> e;
    
    cities.push_back(start);
    times.push_back(0);
    hulls.push_back(0);
    
    pii qw;
    qw.first = MAX;
    qw.second = MAX;
    vector<pii > minimums (nodes+1, qw);
    
    for (int i = 0; i < cities.size(); i++) {
        int qa = cities[i];
        int qb = times[i];
        int qc = hulls[i];
        
        if (qb >= minimums[qa].first && qc >= minimums[qa].second) {
            continue;
        }
        if (qb < minimums[qa].first && qc < minimums[qa].second) {
            minimums[qa].first = qb;
            minimums[qa].second = qc;
        }
        
        bfs(qa, qb, qc);
        
    }
    if (curmini == MAX) {
        cout << -1;
    }
    else cout << curmini;
}