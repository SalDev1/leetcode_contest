#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    vector<int> minPrev(n, -1); // NSE from the left;
    vector<int> minNext(n, n);  // NSE from the right;
    vector<int> maxPrev(n, -1); // NGE from the left;
    vector<int> maxNext(n, n);  // NGE from the right;

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            minPrev[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and nums[st.top()] > nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            minNext[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() and nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            maxPrev[i] = st.top();
        }
        st.push(i);
    }

    while (!st.empty())
    {
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() and nums[st.top()] < nums[i])
        {
            st.pop();
        }
        if (!st.empty())
        {
            maxNext[i] = st.top();
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << minPrev[i] << minNext[i] << maxPrev[i] << maxNext[i] << endl;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long leftMin = i - minPrev[i], rightMin = minNext[i] - i;
        long long leftMax = i - maxPrev[i], rightMax = maxNext[i] - i;
        long long prod = (leftMax * rightMax - leftMin * rightMin) * nums[i];
        sum += prod;
    }
    return sum;
}

int main()
{
    vector<int> res = {1, 2, 3};

    cout << subArrayRanges(res) << endl;
    return 0;
}

/*
  Similar to what we do the sum_of_subarr_mins.

  For every element , we consider them as the min_element and try to find the count of
  subarrays where the curr ith element is the min element.

  For every ith element ,
  Find the NGE from the left and right.
  Find the NSE from the left and right.
  With the same method, we can also find the sum of the maximum element of all subarrays.

  The solution for this problem can be formulated as sum(max(b)) - sum(min(b)),
  where b ranges over every (contiguous) subarray of n.
*/