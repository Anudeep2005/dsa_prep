/*
    Problem : Given an array nums of size n and an integer x.
              Find the number of occurrences of x in nums.

    Example :  
    
                Input : n = 7   nums = {3,4,13,13,13,20,40} x = 13

                Ouptut : 3

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int find_occurrences(const vector<int> nums,int x)
    {
        int first = first_occ(nums,x);
        int last = last_occ(nums,x);
        return (last - first) + 1;
    }
    int first_occ(const vector<int> nums,int x)
    {
        int n = nums.size();
        int ans = -1;
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == x)
            {
                ans = mid;
                high = mid - 1;
            }
            else if(nums[mid] < x)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
    int last_occ(const vector<int> nums,int x)
    {
        int n = nums.size();
        int ans = -1;
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == x)
            {
                ans = mid;
                low = mid + 1;
            }
            else if(nums[mid] > x)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int x;
    cin >> x;
    Solution sol;
    int occurrences = sol.find_occurrences(nums,x);
    cout <<"occurrences : " << occurrences;
    return 0;
}

/*
    Approaches :

        1.Brute force - Linear Search O(n) | O(1)
        2.Logarithmic Elimination of Array Halves O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)
*/