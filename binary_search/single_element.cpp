/*
    Problem : Given a sorted array nums of size n.
              Where every element appears twice except one element.
              Return that single element.

    Example :   
    
                Input :     n = 11  nums = {1,1,2,2,3,3,4,5,5,6,6}

                Output :    4

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int single_ele(const vector<int> nums,int n)
    {
        if(n < 1) return -1;
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];
        
        int low = 1, high = n - 2;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid+1])
                return nums[mid];
            if((mid % 2 == 0 && nums[mid] == nums[mid] + 1) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
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
    int ele = sol.single_ele(nums,n);
    cout <<"Single element : " << ele;
    
}

/*
    Approaches :

        1.Linear search O(n) | O(1)
        2.Logarithmic Elimination O(log n) | O(1)
    Complexity Analysis

    Time : O(log n)
    Space : O(1)

    Quick note : The whole idea is to figure out whether we're on the right half
                 of the single element or the left half of the single element.
                
                Since the right half elements follow the (even,odd) property.
                And the ones on the right follow (odd,even) property.

                Where the same elements are at (even,odd) indices.
                If that's the case, we're on the right half of the element.
*/