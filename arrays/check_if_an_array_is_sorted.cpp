/*
    Problem : Check if an array is sorted.

    You're given an array of size n. Check whether the array follows 
    the sorted property or not.

    If yes return true and Vice Versa.

    Example : 

    Input: N = 5, array[] = {1,2,3,4,5}
    Output: True.

    Author : AnuRudransh@caffeine-engine.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    bool checksortedprop(vector<int> nums,int n)
    {
        for(int i = 1;i < n;i++)
        {
            if(nums[i] < nums[i-1]) return false;
        }
        return true;
    }

};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    Solution sol;
    string res = (sol.checksortedprop(nums,n) ? "True" : "False");
    cout << res;
    
} 
