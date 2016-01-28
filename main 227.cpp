//
//  main.cpp
//  Floor Plan Again
//
//  Created by Siddhant Jain on 2014-11-09.
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

vector<vector<char> > floor(26, vector<char>(26, 'I'));
vector<vector<int> > label(26, vector<int>(26, -1));
vector<int > rooms;

map<int, int> values;
// floor fill on 2d board
void visit( int row, int col, char curLabel ){
    if ( floor[row][col]=='I' ) return;
    //cout << row << " " << col << " " << curLabel << endl;
    if ( floor[row][col] != '.')
        return;
    
    floor[row][col]=curLabel;
    rooms[curLabel - '0']++;
    
    
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
        }
    }
    /*for (int i = 0; i <= rows+1; i++) {
        for (int j = 0; j<= columns+1; j++) {
            cout << floor[i][j];
        }
        cout << endl;
    }*/
    char curnum = '0';
    rooms.push_back(0);
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j<= columns; j++) {
            if (floor[i][j] == '.') {
                curnum++;
                rooms.push_back(0);
                visit(i, j, curnum);
            }
        }
    }
    /*cout << endl << endl;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j<= columns; j++) {
            cout << floor[i][j];
        }
        cout << endl;
    }
    */
    //cout << endl << endl;
    sort(rooms.begin(), rooms.end());
    int count=0;
    for (long i =rooms.size() - 1; i>0; i--) {
        //cout << "i: " << i << " value: " << rooms[i] << endl;
        if ((hardwood-rooms[i]) >= 0) {
            hardwood -= rooms[i];
            count++;
            //cout << "hard: " << hardwood << " " << count << endl;
        }
        else
            break;
    }
    if (count == 1) {
        cout << count << " room, " << hardwood << " square metre(s) left over";
    }
    else
        cout << count << " rooms, " << hardwood << " square metre(s) left over";
}

