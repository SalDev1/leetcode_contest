#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorderTraversal(TreeNode *root, vector<int> &nums)
{
    if (root != NULL)
    {
        inorderTraversal(root->left, nums);
        nums.push_back(root->val);
        inorderTraversal(root->right, nums);
    }
}

int findMin(vector<int> &nums, int q)
{
    int l = 0;
    int r = nums.size() - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // needed the largest min value , so try to check the right side.
        if (q >= nums[mid])
        {
            if (nums[mid] == q)
            {
                return q;
            }
            ans = nums[mid];
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

int findMax(vector<int> &nums, int q)
{
    int l = 0;
    int r = nums.size() - 1;
    int ans = -1;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        // needed the smallest max value , try to check in the left.
        if (q <= nums[mid])
        {
            if (nums[mid] == q)
            {
                return q;
            }
            ans = nums[mid];
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}
vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
{
    vector<int> nums;
    inorderTraversal(root, nums);
    int n = queries.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int min_value = findMin(nums, queries[i]);
        int max_value = findMax(nums, queries[i]);
        ans.push_back({min_value, max_value});
    }
    return ans;
}

// O(NlogN) + O(N) , O(N) + O(N)
/*
  Sort all the nodes and store them in the temp array to find min and max for the given
  query.
  As it is a binary search tree , applying binary search to find the min and max of the given
  query would be helpful.

  Refer the problem.
  https://leetcode.com/problems/closest-nodes-queries-in-a-binary-search-tree/
*/