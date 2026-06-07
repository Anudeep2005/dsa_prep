/*
    Problem :Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise. The rotation must be done in place,
    meaning the input 2D matrix must be modified directly..

    Example :
    
            Input : 

                matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]

            Output: 

                matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void rotate_an_image(vector<vector<int>> &nums)
    {
        int n = nums.size();
        int m = nums[0].size();
        for(int i = 0;i < n;i++)
        {
            for(int j = i;j < m;j++) swap(nums[i][j],nums[j][i]);
        }
        for(int i = 0;i < n;i++)
        {
            reverse(nums[i].begin(),nums[i].end());
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
    sol.rotate_an_image(nums);
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

        1.Brute force - Making use of an extra matrix O(n^2) \ O(n^2)
        2.Lower triangular matrix traversal and reversal O(n^2) | O(1)

    Complexity Analysis

    Time : O(n^2)
    Space : O(1)
*/