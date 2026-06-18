/*
    Problem : Given an array that contains both negative and positive integers.
             find the maximum product subarray.

    Example :
                Input: Nums = [1,2,3,4,5,0]

                Output: 120

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int max_product_sub_array(vector<int> nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        int pref = 1;
        int suff = 1;
        for(int i = 0;i < n;i++)
        {
            pref *= nums[i];
            suff *= nums[n - i - 1];
            maxi = max(maxi,max(pref,suff));
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
        }
        return maxi;
    }
  
    
};


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    Solution sol;
    int max_pro = sol.max_product_sub_array(nums);
    cout <<"Max product sub array : " << max_pro;
    return 0;
}

/*
    Approaches :

        1.Brute force approach - Nested for loop O(n^2) | O(1)
        2.Observation based Prefix and Suffix Approach O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/