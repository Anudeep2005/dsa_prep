/*
    Problem :Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input.

    Example :

            Input : intervals=[[1,3],
                                [2,6],
                                [8,10],
                                [15,18]]

            Output : [[1,6],
                    [8,10],
                    [15,18]]

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:

        vector<vector<int>> merge(vector <vector<int>> &intervals)
        {

            sort(intervals.begin(), intervals.end());
            vector < vector < int >> merged;
            for (auto interval: intervals)
            {
                if (merged.empty() || merged.back()[1] < interval[0]) 
                {
                    merged.push_back(interval);
                } 
                else
                {

                        merged.back()[1] = max(
                        merged.back()[1],
                        interval[1]);
                }
            }

            return merged;
        }
};

int main() {
    Solution sol;
    vector < vector < int >> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector < vector < int >> result = sol.merge(intervals);
    for (auto v: result) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }
    return 0;
}

/*
    Approaches :

        1.Brute force - Nested Loops O(n^2) | O(1)
        2.Pointer based Approach O(n) | O(1)

    Complexity Analysis

    Time : O(n)
    Space : O(1)
*/