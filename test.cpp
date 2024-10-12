#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> ans, int k)
{
    if (ans.size() == 1)
    {
        return true;
    }
    for (int i = 1; i < ans.size(); i++)
    {
        int diff = abs(ans[i - 1] - ans[i]);
        if (diff == k)
        {
            return false;
        }
    }
    return true;
}

void solve(int i, vector<vector<int>> &res, vector<int> nums, int k, vector<int> &ans)
{
    if (i == nums.size())
    {
        if (check(ans, k))
        {
            res.push_back(ans);
        }
        return;
    }
    // If you pick up the element.
    ans.push_back(nums[i]);
    solve(i + 1, res, nums, k, ans);
    ans.pop_back();

    // If you don't pick up the element.
    solve(i + 1, res, nums, k, ans);
}

int beautifulSubsets(vector<int> &nums, int k)
{
    vector<vector<int>> res;
    vector<int> ans;
    solve(0, res, nums, k, ans);

    return res.size() - 1;
}

int main()
{
    vector<int> nums = {2, 4, 6};
    int k = 2;

    cout << beautifulSubsets(nums, k) << endl;
}
/*
"86217457695827338571"
8
*/
