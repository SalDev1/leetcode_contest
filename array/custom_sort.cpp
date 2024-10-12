#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Leetcode Question 2545, using custom sort to solve the problem.
vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
{
    sort(begin(score), end(score), [&](const auto &s1, const auto &s2)
         { return s1[k] > s2[k]; });
    return score;
}

int main()
{
    return 0;
}