/*
    Problem : Given a sorted array nums of size n.
              Return the count of rotations.

            

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
    int rotation_count(vector<int> nums)
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
   int rotations = sol.rotation_count(nums);
   cout <<"Rotation count : " << rotations;
   return 0;
}

/*
    Approaches :

        1.Logarithmic Elimination of halves O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)

    Quick note : If we were to figure out the min element in the array,
                 The position of that element is the exact number of rotations.


*/