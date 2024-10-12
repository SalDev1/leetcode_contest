#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
{
    int n = score.size();
    int m = score[0].size();
    vector<vector<int>> res;

    priority_queue<pair<int, vector<int>>> maxHeap;

    for (int i = 0; i < n; i++)
    {
        maxHeap.push({score[i][k], score[i]});
    }

    while (!maxHeap.empty())
    {
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }
    return res;
}

int main()
{
    vector<vector<int>> res = {{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}};
    int k = 2;

    auto p = sortTheStudents(res, k);

    for (auto i : p)
    {
        for (auto x : i)
        {
            cout << x << " ";
        }
        cout << endl;
    }

    string temp = "";
    return 0;
}