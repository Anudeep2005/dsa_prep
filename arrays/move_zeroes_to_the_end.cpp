/*
    Problem : Move zeroes to the end.

    You're given an array of size n. 
    Move all the zeoroes to the end without altering the order of the elements.

    Example : 

    Input: { 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1 }
    Output: { 1 ,2 ,3 ,4 ,1 ,0 ,0 ,0 }
    Author : AnuRudransh@caffeine-engine.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    void move_zeores(vector<int> &nums)
    {
        int n = nums.size();
        int j = -1;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] == 0)
            {
                j = i;
                break;
            }
        }
        if(j == -1) return;
        for(int i = j+1;i < n;i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[j++]);
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
    sol.move_zeores(nums);
    for(int i = 0;i < n;i++) cout << nums[i] <<" ";
    
} 


/*
    Complexity Analysis 

    Time : O(n)
    Space O(1) 

*/