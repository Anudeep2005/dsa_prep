/*
    Problem : Given an array of N integers, count the inversion of the array (using merge-sort).
              Inversion of an array: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

    Example :

            Input : N = 5, array[] = {5,4,3,7,9}
            
            Output : 3


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int merge(vector<int> &nums,int low,int mid,int high)
    {
        int cnt = 0;
        vector<int> temp;
        int left = low,right = mid + 1;
        while(left <= mid && right <= high)
        {
            if(nums[left] > nums[right])
            {
                cnt += (mid - left) + 1;
                temp.push_back(nums[right]);
                right += 1;
            }
            else
            {
                temp.push_back(nums[left]);
                left += 1;
            }
        }
        while(left <= mid) temp.push_back(nums[left++]);
        while(right <= high) temp.push_back(nums[right++]);
        for(int i = low;i <= high;i++)
        {
            nums[i] = temp[i - low];
        }
        return cnt;
    }
    
    int mergesort(vector<int> &nums,int low,int high)
    {
        int cnt = 0;
        if(low >= high) return cnt;
        int mid = low + ((high - low) / 2);
        cnt += mergesort(nums,low,mid);
        cnt += mergesort(nums,mid+1,high);
        cnt += merge(nums,low,mid,high);
        
        return cnt;
        
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    Solution sol;
    int inversions = sol.mergesort(nums,0,n-1);
    cout <<"The number of inversions are : "<<inversions;
    
    
}

/*
    Approaches :

        1.Brute force - Nested For Loop O(n^2) | O(1)
        2.Merge Sort Powered Approach O(n log n) | O(n)

    Complexity Analysis

    Time : O(n log n)
    Space : O(n)
*/