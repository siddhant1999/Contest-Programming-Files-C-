//
//  main.cpp
//  Packet Routing
//
//  Created by Siddhant Jain on 2014-11-08.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
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

int dist[101][101];

int main( void ){
    in=fopen( "packet.in", "r" );
    out=fopen( "packet.out", "w" );
    out=stdout;
    int n,w,p;
    fscanf( in, "%d %d %d", &n, &w, &p );
    
    int i,j,k,a,b,d;
    
    for ( i=0; i<=n; dist[i][i]=0,i++ )
        for ( j=i+1; j<=n; j++ )
            dist[i][j]=dist[j][i]=1000000000;
    
    for ( i=0; i<w; i++ ){
        fscanf( in, "%d %d %d", &a, &b, &d );
        dist[a][b]=dist[b][a]=d;
    }
    
    for ( k=1; k<=n; k++ )
        for ( i=1; i<=n; i++ )
            for ( j=1; j<=n; j++ )
                dist[i][j]=min( dist[i][j], dist[i][k]+dist[k][j] );
    
    for ( i=0; i<p; i++ ){
        fscanf( in, "%d %d", &a, &b );
        fprintf( out, "from %d to %d is %d\n", a,b,dist[a][b] );
    }
    
}/*
int curcheck;
vector<vector <int > > network(101);
int mass[101][101] = {0};

int dfs(int curnum, int prevnum, int weight){
    if (curnum == curcheck)
        return weight;
    
    for (int i = 0; i < network[curnum].size(); i++)
        if (network[curnum][i] != prevnum) {
            int var = dfs(network[curnum][i], curnum, weight + mass[curnum][network[curnum][i]]);
            if (var > 0)return var;
        }
    
    return 0;
}
int main(void)
{
    int num, wires, tests;
    cin >> num >> wires >> tests;
    
    while (wires--) {
        int x,y,w;
        cin >> x >> y >> w;
        mass[x][y] = w;//edge weight
        mass[y][x] = w;
        network[x].push_back(y);
        network[y].push_back(x);
    }
    while (tests--) {
        int x, y;
        cin >> x >> y;
        curcheck = y;
        cout << dfs(x, x, 0) << endl;
    }
}*/

