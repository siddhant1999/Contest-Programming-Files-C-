/*
ID: siddhan9
PROG: ride
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
vcc board;
vc list;
int MAX = 999999999;

int main(void)
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string str1, str2;
    fin >> str1 >> str2;
    
    int sum = 1;
    int xum = 1;
    for (int i = 0; i < str1.length(); i++) {
        char temp;
        temp = str1[i];
        int x = temp - 'A';
        x++;
        sum *= x;
        
        
    }
    for (int i = 0; i < str2.length(); i++) {
        char t = str2[i];
        int y = t- 'A';
        y++;
        xum *= y;
    }
    if (xum%47 == sum%47) {
        fout << "GO";
    }else fout << "STAY";
}
