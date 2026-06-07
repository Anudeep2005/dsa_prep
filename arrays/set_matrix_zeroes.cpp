/*
    Problem : Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0
     and then return the matrix..

    Example :

                Input:
                            matrix=[[1,1,1],
                                    [1,0,1],
                                    [1,1,1]]
                
                Output:     matrix =  [[1,0,1],
                                       [0,0,0],
                                       [1,0,1]]


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void set_matrix_zeroes(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        int col_var = 1;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(nums[i][j] == 0)
                {
                    if(j == 0)
                    {
                        col_var = 0;
                    }
                    else
                    {
                        nums[i][0] = 0;
                        nums[0][j] = 0;
                    }
                }
            }
        }
        for(int i = n-1;i >= 1;i--)
        {
            for(int j = m-1;j >= 1;j--)
            {
                if(nums[i][0] == 0 || nums[0][j] == 0) nums[i][j] = 0;
            }
        }
        for(int i = m-1;i >= 1;i--)
        {
            if(nums[0][i] == 0) continue;
            else if(nums[0][0] == 0) nums[0][i] = 0;
        }
        for(int i = 0;i < n;i++)
        {
            if(nums[i][0] == 0) continue;
            else if(col_var == 0) nums[i][0] = 0;
        }
        
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
    sol.set_matrix_zeroes(nums);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            cout << nums[i][j] <<" ";
        }
        cout <<endl;
    }
    return 0;
}

/*
    Approaches :

        1.Brute force - A dual matrix traversal + Row & Col marking. O(n*m) + O(n+m) | O(1)
        2.Keeping track of rows and cols to be zeroes by making use of two arrays. O(n*m) | O(m+n)
        3.Embedding the arrays into the matrix itself as row and col. O(n*m) | O(1).

    Complexity Analysis

    Time : O(n*m)
    Space : O(1)
*/