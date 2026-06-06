/*
    Problem : There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. 
    Without altering the relative order of positive and negative elements, 
    you must return an array of alternately positive and negative values.

    Example :

        Input:
                arr[] = {1,2,-4,-5}, N = 4
        Output:
                1 -4 2 -5

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> rearrange_elements(vector<int> nums)
    {
        int n = nums.size();
        if(n <= 2) return {-1};
        int pos = 0, neg = 1;
        vector<int> ans(n,0);
        for(int i = 0;i < n;i++)
        {
            if(nums[i] > 0)
            {
                ans[pos] = nums[i];
                pos += 2;
            }
            else
            {
                ans[neg] = nums[i];
                neg += 2;
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

    Solution sol;
    vector<int> rearranged = sol.rearrange_elements(nums);
    for(int num : rearranged) cout << num <<" ";
    return 0;
}

/*
    Approaches :

        1.Brute force - two empty arrays +ve and -ve elements O(2n) | O(n)
        2.Two pointer approach - O(n) | O(n) -> To return the answer.

    Complexity Analysis

    Time : O(n)
    Space : O(n) | O(1) -> Depending on the system considerations.

*/