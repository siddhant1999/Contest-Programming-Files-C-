//
//  main.cpp
//  Upper_Bound Binary
//
//  Created by Siddhant Jain on 2015-02-23.
//  Copyright (c) 2015 Siddhant Jain. All rights reserved.
//

int binary(int low, int high, int k)
{
    int mid;
    while ( low <= high )
    {
        mid = (low + high) / 2;
        if (board[mid] == k ) return mid;//
        if (low==high) return low;
        if ( board[mid] < k )
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}