/*
    Problem : Given an array Arr[] of integers, 
    rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.
    If such an arrangement is not possible, 
    it must rearrange to the lowest possible order (i.e., sorted in ascending order).

    Example :

    Input: Arr[] = {1,3,2}

    Output: {2,1,3}

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{

    public:
    void next_perm(vector<int> & nums)
    {
        int n = nums.size();
        int index = -1;
        for(int i = n-2;i >= 0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                index = i;
                break;
            }
        }
        if(index == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        else
        {
            for(int i = n-1;i > index;i--)
            {
                if(nums[i] > nums[index])
                {
                swap(nums[i],nums[index]);
                break;
                }
            }
        }
        reverse(nums.begin() + index + 1,nums.end());
       
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
    sol.next_perm(nums);
    for(int num:nums) cout << num <<" ";

    return 0;
}

/*
    Approaches :

        1. Brute force recursive approach - Generate all possible permutations O(n! * n) | O(n!)
        2. Break point based approach O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/