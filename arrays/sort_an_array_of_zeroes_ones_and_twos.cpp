/*
    Problem : Given an array nums consisting of only 0, 1, or 2.
    Sort the array in non-decreasing order.
    The sorting must be done in-place, without making a copy of the original array.

    Example :


        Input: nums = [1, 0, 2, 1, 0]
        Output: [0, 0, 1, 1, 2]


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dutch_national_flag_algo(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0,mid = 0, high = n - 1;
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[low],nums[mid]);
                low++,mid++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid],nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }

    }
    
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];

    Solution sol;
    sol.dutch_national_flag_algo(nums);
    for(int i = 0;i < n;i++) cout << nums[i] <<" ";

    return 0;
}

/*
    Approaches :

        1.Brute force - Keeping track of the frequencies using variables O(2n) | O(1)
        2.Dutch National Flag Algorithm O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/