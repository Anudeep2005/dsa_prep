/*
    Problem : Given an integer array nums of size n.
              Find and return the peak's index.

        A peak is a number where that's greater than both the neighbours :
                    --> arr[i-1] < arr[i] > arr[i+1] <--
        An array can have multiple peaks, return any one of em.

    Example :

                Input :    n = 10    nums = {1,2,3,4,5,6,7,8,5,1}
                
                Output : 7

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int peak_element(const vector<int> nums,int n)
    {
        if(n == 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n - 1;
        
        int low = 1, high = n - 2;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] > nums[mid -1] && nums[mid] > nums[mid + 1])
                return mid;
            else if(nums[mid] > nums[mid - 1])
                low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    Solution sol;
    int peak = sol.peak_element(nums,n);
    cout <<"Peak : " << peak;
    
}

/*
    Approaches :

        1.Linear Search O(n) | O(1)
        2.Peak and Depression Based Logarithmic Elimination O(log n) | O(1)

    Complexity Analysis
 
    Time :  O(log n)
    Space :  O(1)

    Quick note :

        We were to assume that the array has -∞ on both the ends.. 
        So, even if it has one element that would be greater than both the infinities and still be considered a peak.

        We'll start off by conquering the edges cases.
        Then we'll perform a binary search assuming that atleast some portion of the array would be sorted.
        
        The break point is where the peak is at. Move towards the break-point.
*/