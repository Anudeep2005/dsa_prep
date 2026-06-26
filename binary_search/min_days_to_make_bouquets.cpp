/*
    Problem :  Given an array arr of size n.
               Where the array has n flowers and the ith flower blooms on the arr[i]th day.
               m represents the required number of bouquets and k represents the count of flowers in each bouquet.

               Return an integer k such that 
               k represents the minimum days to make the required bouquets.

    Example :   
                Input :     n =  8  arr = {7,7,7,7,13,12,11,7}  m = 2   k = 3

                Output : 12
    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    int max_ele(const vector<int>& arr,int n)
    {
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++) maxi = max(maxi,arr[i]);
        return maxi;
    }
    int count_bouquets(const vector<int>& arr,int n,int mid,int m,int k)
    {
        int count = 0,bouquets = 0;
        for(int i = 0;i < n;i++)
        {
            if(arr[i] <= mid) count++;
            if(count == k)
            {
                bouquets++;
                count = 0;
            }
            if(arr[i] > mid) count = 0;
        }
        if(bouquets >= m) return 0;
        return 1;
    }
    int min_days(const vector<int>& arr,int n,int m,int k)
    {
        int ans = -1;
        int low = 1, high = max_ele(arr,n);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int res = count_bouquets(arr,n,mid,m,k);
            if(res == 0)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    int m,k;
    cin >> m >> k;
    MagicalStuff magic;
    int mini = magic.min_days(arr,n,m,k);
    cout <<"Minimum days : " << mini;
}

/*
    Approaches :

        1.Linear Iterative Approach O(max_element(arr) * n) | O(1)
        2.Binary Search O(log max_element(arr) * n) | O(1)

    Complexity Analysis

    Time : O(log max_element(arr) * n)
    Space : O(1)
*/