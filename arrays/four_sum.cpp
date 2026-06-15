/*
    Problem :Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

    Example :


            Input :     arr[] = [1,0,-1,0,-2,2], target = 0
            
            Output :    [[-2,-1,1,2],
                        [-2,0,0,2],
                        [-1,0,0,1]]

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<vector<int>> foursum(vector<int> nums,int x)
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i < n;i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1;j < n;j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j + 1, right = n - 1;
                while(left < right)
                {
                    long long sum = (long long) nums[i] + nums[j];
                    sum += (long long) nums[right] + nums[left];
                    if(sum == x)
                    {
                        ans.push_back({nums[i],nums[j],nums[left],nums[right]});
                        while(left < right && nums[left] == nums[left + 1]) left += 1;
                        while(left < right && nums[right] == nums[right - 1]) right -= 1;
                        left += 1;
                        right -= 1;
                    }
                    else if(sum < x) left += 1;
                    else right -= 1;
                }
            }
        }
        return ans;
    }
    
};

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> nums[i];
    int target;
    cin >> target;
    Solution sol;
    vector<vector<int>> pairs = sol.foursum(nums,target);
    for(int i = 0;i < pairs.size();i++)
    {
        for(int j = 0;j < pairs[i].size();j++)
        {
            cout <<pairs[i][j] <<" ";
        }
        cout <<endl;
    }

    return 0;
}

/*
    Approaches :

        1.Brute force Nested Loops O(n^4) | O(1)
        2.Sorting and Pointer Based Approach O(n^3) | O(1)

    Complexity Analysis

    Time : O(n^3)
    Space : O(1)
*/