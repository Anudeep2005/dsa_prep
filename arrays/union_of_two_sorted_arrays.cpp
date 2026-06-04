/*
    Problem : Given two sorted arrays of size m and n respectively.
              Find the union of both the arrays.


    Example : 

            Input:  n = 5,m = 5 

            arr1[] = {1,2,3,4,5} ; arr2[] = {2,3,4,4,5}
            Output: {1,2,3,4,5}

    Author : AnuRudransh@caffeine-engine.

*/


#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<int> union_of_sorted_arrays(vector<int> nums1, vector<int> nums2)
    {
        vector<int> temp;
        int n = nums1.size(), m = nums2.size();
        int i = 0, j = 0;
        while(i < n && j < m)
        {
            if(nums1[i] < nums2[j])
            {
                if(temp.empty() || temp.back() != nums1[i])
                {
                    
                } 
            }
        }
    }

};

int main()
{
    int n,m;
    cin >> n >> m;
    vector<int> nums1(n);
    vector<int> nums2(m);
    for(int i = 0;i < n;i++) cin >> nums1[i];
    for(int i = 0;i < m;i++) cin >> nums2[i];
    Solution sol;
    vector<int> Union = sol.union_of_sorted_arrays(nums1,nums2);
    for(int i = 0;i < Union.size();i++)
    {

    }

    
} 



/*

    Approaches :

        1.Hashmap
        2.Sets
        3.Two pointer approach - optimal approach.

    Complexity Analysis

    Time : 
    Space : 


*/