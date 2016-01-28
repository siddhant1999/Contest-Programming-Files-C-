//
//  main.cpp
//  Floor Plan
//
//  Created by Siddhant Jain on 2/17/2014.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

vector<vector<char> > floor(26, vector<char>(26, 0));
vector<vector<int> > label(26, vector<int>(26, 0));
vector<int> area( 800, 0 );
vector<int > rooms;
int totalarea = 0;
map<int, int> values;
// floor fill on 2d board
void visit( int row, int col, int curLabel ){
    if ( floor[row][col]=='I' ) return;
    //cout << row << " " << col << " " << curLabel << endl;
    if ( label[row][col] > 0 )
        return;
    label[row][col]=curLabel;
    rooms[curLabel]++;
    area[curLabel]++;
    
    
    visit( row+1, col, curLabel );
    visit( row-1, col, curLabel );
    visit( row, col-1, curLabel );
    visit( row, col+1, curLabel );
}

int main(void)
{
    int hardwood, rows, columns;
    cin >> hardwood >> rows >> columns;
    char temp;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j<= columns; j++) {
            cin >>temp;
            floor[i][j] = temp;
            if (temp == '.') {
                totalarea++;
            }
        }
    }
    
    
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j<= columns; j++)
            cout << floor[i][j];
        cout << endl;
    }
    int numRooms=0;
    rooms.push_back(0);
    for (int i = 1; i <= rows; i++)
        for (int j = 1; j<= columns; j++)
            if ( label[i][j] == 0 )
                if ( floor[i][j]=='.' ){
                    numRooms++;
                    rooms.push_back(0);
                    cout << "i: " << i <<" j: " << j << " numrooms: " << numRooms << endl;
                    visit( i, j, numRooms );
                }
    
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j<= columns; j++)
            cout << label[i][j];
        cout << endl;
    }
    cout << numRooms;
    cout << " " << totalarea;
    cout << endl << endl;
    sort(rooms.begin(), rooms.end());
    int count=0;
    for (long i =rooms.size() - 1; i>=0; i--) {
        //cout << "i: " << i << " value: " << rooms[i] << endl;
        if ((hardwood-rooms[i]) >= 0) {
            hardwood -= rooms[i];
            count++;
            //cout << "hard: " << hardwood << " " << count << endl;
        }
        else {
            cout << count << " rooms, " << hardwood << " square metre(s) left over";
            break;
        }
    }
}
