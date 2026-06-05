/*
    Problem :  Maximum Subarray Sum in an Array
    Can you print the subarray that has the maximum sum?

    Example :
    
        Input :
                nums = [2, 3, 5, -2, 7, -4]  
        Output:
                15  

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{   
    public:
    vector<int> kadane_algo(vector<int> nums)
    {
        int summ = 0,maxi = INT_MIN;
        int start = 0;
        int ans_start = -1,ans_end = -1;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(summ == 0) start = i;
            summ += nums[i];
            if(summ > maxi)
            {
                maxi = summ;
                ans_start = start;
                ans_end = i;
            }
            if(summ < 0) summ = 0;
        }
        return {ans_start,ans_end,maxi};
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
    vector<int> ans = sol.kadane_algo(nums);
    cout <<"The sub-array with max sum : " <<endl;
    for(int i = ans[0];i <= ans[1];i++)
    {
        cout << nums[i] <<" ";
    }
    cout <<endl <<"Sum : " <<ans[2];
    

    return 0;
}

/*
    Approaches :

        1.Brute force - Nested for loop O(n^2) | O(1)
        2.Kadane's Algorithm O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/