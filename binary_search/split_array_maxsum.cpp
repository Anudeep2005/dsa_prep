/*
    Problem : Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. 
    Split the array ‘A’ into ‘K’ non-empty subarrays such that the largest sum of any subarray is minimized.
    Your task is to return the minimized largest sum of the split. A subarray is a contiguous part of the array.

    Example : 

                Input : N = 5, a[] = {1,2,3,4,5}, k = 3
  
                Output : 6

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    int countSubarrays(const vector<int>& arr,int maxi)
    {
        int n = arr.size();
        int subarr_cnt = 1, sum = 0;
        for(int i = 0;i < n;i++)
        {
            if(sum + arr[i] <= maxi) sum += arr[i];
            else
            {
                sum = arr[i];
                subarr_cnt += 1;
            }
        }
        return subarr_cnt;
    }
    int split_array(const vector<int>& arr,int k)
    {
        int n = arr.size();
        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(countSubarrays(arr,mid) > k) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0;i < n;i++) cin >> arr[i];
    int k;
    cin >> k;
    MagicalStuff magic;
    int max_sum = magic.split_array(arr,k);
    cout <<"Max sum : " << max_sum;
}

/*
    Approaches :

        1. Linear Iterative Approach O((sum - max_element + 1) * n) | O(1)
        2. Binary Search O(log (sum - max_element + 1) * n) | O(1)

    Complexity Analysis

    Time :  O(log (sum - max_element + 1) * n)
    Space : O(1)
*/