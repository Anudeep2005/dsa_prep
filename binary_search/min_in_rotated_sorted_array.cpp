/*
    Problem : Given an array nums of size n.
              Return the index of the smallest element in the array.

            

    Example : 
    
            Input : n = 8     nums = {6,7,8,9,0,1,2,3}

            Output : 4

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int rotated_sorted_mini(vector<int> nums)
    {
        int ans = INT_MAX;
        int n = nums.size();
        int low = 0,high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if(nums[low] <= nums[high]) return low;
            
            if(nums[low] == nums[mid] && nums[mid] == nums[high]) 
            {
                ans = min(nums[low],ans);
                low++;
                high--;
                continue;
            }
            else if(nums[low] <= nums[mid])
            {
                ans = min(ans,nums[low]);
                low = mid + 1;
            }
            else if(nums[mid] <= nums[high])
            {
                ans = min(nums[mid],ans);
                high = mid - 1;
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
   Solution sol;
   int mini = sol.rotated_sorted_mini(nums);
   cout <<"Minimum value's position : " << mini;
   return 0;
}

/*
    Approaches :

        1.Brute force - Linear search O(n) | O(1)
        2.Logarithmic Elimination of array halves O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)

    Quick note : The whole idea is to have a look the half and figure out whether it's sorted or not.
                If it is, we'll store the lower bound value and move over to the unsorted half.


*/