/*
    Problem :

        Given an array nums of n integers.
        Return the length of the longest sequence of consecutive integers.
        The integers in this sequence can appear in any order.

    Example :

        Input : n = 6 ; nums = {100, 4, 200, 1, 3, 2}

        Output : 4


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longest_sequence(vector<int> nums)
    {
        unordered_set<int> stashset;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            stashset.insert(nums[i]);
        }
        int longest_cnt = INT_MIN;
        for(auto it:stashset)
        {
            if(stashset.find(it + 1) == stashset.end())
            {
                int cnt = 1;
                int x = it;
                while(stashset.find(x - 1) != stashset.end())
                {
                    x = x - 1;
                    cnt = cnt + 1;
                }
                longest_cnt  = max(longest_cnt,cnt);
            }
            
        }
        return longest_cnt;
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
    int longest_seq = sol.longest_sequence(nums);
    cout <<"Longest consecutive sequence : "<<longest_seq;
    return 0;
}

/*
    Approaches :

        1.Brute force - Nested loops and Linear Search O(n^2) | O(1)
        2.Sorting the array and figuring out the sequence O(2n log n) | O(1)
        3.Hashmap based reverse lookup O(n) | O(n)

    Complexity Analysis

    Time : O(n)
    Space : O(n)
*/