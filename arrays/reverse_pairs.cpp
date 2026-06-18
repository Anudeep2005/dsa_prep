/*
    Problem :Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].

    Example :

            Input:
                    N = 5, array[] = {1,3,2,3,1}

            Output :     2 

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void merge(vector<int> &nums,int low,int mid,int high)
    {
        int n = nums.size();
        vector<int> temp;
        int left = low,right = mid + 1;
        while(left <= mid && right <= high)
        {
            if(nums[left] >= nums[right])
            {
                temp.push_back(nums[right++]);
            }
            else
            {
                temp.push_back(nums[left++]);
            }
        }
        while(left <= mid)
            temp.push_back(nums[left++]);
        
        while(right <= high)
            temp.push_back(nums[right++]);
            
        for(int i = low;i <= high;i++)
        {
            nums[i] = temp[i- low];
        }
        
    }
    
    int count_pairs(vector<int> nums,int low, int mid, int high)
    {
        int n = nums.size();
        int cnt = 0;
        int right = mid + 1;
        for(int i = low;i <= mid;i++)
        {
            while(right <= high && nums[i] > nums[right] * 2) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
        
    }
    
    
    int merge_sort(vector<int> &nums,int low, int high)
    {
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + (high - low) / 2;
        cnt += merge_sort(nums,low,mid);
        cnt += merge_sort(nums,mid+1,high);
        cnt += count_pairs(nums,low,mid,high);
        merge(nums,low,mid,high);
        return cnt;
        
    }
    
    int count_reverse_pairs(vector<int> &nums)
    {
        int n = nums.size();
        return merge_sort(nums,0,n-1);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    int rev_pairs = sol.count_reverse_pairs(nums);
    cout <<"Reverse pairs : "<< rev_pairs;
    
}

/*
    Approaches :

        1.Brute force - Nested for loop O(n^2) | O(1)
        2.Merge sort based approach O(n log n) | O(n)

    Complexity Analysis

    Time : O(n log n)
    Space : O(n)
*/