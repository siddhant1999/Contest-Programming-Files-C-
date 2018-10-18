//
//  main.cpp
//  RNA Sequence
//
//  Created by Siddhant Jain on 2016-03-12.
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
vcc board, where;
map<char, int> lookup;
map<char, char> pairto;
string rna;

vcc unused;

pii randomchoose(int left, int right){//inclusive
    int r_node = rand() % (right-left+1) + left;
    //Figure out the number of pairable sites to the left and to the right of this char
    char pairable = pairto[rna[r_node]];
    
    //int before = board[lookup[pairable]][r_node];
    //int after = board[lookup[pairable]][rna.length()-1] - board[lookup[pairable]][r_node];
    
    int totnum = board[lookup[pairable]][rna.length()-1];
    
    int canpairto = rand()%totnum;
    int second_link = where[lookup[pairable]][canpairto];
    pii q;
    q.first = r_node;
    q.second = second_link;
    return q;
    
}

int main(void)
{
    input;
    
    cin >> rna;
    //A -> U
    //C -> G
    
    //A = 0
    //U = 1
    //C = 2
    //G = 3
    
    lookup['A'] = 0;
    lookup['U'] = 1;
    lookup['C'] = 2;
    lookup['G'] = 3;
    
    pairto['A']='U';
    pairto['U']='A';
    pairto['C']='G';
    pairto['G']='C';
    
    //creating list of unused nodes
    vc list;
    for (int i = 0; i < 500; i++) {
        list.push_back(i);
    }
    for (int i =0;i<500; i++) {
        unused.push_back(list);
    }
    
    
    
    where = vcc(4);
    
    board = vcc(4, vc(rna.length(), 0));
    board[lookup[rna[0]]][0] = 1;
    where[lookup[rna[0]]].push_back(0);
    
    vector<pii> firstgen;
    
          
    for(int i = 1; i < rna.length(); i++){
        board[lookup[rna[i]]][i] = board[lookup[rna[i]]][i-1] +1;
        where[lookup[rna[i]]].push_back(i);
    }
    
    for (int i = 0; i< 500; i++) {
        pii p =randomchoose(0, rna.length()-1);
        firstgen.push_back(p);
    }
    
}

