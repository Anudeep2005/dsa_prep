/*
    Problem :Check if a pair with given sum exists in Array.

    Example :

        Input: N = 5, arr[] = {2,6,5,8,11}, target = 14

        Output : YES


    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void two_sum(vector<int> nums,int target)
    {
        int n = nums.size();
        bool doesExist = false;
        sort(nums.begin(),nums.end());
        int left = 0, right = n - 1;
        while(left < right)
        {
            int curr_sum = nums[left] + nums[right];
            if(curr_sum == target)
            {
                doesExist = true;
                break;
            }

            if(curr_sum < target) left++;
            else right--;
        }
        cout << (doesExist ? "True" : "False");
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
    sol.two_sum(nums,target);

    return 0;
}

/*
    Approaches :

        1.Brute force - Nested for loop O(n^2) | O(1)
        2.Complement based hashmap approach O(n) | O(n)
        3.Sorted two pointer approach O(n log n) | O(1) 

    Complexity Analysis

    Time : O(n log n)
    Space : O(1)
*/