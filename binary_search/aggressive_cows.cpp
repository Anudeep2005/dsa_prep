/*
    Problem : Given an array stalls of size n and an integer k which denotes the number of aggressive cows.
              Stalls[i] denotes the exact coordinate of the place where ith stall is at.
              Place k cows in such a way that you maximize the minimum distance between two consecutive cows.

    Example :   

            Input : n = 6   stalls = {0,3,4,7,10,9}     k = 4

            Output : 3

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    bool canPlaceCows(const vector<int>& stalls,int n,int k,int dist)
    {
        int Cowcount = 1,cord = stalls[0];
        for(int i = 1;i < n;i++)
        {
            if(stalls[i] - cord >= dist)
            {
                Cowcount++;
                cord = stalls[i];
            }
            
            if(Cowcount >= k) return true;
        }
        return false;
    }
    int maxmin_cows(const vector<int>& stalls,int k)
    {
        int n = stalls.size();
        sort(stalls.begin(),stalls.end());
        int low = 1,high = stalls[n-1] - stalls[0];
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(canPlaceCows(stalls,n,k,mid)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
    
};

int main()
{
    int n;
    cin >> n;
    vector<int> stalls(n);
    for(int i = 0;i < n;i++) cin >> stalls[i];
    int k;
    cin >> k;
    MagicalStuff magic;
    int cows = magic.maxmin_cows(stalls,k);
    cout << cows;
}

/*
    Approaches :

        1.Linear Iterative Approach O(max - min) * O(n) | O(1)
        2.Binary search powered approach O(log (max - min)) * O(n) | O(1) 
    Complexity Analysis

    Time :  O(log (max - min)) * O(n)
    Space : O(1)


    Quick note :
    This questions asks us to find the maximum of minimum distances.
    So, it's basically how we interpret the question. that's what matters a lot.

    If we were to place cows by having dist = 1, we would the minimum distance between two consecutive cows as 3.
    Similarly if we were to do the same with 2 and 3. We'd end up stopping at 3. Cause that's the maximum possible answer.

    That's what they're looking for, the maximum possible minimum distance between two consecutive cows.

*/