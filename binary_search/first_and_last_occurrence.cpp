/*
    Problem : Given an array nums of size n and an integer x.
              Find the first and the last occurrences of x in the array.

    Example : 
    
                Input : n = 7     nums = {3,4,13,13,13,20,40} x = 13

                Output :    First Occurrence : 2
                            Last Occurrence  : 4 



    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> first_and_last_occurences(const vector<int> nums,int x)
    {
        int first = first_occ(nums,x);
        int last = last_occ(nums,x);
        return {first,last};
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
    vector<int> fir_last = sol.first_and_last_occurences(nums,x);
    cout <<"First occurrence : " << fir_last[0] << endl;
    cout <<"Last occurrence : " << fir_last[1] << endl;
    return 0;
}

/*
    Approaches :

        1.Traditional Linear Search O(n) | O(1)
        2.Logarithmic Array Half Elimination O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)
*/