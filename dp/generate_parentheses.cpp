#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// O(2^{2n} * n) , O(2^(2n) * n)
void solve(int n, int op, int cl, vector<string> &res, string temp)
{
    if (op == n and cl == n)
    {
        res.push_back(temp);
    }
    if (op < n)
    {
        solve(n, op + 1, cl, res, temp + "(");
    }
    if (cl < op)
    {
        solve(n, op, cl + 1, res, temp + ")");
    }
}

vector<string> generateParenthesis(int n)
{
    int limit = n;
    vector<string> result;
    solve(n, 0, 0, result, "");
    return result;
}

int main()
{
    int n = 2;
    auto p = generateParenthesis(n);
    for (auto i : p)
    {
        cout << i << " ";
    }
    return 0;
}
