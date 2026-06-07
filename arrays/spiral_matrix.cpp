/*
    Problem : Given a matrix. print that in spiral order.

    Example :

        Input :     n =  4 m = 4;
                    matrix = [[1,2,3,4]
                              [5,6,7,8]
                              [9,10,11,12]
                              [13,14,15,16]]
        Output : ans = [1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10]

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> spiral_traversal(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        int top = 0,right = m-1,bottom = n-1,left = 0;
        vector<int> ans;
        while(left <= right && top <= bottom)
        {
        
            for(int i = left;i <= right;i++)
            {
                ans.push_back(nums[top][i]);
            }
            top += 1;
                for(int i = top;i <= bottom;i++)
                {
                    ans.push_back(nums[i][right]);
                }
            right -= 1;
            if(top <= bottom)
            {
                for(int i = right;i >= left;i--)
                {
                    ans.push_back(nums[bottom][i]);
                }
                bottom -= 1;
            }
            
            
            if(left <= right)
            {
                for(int i = bottom;i >= top;i--)
                {
                    ans.push_back(nums[i][left]);
                }
                left += 1;
            }
            
        }
        return ans;
        
    }
    
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> nums(n,vector<int>(m,0));
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cin >> nums[i][j];
        }
    }
    Solution sol;
    vector<int> ans = sol.spiral_traversal(nums);
    for(int i = 0;i < ans.size();i++) cout << ans[i] <<" ";
}

/*
    Approaches :

        1.Boundary based traversal O(n * m) | O(1)

    Complexity Analysis

    Time : O(n * m)
    Space : O(1)
*/