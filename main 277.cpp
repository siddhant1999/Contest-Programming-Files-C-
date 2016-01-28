#include <fstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

int n, add = 0;
int target = 4;
string bits(30, ' ');

void recursion(int index, int k){
    if (index == n && k == target) {
        cout << bits.substr(0, n) << endl;
        add++;
        return;
    }
    if(index == n)
        return;
    bits[index] = '0';
    recursion(index+1, k);
    bits[index] = '1';
    recursion(index+1, k + 1);
    
}

int main(void){
    cin >> n;
    recursion(0, 0);
    cout << add;
}