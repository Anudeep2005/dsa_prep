/*
    Problem :Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

    Example :

            Input:
                    N = 5, array[] = {1,3,2,3,1}

            Output :     2 

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;

    return 0;
}

/*
    Approaches :

        1.Brute force - Nested for loop O(n^2) | O(1)
        2.Merge sort based approach O(n log n) | O(n)

    Complexity Analysis

    Time : O(n log n)
    Space : O(n)
*/