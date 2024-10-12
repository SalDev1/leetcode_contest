#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool static comp(pair<int, char> p1, pair<int, char> p2)
{
    return p1.first > p2.first;
}

string frequencySort(string s)
{
    unordered_map<char, int> mp;
    string temp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }

    vector<pair<int, char>> p;
    for (auto it : mp)
    {
        p.push_back({it.second, it.first});
    }

    sort(p.begin(), p.end(), comp);

    for (int i = 0; i < p.size(); i++)
    {
        while (p[i].first > 0)
        {
            temp += p[i].second;
            p[i].first--;
        }
    }
    return temp;
}

string frequencySort_2(string s)
{
    unordered_map<char, int> freq;           // for frequency of characters
    priority_queue<pair<int, char>> maxheap; // maxheap according to frequency of characters
    for (char c : s)
        freq[c]++;
    for (auto it : freq)
        maxheap.push({it.second, it.first}); // heap will be constructed on the basis of frequency
    s = "";
    while (!maxheap.empty())
    {
        s += string(maxheap.top().first, maxheap.top().second); // frequency times the character
        maxheap.pop();
    }
    return s;
}

int main()
{
    string s = "raaeaedere";

    cout << frequencySort(s) << endl;
    return 0;
}