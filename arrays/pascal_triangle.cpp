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
    int print_ele(int n,int r)
    {
        int result = 1;
        for(int i = 0;i < r;i++)
        {
            result = result * (n - i);
            result = result / (i+1);
        }
        return result;
    }

    vector<int> print_row(int n)
    {  
        vector<int> row;
        int val = 1;
        row.push_back(val);
        for(int i = 0;i < n;i++)
        {
            val = val * (n - i) / (i + 1);
            row.push_back(val);
        }
        return row;
  
    }

    vector<vector<int>> print_triangle(int rows)
    {
        vector<vector<int>> row_arr;
        for(int i = 0;i <= rows;i++)
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

    int rows,n,r;
    cin >> rows >> n >> r;
    Solution sol;

    vector<vector<int>> triangle = sol.print_triangle(rows);
    vector<int> row = sol.print_row(n);
    int nCr = sol.print_ele(n,r);
    cout <<"Triangle : " <<endl;
    for(int i = 0;i < triangle.size();i++)
    {
        for(int j = 0;j < triangle[i].size();j++)
        {
            cout << triangle[i][j] <<" ";
        }
        cout << endl;
    }
    cout << n <<"th Row :";
    for(int i = 0;i < row.size();i++)
    {
        cout << row[i] <<" ";
    }
    cout <<"\n" <<"Element at " <<n <<"th row and "<<r<<"th Column : " <<endl;
    cout <<nCr;

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