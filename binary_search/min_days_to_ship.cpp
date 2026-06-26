/*
    Problem : Given an array weights of size n and an integer d.
              Where weights[i] represents the weight of ith package.

              We're supposed to ship the packages within 'd' days.
              Return the minimum integer x where x is the minimum capacity we could go with to complete the shipping in time.

    Example : 
    
                Input :  n = 10  weights = {1,2,3,4,5,6,7,8,9,10}    days = 5

                Output : 15

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicStuff 
{
    public:
    bool isCapable(vector<int>& weights,int n, int mid,int days)
    {
        int days_req = 1,load = 0;
        for(int i = 0;i < n;i++)
        {
            if(load + weights[i] > mid)
            {
                days_req += 1;
                load = weights[i];
            }
            else load += weights[i];
        }
        if(days_req <= days) return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days)
    {
        int n = weights.size();
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(isCapable(weights,n,mid,days))
                high = mid - 1;
            else low = mid + 1;
        }
        return low;    
    }
};
int main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0;i < n;i++) cin >> weights[i];
    int days;
    cin >> days;
    MagicStuff magic;
    int capacity = magic.shipWithinDays(weights,days);
    cout <<"Minimum capacity : " << capacity;
}

/*
    Approaches :

        1.Iterative Linear Search O(sum - max_ele + +) * n | O(1)
        2.Binary Search    O(log (sum - max_ele +1) * n) | O(1)

    Complexity Analysis

    Time : O(log (sum - max_ele +1) * n) 
    Space : O(1)
*/