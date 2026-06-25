/*
    Problem : Given an integer n.
              Find the floor of the square root of n.

    Example :  

                Input :     n  = 48

                Output :    6

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int square_root(int n)
    {
        long long low = 1, high = n / 2;
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long squared = (mid * mid);
            if(squared <= n) low = mid + 1;
            else high = mid - 1;
            
        }
        return high;
    }
    
};


int main()
{
    int n;
    cin >> n;
    Solution sol;
    int sq_root = sol.square_root(n);
    cout <<"Square root : " << sq_root;
}

/*
    Approaches :

        1.Linear Iterative Implementation O(n) Near about linear | O(1)
        2.Logarithmic Elimination O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)

    Quick note :
        The core idea is to find the maximum integer which on squaring <= n;

        If this is comes up in an interview, we end up looking at two conditions :

        1.Do we know the range to search ?
        2.Are we asked to figure out a max or min in the range ? 

        If yes, We'll go for binary search. We'll tweak it ;)
*/