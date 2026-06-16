/*
    Problem :Given two sorted integer arrays nums1 and nums2, merge both the arrays into a single array sorted in non-decreasing order.
            The final sorted array should be stored inside the array nums1 and it should be done in-place.
            Array nums1 has a length of m + n, where the first m elements denote the elements of nums1 and rest are 0s whereas nums2 has a length of n.

    Example : 


            Input : 
    
                nums1 = [-5, -2, 4, 5, 0, 0, 0], nums2 = [-3, 1, 8]

            Output : [-5, -3, -2, 1, 4, 5, 8]

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void merge_sorted_arrays(vector<int> nums1, vector<int> &nums2,int n, int m)
    {
        int i = n-1, j = m - 1, k = n + m - 1;
        while(i >= 0 && j >= 0)
        {
            if(nums1[i] >= nums2[j])
            {
                nums2[k--] = nums1[i--];
            }
            else
            {
                nums2[k--] = nums2[j--];
            }
        }
        while(i >= 0)
        {
            nums2[k--] = nums1[i--];
        }
    }
    
};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m+n,0);
    for(int i = 0;i < n;i++)
    {
        cin >> nums1[i];
    }
    for(int i = 0;i < m;i++)
    {
        cin >> nums2[i];
    }
    Solution sol;
    sol.merge_sorted_arrays(nums1,nums2,n,m);
    for(int num : nums2) cout << num << " ";


    return 0;
}

/*
    Approaches :

        1.Simulating everything using 3 pointers O(m + n) | O(1)

    Complexity Analysis

    Time : O(m + n)
    Space : O(1)
*/