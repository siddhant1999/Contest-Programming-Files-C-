//
//  main.cpp
//  Neural Network
//
//  Created by Siddhant Jain on 2016-11-13.
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
vcc board;
vc list;
vector<vector<pair<double, vector<double> > > > net;
//this represents the 2D structure of neurons
//each neuron has a value and edge weights to every neuron in the next row

int main(void)
{
    input;
    int num;//layers to the net
    cin >> num;
    fori(num){
        int nLayer;
        cin >> nLayer;
        list.push_back(nLayer);
    }
    forj(net.size()-1){
       
        vector<pair<double, vector<double> > > layer;
        layer = vector<pair<double, vector<double> > > (list[j], pair<double, vector<double> > {NULL, vector<double> (net[j+1].size())});
    }
    vector<pair<double, double> > layer (nLayer+1);//1 bias neuron
    net.push_back(layer);
    fori(net[0].size()){
        int neuronval;
        cin >> neuronval;
        
    }
    
    
}
