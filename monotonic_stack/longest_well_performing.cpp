#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int longestWPI(vector<int> &hours)
{
    int n = hours.size();
    vector<int> prefix(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        prefix[i] = prefix[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
    }

    // We want an optimal j - i from the range of [i,j)
    // So by fixing j and minimize i as much as possible , would contribute in optimal j - i;
    stack<int> st;

    // Create a strictly monotonic decreasing stack by the first case.
    for (int i = 0; i <= n; i++)
    {
        if (st.empty() or prefix[st.top()] > prefix[i])
        {
            cout << i << endl;
            st.push(i);
        }
    }
    // So by fixing i and maximize j as much as possible , would contribute in optimal j -i;

    int res = 0;
    for (int j = n; j >= 0; j--)
    {
        while (!st.empty() and prefix[st.top()] < prefix[j])
        {
            res = max(res, j - st.top());
            st.pop();
        }
    }
    return res;
}

int main()
{
    vector<int> hours = {9, 9, 6, 0, 6, 6, 9};
    cout << longestWPI(hours) << endl;
    return 0;
}

/*
 O(N) , O(N)
 Compute prefix sum of arr as prefixSum where prefixSum[i] = sum(arr[0], ... arr[i-1])
 for i > 0 and prefixSum[0] = 0.
 Iterate through prefixSum from begin to end and build a strictly monotone
 decreasing stack smdStack. (smdStack.top() is the smallest)
 Iterate through prefixSum from end to begin. For each prefixSum[i], while smdStack.top() is less than prefixSum[i] by at least K, pop smdStackand try
 to update result by subarray [index of top,i). Until top element is not less than it by K.
 Return result.
*/