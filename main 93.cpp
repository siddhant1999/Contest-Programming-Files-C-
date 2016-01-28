//
//  main.cpp
//  Minesweeper
//
//  Created by Siddhant Jain on 12/22/2013.
//  Copyright (c) 2013 Siddhant Jain. All rights reserved.
//

//I will place the various components of the strings received into a 2D array.
//Then check the 8 places around the that part of the array and record the # of *
//result = the number that will be displayed and equal the placement in the array 


#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;
char position[50][50]={0};

char countmines(int i, int j) {
    char result = '0';
    for (int di = -1; di <= 1; di++) {
        for (int dj = -1; dj <= 1; dj++) {
            if(di != 0 || dj != 0){
                int newi = i + di;
                int newj = j + dj;
                if (position[newi][newj] == '*')
                    result++;
            }
        }
    }
    return result;
}

int main(void){
    int rows, columns, k = 0, num;
    char input, nothing;
    vector<char> com;
    
    cin >> rows;
    cin >> columns;
    num = rows * columns;
    nothing = cin.get();
    while (num--)
    {
        cin >> input;
        com.push_back(input);
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            position[i][j] = com[k];
            k++;
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (position[i][j] != '*'){
                position[i][j] = countmines(i, j);
                
            }
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << position[i][j];
        }
        cout << endl;
    }
}