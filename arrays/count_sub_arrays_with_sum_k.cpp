/*
    Problem : Given an array of size n and a variable k.
              Return the count of sub arrays with sum k.

    Example :

        Input : 
                n = 3, nums = {1,2,3} k = 3;
        Output : 
                2

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int subarrays_with_sumk(vector<int> nums,int k)
    {
        int n = nums.size();
        int pref_sum = 0,cnt = 0;
        unordered_map<int,int> stashmap;
        stashmap[0] = 1;
        for(int i = 0;i < n;i++)
        {
            pref_sum += nums[i];
            int rem = pref_sum - k;
            if(stashmap.find(rem) != stashmap.end())
            {
                cnt += stashmap[rem];
            }
            stashmap[pref_sum]++;
        }
        return cnt; 
    }
    
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;

    Solution sol;
    int cnt = sol.subarrays_with_sumk(nums,k);
    cout <<"Sub arrays with sum k : "<<cnt;

    return 0;
}

/*
    Approaches :

        1.Brute force - Nested loops O(n^2) \ O(1)
        2.Prefix sum approach which leverages a hashmap O(n) | O(n)

    Complexity Analysis

    Time :
    Space :
*/