/*
    Problem : Find upper and lower bound indices for the given target element.
    
    Example :

        Input : n = 6   nums = {3,5,8,9,15,19}  x = 9

        Output :  Lower bound index : 3
                  Upper bound index : 4

    Author : AnuRudransh@caffeine-engine
*/



#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int lower_bound(vector<int> nums,int x)
    {
        int n = nums.size();
        int ans = n;
        int low = 0,high = n-1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] >= x)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
    int upper_bound(vector<int> nums,int x)
    {
        int n = nums.size();
        int ans = n;
        int low = 0,high = n-1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] > x)
            {
                ans = mid;
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
    for(int i = 0;i < n;i++) cin >> nums[i];
    int x;
    cin >> x;
    Solution sol;
    int lower_bound = sol.lower_bound(nums,x);
    int upper_bound = sol.upper_bound(nums,x);
    cout <<"Lower bound index :" << lower_bound <<endl;
    cout <<"Upper bound index : " << upper_bound;
}


/*
    Approaches :

        1.Logarithmic Elimination of halves O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)
*/