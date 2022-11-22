#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Find all the perfect square uptil n;
int numSquares(int n)
{
    if (n <= 0)
    {
        return n;
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;

    // For every ith value , find least perfect squares
    // that e
    // O(n*sqrt(n)) , O(N).
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    return dp[n];
}

int main()
{
    int n = 12;
    cout << numSquares(n) << endl;
    return 0;
}

/*
   Very similar to the problem of (Coin Change).
   The basic idea is the same , for every ith value , find the least no of perfect squares
   that sums up to the value of n.
*/