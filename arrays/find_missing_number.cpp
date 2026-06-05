/*
    Problem :Given an array arr[] of size n-1 with distinct integers in the range of [1, n]. 
    This array represents a permutation of the integers from 1 to n with one element missing.
    Find the missing element in the array.


    Example :

        Input: arr[] = [8, 2, 4, 5, 3, 7, 1]
        Output: 6


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int missing_num(vector<int> nums)
    {
        int n = nums.size();
        int xor1 = 0, xor2 = 0;
        for(int i = 0;i < n;i++)
            xor1 ^= nums[i];
        for(int i = 1;i <= n+1;i++)
            xor2 ^= i;
        return (xor1 ^ xor2);

    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n-1);
    for(int i = 0; i < n-1; i++)
        cin >> nums[i];
    Solution sol;
    int missing = sol.missing_num(nums);
    cout <<missing <<" ";

    return 0;
}

/*
    Approaches :

        1. Brute-force (Nested loop) - O(n^2) | O(1)
        2. Hashmap - O(n) | O(n)
        3. Summation | XOR Approach - O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/