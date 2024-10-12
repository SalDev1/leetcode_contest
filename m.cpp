#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
{
    vector<vector<int>> res;
    unordered_map<int, vector<int>> mp;
    for (auto i : items1)
    {
        mp[i[0]] = {i[0], i[1]};
    }
    for (auto j : items2)
    {
        if (mp.find(j[0]) != mp.end())
        {
            mp[j[0]] = {j[0], j[1] + mp[j[0]][1]};
        }
    }
    for (auto it : mp)
    {
        res.push_back(it.second);
    }

    return res;
}

int main()
{
    set<int> st;

    st.insert(10);
    st.insert(5);
    st.insert(9);

    for (int it : st)
    {
        cout << it << " ";
    }
    return 0;
}