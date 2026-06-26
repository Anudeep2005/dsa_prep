/*
    Problem :   Given an array nums of size n and a threshold named limit.
                Return the minimum integer x such that the sum of all the division operations on nums with x <= limit.


    Example :
                Input :     n = 5   nums = {1,2,3,4,5}  limit = 8

                Output : 3
    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    pair<int,int> minimax(const vector<int>& nums,int n)
    {
        int mini = INT_MAX,maxi = INT_MIN;
        for(int i = 0;i < n;i++)
        {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        return {mini,maxi};
    }
    bool thresh_potent_div(const vector<int>& nums,int n,int mid,int limit)
    {
        int summ = 0;
        for(int i = 0;i < n;i++) 
        {
            summ += ceil((double) nums[i] / (double) mid);
            if(summ > limit) return false;
        }
        return true;
    }
    int min_threshold_divisor(const vector<int>& nums,int n,int limit)
    {
        pair<int,int> minmax = minimax(nums,n);
        int ans = -1;
        int low = minmax.first,high = minmax.second;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(thresh_potent_div(nums,n,mid,limit))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
            
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int limit;
    cin >> limit;
    MagicalStuff magic;
    int mini = magic.min_threshold_divisor(nums,n,limit);
    cout <<"Minimum possible threshold divisor where sum(Divi Ops) <= limit : " << mini;
    
}

/*
    Approaches :

        1.Linear Iterative Approach O(max_element(arr) * n) | O(1)
        2.Binary Search O(log max_element(arr) * n) | O(1)

    Complexity Analysis

    Time : O(log max_element(arr) * n)
    Space : O(1)
*/