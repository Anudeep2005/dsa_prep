/*
    Problem : Given an array of integers of size n and an integer k.
              Return the kth missing integer in the array.

    Example :

            Input : N = 5   nums = {2,3,4,7,11} k = 5

            Output : 9

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    int kth_missing_int(vector<int>& nums,int k)
    {
        int n = nums.size();
        int low = 0,high = n - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int missing = nums[mid] - (mid + 1);
            if(missing < k) low = mid + 1;
            else high = mid - 1;
        }
        return high + k + 1;
    }
    
};

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0;i < n;i++) cin >> nums[i];
    int k;
    cin >> k;
    MagicalStuff magic;
    int num = magic.kth_missing_int(nums,k);
    cout <<"Kth missing number : " << num;
}

/*
    Approaches :

        1.Linear Iterative Approach O(n) | O(1)
        2.Mathematical + Binary Search Approach O(log n) | O(1)

    Complexity Analysis

    Time : O(log n)
    Space : O(1)

    Quick note : When we're at a specific index, let's say x.. the actual number that should'a been there is
                 x + 1. So, figure out the missing elements till that index we'll end up using the formula 

                 missing_elements = arr[x] - (x + 1)
                
                 * Figuring out more is pretty simple. 
                 more = k - missing_elements (basically the additional elements required at a particular index x)

                 and the answer would be arr[high] + more
                 There's a chance that high might be beyond the boundaries of the array.. Soo
                 To figure out the mathematical formual, we elaborate the formula..

                 arr[high] + more -> arr[high] + k - missing -> arr[high] + k - arr[high] - (high + 1)
                 We end up cancelling arr[high] and all that's left is -> high + k + 1
                 Or we could return low + k too, cause low = high + 1;

                 
*/