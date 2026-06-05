/*
    Problem : Given an integer array nums of size n, return the majority element of the array.

    Example :

        Input:
            nums = [7, 0, 0, 1, 7, 7, 2, 7, 7]  
        Output:
            7 

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int moore_algo(vector<int> nums)
    {
        int cnt = 0;
        int el = -1;
        int n = nums.size();
        for(int i = 0;i < n;i++)
        {
            if(cnt == 0)
            {
                cnt = 1;
                el = nums[i];
            }
            else if(nums[i] == el) cnt++;
            else cnt--;
        }
        int cnt1 = 0;
        for(int i = 0;i < n;i++)
        {
            if(nums[i] == el) cnt1++;
        }
        if(cnt1 > (n/2)) return el;
        return -1;
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
    int majority_el = sol.moore_algo(nums);
    cout <<"Majority element : " <<majority_el;
    return 0;
}

/*
    Approaches :

        1.Brute force - Nested for loop O(n^2) | O(1)
        2.Hashmap powered approach O(n) | O(n)
        3.Moore's voting algorithm O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/