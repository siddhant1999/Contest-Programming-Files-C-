//
//  main.cpp
//  Primes
//
//  Created by Siddhant Jain on 2014-10-26.
//  Copyright (c) 2014 Siddhant Jain. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

bool isprime(int x)
{
    if (x % 2 == 0) return false;
    for (int i = 3; i * i <= x;i+= 2)
        if (x % i == 0)
            return false;
    return true;
}