#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> finalPrices(vector<int> &prices)
{
    int n = prices.size();
    vector<int> ans(n, 0);
    stack<int> st;
    for (int i = 0; i < prices.size(); i++)
    {
        while (!st.empty() and prices[st.top()] >= prices[i])
        {
            ans[st.top()] = prices[st.top()] - prices[i];
            st.pop();
        }
        st.push(i);
        if (!st.empty())
        {
            ans[i] = prices[st.top()];
        }
    }
    return ans;
}

int main()
{
    vector<int> res = {8, 4, 6, 2, 3};
    auto p = finalPrices(res);

    for (auto i : p)
    {
        cout << i << " ";
    }
    return 0;
}

/*
Intitution :-
A simple example of monotonic increasing stack.

Input: prices = [8,4,6,2,3]
Output: [4,2,4,2,3]
Explanation:
For item 0 with price[0]=8 you will receive a discount equivalent to prices[1]=4, therefore, the final price you will pay is 8 - 4 = 4.
For item 1 with price[1]=4 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 4 - 2 = 2.
For item 2 with price[2]=6 you will receive a discount equivalent to prices[3]=2, therefore, the final price you will pay is 6 - 2 = 4.
For items 3 and 4 you will not receive any discount at all.
*/
