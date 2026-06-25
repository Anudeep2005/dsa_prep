/*
    Problem : We're given an two integers n and m.
              Return the nth root of m.

    Example :  
                Input : n  = 3; m = 125

                Output : 5

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class MagicalStuff
{
    public:
    int power(int n,int m,int mid)
    {
        long long ans = 1;
        long long base = mid;
        while(n > 0)
        {
            if(n % 2 == 1)
            {
                ans = ans * base;
                n -= 1;
            }
            else
            {
                base *= base;
                n /= 2;
            }
            
            if(ans > m) return 0;
        }
        if(ans == m) return 1;
        return 2;
    }
    
    int nth_root(int n,int m)
    {
        if(n == 1) return m;
        if(n < 1) return -1;
        
        int low = 1, high = m;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int res = power(n,m,mid);
            if(res == 1) return mid;
            else if(res == 0) high = mid -1;
            else low = mid + 1;
        }
        return -1;
    }
};

int main()
{
    int n,m;
    cin >> n >> m;
    MagicalStuff magic;
    int root = magic.nth_root(n,m);
    cout <<"The nth root of m : " << root;
}
/*
    Approaches :

        1.Linear Iterative Approach O(nth root of m) | O(1)
        2.Binary Search O(log m) | O(1)
    Complexity Analysis

    Time : O(log m)
    Space : O(1)

    Quick note :
        If we were to approach a problem where we observe a monotonical increase or decrease 
        in the range. We can apply binary search to it.

        The power() function is based on the binary exponentiation.
*/