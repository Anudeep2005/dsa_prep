/*
    Problem : Given an array of size n. Sort that using Merge Sort.

    Example :

        Input :
                    N=7
                    arr[]={3,2,8,5,1,4,23}
                    
        Output :    {1,2,3,4,5,8,23}

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void merge(vector<int> & nums,int low,int mid,int high)
    {
        vector<int> temp;
        int left = low, right = mid + 1;
        while(left <= mid && right <= high)
        {
            if(nums[left] <= nums[right])
            {
                temp.push_back(nums[left]);
                left++;
            }
            else if(nums[right] < nums[left])
            {
                temp.push_back(nums[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            temp.push_back(nums[left++]);
        }
        while(right <= high)
        {
            temp.push_back(nums[right++]);
        }
        for(int i = low;i <= high;i++)
        {
            nums[i] = temp[i-low];
        }
    }

    void mergesort(vector<int> &nums,int low,int high)
    {
        if(low >= high) return;
        int mid =  low + ((high - low) / 2);
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,mid,high);
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
    sol.mergesort(nums,0,n-1);
    for(int num : nums) cout << num <<" ";

    return 0;
}

/*

    Complexity Analysis

    Time : O(n log n)
    Space : O(n)
    
*/