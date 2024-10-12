#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(string temp)
{
    for (char ch : temp)
    {
        if (!isalpha(ch) or !isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

bool allNum(string temp)
{
    for (char ch : temp)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

int maximumValue(vector<string> &strs)
{
    int n = strs.size();
    int max_val = 0;

    for (int i = 0; i < n; i++)
    {
        string curr = strs[i];
        if (check(curr))
        {
            int sz = curr.length();
            max_val = max(max_val, sz);
        }
        else if (allNum(curr))
        {
            int num = stoi(curr);
            max_val = max(max_val, num);
        }
    }

    return max_val;
}

int main()
{
    int n = 39;

    int a = 7 / 2;
    cout << a << endl;

    int b = stoi("0001");
    cout << b << endl;

    return 0;
}
