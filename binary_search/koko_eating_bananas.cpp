/*
    Problem : Given an array piles of size n and an integer h.
              Koko loves eating bananas and the ith pile has piles[i] bananas.
              The integer h determines the maximum time koko can afford to spend on eating bananas.

              Return a minimum value k, such that 
              Coco can eat all the piles in lesser than or equal to h hours.



    Example :

            Input : n = 4   piles = {3,4,6,11}  h = 8
            
            Output : 4

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    int max_ele(const vector<int> piles,int n)
    {
        int maxi = INT_MIN;
        for(int i = 0;i < n;i++) maxi = max(maxi,piles[i]);
        return maxi;
    }
    
    int count_hours(const vector<int> piles,int n,int mid)
    {
        int _hours = 0;
        for(int i = 0;i < n;i++)
        {
            _hours += ceil((double) piles[i] / (double) mid);
        }
        return _hours;
    }
    
    int koko(const vector<int> piles,int h)
    {
        int n = piles.size();
        if(n == 1) return piles[0];
        
        int low = 1, high = max_ele(piles,n);
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int hours = count_hours(piles,n,mid);
            if(hours <= h)
            {
                high = mid - 1;
            }
            else low = mid + 1;
            
        }
        return low;
    }


};

int main()
{
    int n;
    cin >> n;
    vector<int> piles(n);
    for(int i = 0;i < n;i++) cin >> piles[i];
    int h;
    cin >> h;
    MagicalStuff magic;
    int k = magic.koko(piles,h);
    cout <<"Min Bananas : " << k;
}

/*
    Approaches :

        1.Iterative Linear Implementation O(max(piles)) * O(n) | O(1)
        2.Binary Search O(log max(piles)) * O(n) | O(1)

    Complexity Analysis

    Time : O(log max(piles)) * O(n)
    Space : O(1)
*/