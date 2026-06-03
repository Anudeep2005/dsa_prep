/*
    Problem : Remove duplicates from a sorted array.

    You're given an array of size n. Remove duplicates or push them towards the end of the array.

    Example : 

    Input: N = 7, array[] = {1,1,2,2,2,3,3}
    Output: {1,2,3,_,_,_,_}.

    Author : AnuRudransh@caffeine-engine.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void remove_duplicates(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;
        for(int j = 0;j < n;j++)
        {
            if(nums[j] != nums[i])
            {
                i++;
                nums[i] = nums[j];
            }
        }
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    Solution sol;
    sol.remove_duplicates(nums);
    for(int i = 0;i < n;i++) cout << nums[i] <<" ";
    
} 
