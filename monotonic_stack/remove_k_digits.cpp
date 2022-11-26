#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k)
{
    int n = num.size();

    if (num.size() <= k)
        return "0";

    if (k == 0)
        return num;

    string ans = "";
    stack<char> st;

    st.push(num[0]);

    for (int i = 1; i < num.size(); i++)
    {

        while (k > 0 and !st.empty() and st.top() >= num[i])
        {
            st.pop();
            k--;
        }

        st.push(num[i]);

        // Popping preceding zeros.
        if (st.size() == 1 and num[i] == '0')
            st.pop();
    }

    /*
      For handling cases such as.
      eg:- 1111111 and k = 3 or 456 , k = 1;
    */
    while (k and !st.empty())
    {
        k--;
        st.pop();
    }

    // Form the string.
    while (!st.empty())
    {
        ans = ans + st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    if (ans.size() == 0)
    {
        return "0";
    }
    return ans;
}

int main()
{
    string num = "10";
    int k = 1;
    cout << removeKdigits(num, k) << endl;

    // bool ans = '1' < '4';
    // cout << ans << endl;
    return 0;
}

/*
  Simple Idea :- Using monotonic increasing stack.
  And handling edge cases.
*/