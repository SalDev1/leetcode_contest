#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Recursive :- O(2^N) , O(N)
int solve_recur(int i, int j, int n, vector<vector<int>> triangle)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    int bottom = triangle[i][j] + solve_recur(i + 1, j, n, triangle);
    int bottom_right = triangle[i][j] + solve_recur(i + 1, j + 1, n, triangle);
    return min(bottom, bottom_right);
}

// Memoization :- O(N^2) , O(N^2)
int solve_td(int i, int j, int n, vector<vector<int>> triangle, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int bottom = triangle[i][j] + solve_td(i + 1, j, n, triangle, dp);
    int bottom_right = triangle[i][j] + solve_td(i + 1, j + 1, n, triangle, dp);

    return dp[i][j] = min(bottom, bottom_right);
}

// Tabulation method :- O(N^2) , O(N^2)
int solve_bp(vector<vector<int>> triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int up = dp[i + 1][j] + triangle[i][j];
            int down = dp[i + 1][j + 1] + triangle[i][j];
            dp[i][j] = min(up, down);
        }
    }
    return dp[0][0];
}

// Space Optimized Approach:-
// As we require the information about the next row , why don;t
//  we use the 1D array.
int solve_op(vector<vector<int>> triangle)
{
    int n = triangle.size();
    vector<int> next(triangle[n - 1]);
    vector<int> curr(n, 0);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int up = triangle[i][j] + next[j];
            int down = triangle[i][j] + next[j + 1];
            curr[j] = min(up, down);
        }
        next = curr;
    }
    return next[0];
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = triangle.size();
    int m = triangle[1].size();

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    cout << solve_recur(0, 0, n, triangle) << endl;
    cout << solve_td(0, 0, n, triangle, dp) << endl;
    cout << solve_bp(triangle) << endl;
    cout << solve_op(triangle) << endl;

    return 0;
}

/*
   The idea behind this is very simple , read the question properly and you will be
   able to get the intutition behind , always try to solve in pen and paper and start
   with a recursive approach.
*/