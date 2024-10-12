#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int findJudge(int n, vector<vector<int>> &trust)
{
    int m = trust.size();
    unordered_map<int, vector<int>> mp;

    for (int i = 1; i <= n; i++)
    {
        mp[i] = {};
    }

    for (int i = 0; i <= m; i++)
    {
        mp[trust[i][0]].push_back({trust[i][1]});
    }

    int judge = 0;
    for (auto it : mp)
    {
        if (it.second.size() == 0)
        {
            judge = it.first;
        }
        else
        {
            judge = 0;
        }
    }
    return judge;
}

int main()
{
    int n = 3;
    vector<vector<int>> res = {{1, 3}, {2, 3}, {3, 1}};

    cout << findJudge(n, res) << endl;
    return 0;
}