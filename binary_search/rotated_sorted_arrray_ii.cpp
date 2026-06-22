/*
    Problem : Given an array nums of size n and an integer x which has duplicates.
              The array is rotated. Find and return the index of x.

    Example : 
    
                Input :  n = 7   nums = {3,1,2,3,3,3,3} x = 1

                Output : 1

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int rotated_sorted_arr(const vector<int> nums,int x)
    {
        int n = nums.size();
        int ans = -1;
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == x) return mid;
            else if(nums[low] == nums[mid] && nums[mid] == nums[high])
            {
                low++;
                high--;
                continue;
            }
            else if(nums[low] <= nums[mid])
            {
                if(nums[low] <= x && x <= nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            else
            {
                if(nums[mid] <= x && x <= nums[high])
                    low = mid + 1;
                else high = mid - 1;
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
    int ind = sol.rotated_sorted_arr(nums,x);
    cout <<"Index : " << ind;
    return 0;
}

/*
    Approaches :

        1.Brute force - Linear Search O(n) | O(1)
        2.Tweaked Binary Search O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)


    Quick note : 

        If you were to approach a problem that deals with duplicates.
        Try solving the problem with distinct values first and then
        Fit in the duplicate condition...

*/