/*
    Problem : Left rotate array by k places.

    You're given an array of size n. Left rotate the array by k places.


    Example : 

    Input : N = 7, nums = [1, 2, 3, 4, 5, 6, 7], k = 2, right
    Output : [6, 7, 1, 2, 3, 4, 5]

    Author : AnuRudransh@caffeine-engine.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void left_rotate(vector<int> &nums,int k)
    {
        int n = nums.size();
        k %= n;

        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
        reverse(nums,0,n-1);
    }

    void right_rotate(vector<int> &nums,int k)
    {
        int n = nums.size();
        k %= n;

        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }

    void reverse(vector<int> &nums,int start,int end)
    {
        while(start <= end)
        {
            swap(nums[start++],nums[end--]);
        }
    }

};

int main()
{
    int n,k;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    cin >> k;
    string part;
    cin >> part;
    Solution sol;
    if(part == "left") sol.left_rotate(nums,k);
    else sol.right_rotate(nums,k);
    for(int i = 0;i < n;i++) cout << nums[i] <<" ";
    
} 
