/*
    Problem :Given an array nums of size n and an integer k, 
    find the length of the longest sub-array that sums to k.
    If no such sub-array exists, return 0

    Example :
        Input:

         nums = [10, 5, 2, 7, 1, 9], k = 15  

        Output:
                4  


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int longest_subarray_of_size_k_using_hashmap(vector<int> nums, int k)
    {
        int n = nums.size();
        int maxx = 0, pref = 0;
        unordered_map<int,int> prefmap;
        for(int i = 0; i < n; i++)
        {
            pref += nums[i];
            if(pref == k) 
            {
                maxx = i+1;
            }
            
            int rem = pref - k;
            if(prefmap.find(rem) != prefmap.end())
            {
                int len = i - prefmap[rem];  
                maxx = max(len, maxx);
            }
            
            if(prefmap.find(pref) == prefmap.end())
            {
                prefmap[pref] = i;
            }
        }
        return maxx;
    }   


    int longest_subarray_of_size_k_using_two_pointers(vector<int> nums,int k)
    {
        int n = nums.size();
        int i = 0, j = 0;
        int summ = nums[0];
        int maxx = 0;
        while(j < n)
        {
            while(i <= j && summ > k)
            {
                summ -= nums[i];
                i++;
            }

            if(summ == k) maxx = max(maxx,j - i + 1);

            j++;
            if(j < n) summ += nums[j];
        }
        return maxx;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int k;
    cin >> k;
    Solution sol;
    int maxx = sol.longest_subarray_of_size_k_using_hashmap(nums,k);
    int ptrmax = sol.longest_subarray_of_size_k_using_two_pointers(nums,k);
    cout <<"Longest sub array with sum K : (Hashmap | Two pointer approach) " << maxx <<" | " <<ptrmax;
}


/*
    Approaches :

        1.Nested Loops O(n^2) | O(1)
        2.Hashmap based approach O(n) | O(n)
        3.Two pointer approach O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/