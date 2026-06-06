/*
    Problem :Given an array prices of size n.
    Where the ith element represents the price on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    Return the maximum profit you can achieve from this transaction.
    If you cannot achieve any profit, return 0.

    Example :

    Input:  prices = [7,1,5,3,6,4]
    Output: 5

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    int buy_and_sell_stocks(vector<int> prices)
    {
        int n = prices.size();
        int min_price = INT_MAX;
        int maxx_profit = 0;
        for(int price:prices)
        {
            if(price < min_price) min_price = price;
            maxx_profit = max(maxx_profit,price-min_price);
        }
        return maxx_profit;
    }
    
};

int main()
{
    int n;
    cin >> n;

    vector<int> prices(n);

    for(int i = 0; i < n; i++)
        cin >> prices[i];

    Solution sol;
    int max_profit = sol.buy_and_sell_stocks(prices);
    cout <<"Max profit : " <<max_profit;

    return 0;
}

/*
    Approaches :

        1.Brute force - Nested loop O(n^2) | O(1)
        2.Dynamic Programming - Keeping track of min_price so far O(n) | O(1)

    Complexity Analysis

    Time : 
    Space :
*/