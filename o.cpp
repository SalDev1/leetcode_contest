#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> ans;
    vector<vector<int>> adjList(n + 1);

    // Create an adjancency list.
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j : graph[i])
        {
            adjList[i].push_back(j);
        }
    }

    vector<int> outdegree(n + 1, 0);

    for (int i = 0; i < adjList.size(); i++)
    {
        for (int j : adjList[i])
        {
            outdegree[j]++;
        }
    }

    queue<int> q;
    q.push(0);

    int i = 0;
    while (i < n and !q.empty())
    {
        auto curr = q.front();
        q.pop();

        for (auto nbr : adjList[curr])
        {
            if (outdegree[nbr] == 0)
            {
                ans.push_back(curr);
                ans.push_back(nbr);
            }
        }
        i++;
        q.push(i);
    }

    return ans;
}

int main()
{
    string st = "abc";

    cout << st.substr(0, 3) << endl;
    return 0;
}