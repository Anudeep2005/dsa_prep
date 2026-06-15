/*
    Problem : Given an array of integers A and an integer B.
             Find the total number of subarrays having bitwise XOR of all elements equal to k.

    Example : 
    
            Input : n = 5 nums = {4,2,2,6,4}, k = 6;
            Output : 4

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int count_xors(vector<int> nums,int k)
    {
        int cnt = 0;
        int n = nums.size();
        unordered_map<int,int> stashmap;
        stashmap[0] = 1;
        int prefxor = 0;
        for(int i = 0;i < n;i++)
        {
            prefxor ^= nums[i];
            int required = (prefxor ^ k);
            if(stashmap.find(required) != stashmap.end())
            {
                cnt += stashmap[required];
                
            }
            stashmap[prefxor]++;
        }
        return cnt;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int k;
    cin >> k;
    Solution sol;
    int xors = sol.count_xors(nums,k);
    cout <<"XORs : "<<xors;
}

/*
    Approaches :

        1.Brute force - Nested Loops O(n) | O(1)
        2.Prefix XOR Approach O(n) | O(n)

    Complexity Analysis

    Time : O(n)
    Space : O(n)
*/