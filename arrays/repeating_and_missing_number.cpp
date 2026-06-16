/*
    Problem : Given an integer array nums of size n containing values from [1, n] and each value appears exactly once in the array, except for A, which appears twice and B which is missing.
            Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

            Note: You are not allowed to modify the original array.

Example: 

                Input:
                        nums = [3, 5, 4, 1, 1]  

                Output:
                            [1, 2] 

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> missing_and_repeating_nums(vector<int> nums)
    {
        int n = nums.size();
        int Sn = n * (n + 1) / 2;
        int S2n = n * ((n+1) * (2*n+1)) / 6;
        int S = 0;
        long long S2 = 0;
        for(int i = 0;i < n;i++)
        {
            S += nums[i];
            S2 +=  (long long) (nums[i] * nums[i]);
        }
        int val1 = (S - Sn);
        int val2 = (S2 - S2n);
        val2 = val2 / val1;
        int x = (val1 + val2) / 2;
        int y = (val2 - x);
        return {x,y};
        
    }
    
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    vector<int> numm = sol.missing_and_repeating_nums(nums);
    cout <<"Repeating number : "<< numm[0] << endl <<"Missing number : "<< numm[1];
    

    return 0;
}

/*
    Approaches :

        1.Brute force - Nested for loop O(n^2) | O(1)
        2.Hashmap based approach O(n) | O(n)
        3.Observation based O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/