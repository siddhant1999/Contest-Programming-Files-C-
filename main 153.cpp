/*
 ID: siddhan9
 PROG: gift1
 LANG: C++
 */
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

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef long long big_int;
typedef vector<int> vc;
typedef vector<vector<int> > vcc;
typedef priority_queue<int> pq;
vc board;
//vc list;
int MAX = 999999999;

int main(void)
{
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    int num;
    fin >> num;
    vector<int> list;
    vector<string> si;
    map<string, int> look;
    for (int i = 0; i < num; i++) {
        string temp;
        fin >> temp;
        look[temp] = i;
        list.push_back(0);
        si.push_back(temp);
    }
    for (int i = 0; i < num; i++) {
        string temp;
        fin >> temp;
        int a, b;
        fin >> a >> b;
        int c = look[temp];
        
        if (b != 0) {
            list[c] += a%b;
            list[c] -= a;
        }
        
        for (int j = 0; j < b; j++) {
            string s;
            fin >> s;
            list[look[s]] += (a/b);
        }
    }
    for (int i = 0; i < si.size(); i++) {
        fout << si[i] << ' ' << list[i] << endl;
    }
}



