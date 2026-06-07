/*
    Problem :

    Example :

    Author : AnuRudransh@caffeine-engine
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void print_ele()
    {
        
    }

    void print_row()
    {
        
    }

    vector<vector<int>> print_triangle(int rows)
    {
        vector<vector<int>> row_arr;
        for(int i = 0;i < rows;i++)
        {
            vector<int> row;
            for(int j = 0;j <= i;j++)
            {
                if(j == 0 || j == i) row.push_back(1);
                else
                {
                    int ele = row_arr[i-1][j-1] + row_arr[i-1][j];
                    row.push_back(ele);
                }
            }
            row_arr.push_back(row);
        }
        return row_arr;
    }
    
};

int main()
{

    int rows,r,c;
    cin >> rows >> r >> c;
    Solution sol;

    vector<vector<int>> triangle = sol.print_triangle(rows);
    for(int i = 0;i < triangle.size();i++)
    {
        for(int j = 0;j < triangle[i].size();j++)
        {
            cout << triangle[i][j] <<" ";
        }
        cout << endl;
    }

    return 0;
}

/*
    Approaches :

        1.
        2.
        3.

    Complexity Analysis

    Time :
    Space :
*/