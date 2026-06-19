/*
    Problem : You are given a sorted array arr of distinct values and a target value x. You need to search for the index of the target value in the array.

Example :

        Input :     arr[] = {1,2,4,7}, x = 6
        Output :    3

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int insert_pos(vector<int> nums,int x)
    {
        return lower_bound(nums,x);
    }

    int lower_bound(vector<int> nums, int x)
    {
        int n = nums.size();
        int ans = n;
    
        int low = 0, high = n - 1;
    
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
    int insert_pos = sol.insert_pos(nums,x);
    cout <<"Insert position : " << insert_pos;
    return 0;
}

/*
    Approaches :

        1.Linear Search O(n) | O(1)
        2.Binary Search powered lower bound O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)
*/