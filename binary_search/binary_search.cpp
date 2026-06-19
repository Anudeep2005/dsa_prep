/*
    Problem : Implement the traditional binary search (Iterative & Recursive).

    Example :

        Input : n = 9   nums = {1,2,3,4,5,6,7,8,9}  x = 6

        Output : Iterative outcome : 5
                 Recursive outcome : 5

    Author : AnuRudransh@caffeine-engine
*/



#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int iterative(vector<int> nums,int x)
    {
        int n = nums.size();
        if(n < 1) return 0;
        int low = 0, high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(nums[mid] == x) return mid;
            else if(nums[mid] > x) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    int recursive(vector<int> nums,int x,int low,int high)
    {
        if(low > high) return -1;
        int mid = low + (high - low) / 2;
        if(nums[mid] == x) return mid;
        else if(nums[mid] > x) return recursive(nums,x,low,mid - 1);
        else return recursive(nums,x,mid + 1,high);
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int x;
    cin >> x;
    Solution sol;
    int fir_ind = sol.iterative(nums,x);
    int sec_ind = sol.recursive(nums,x,0,n-1);
    cout << "Iterative outcome : " << fir_ind << endl;
    cout <<" Recursive outcome : " << sec_ind;
}


/*
    Approaches :

        1.Traditional Approach O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)
*/


