/*
    Problem :   Given an array of size N and an element x.
                Find and return the Floor and Ceil of the x.
                
            Floor : Largest element y where y <= x
            Ceil : Smallest element y where y >= x
    Example :

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> floorandceil(vector<int> nums,int x)
    {
        int _ceil = ceil_ele(nums,x);
        int _floor = floor_ele(nums,x);
        return {_floor,_ceil};
    }
    
    int floor_ele(vector<int> nums,int x)
    {
        int n = nums.size();
        int ans = -1;
        int low = 0,high = n-1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] <= x)
            {
                ans = nums[mid];
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
        
    }

    int ceil_ele(vector<int> nums, int x)
    {
        int n = nums.size();
        int ans = -1;
    
        int low = 0, high = n - 1;
    
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
    
            if(nums[mid] >= x)
            {
                ans = nums[mid];
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    
        return ans;
    }

    
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int x;
    cin >> x;
    Solution sol;
    vector<int> floor_ceil = sol.floorandceil(nums,x);
    cout <<"Floor: " << floor_ceil[0] << endl <<"Ceil : "<< floor_ceil[1];
    return 0;
}

/*
    Approaches :

        1.Linear Search O(n) | O(1)
        2.Binary Search Powered Approach O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)
*/