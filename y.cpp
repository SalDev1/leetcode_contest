#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<char> st = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(string temp)
{
    bool ans = false;
    if (st.find(temp[0]) != st.end() and st.find(temp[temp.length() - 1]) != st.end())
    {
        ans = true;
    }
    return ans;
}

vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
{
    vector<int> res;
    vector<pair<string, bool>> temp;

    for (auto i : words)
    {
        if (isVowel(i))
        {
            temp.push_back({i, true});
        }
    }

    for (auto it : queries)
    {
        int i = it[0];
        int j = it[1];

        int count = 0;
        for (int k = i; k <= j; k++)
        {
            if (temp[k].second)
            {
                count++;
            }
        }
        res.push_back(count);
    }

    return res;
}

int main()
{
    vector<string> words = {"a", "e", "i"};
    vector<vector<int>> queries = {{0, 2}, {0, 1}, {2, 2}};

    auto p = vowelStrings(words, queries);

    for (auto i : p)
    {
        cout << i << endl;
    }

    return 0;
}