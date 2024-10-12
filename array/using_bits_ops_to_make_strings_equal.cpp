#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool makeStringsEqual_1(string s, string target)
{
    return (s.find("1") != string::npos) == (target.find("1") != string::npos);
}
/*
  Consider different possibilities , when it becomes true or false;

  Think of the impossible cases.

  Suppose s == 00 or 11
  Performing OR , XOR operation having different i , j  pointers won't effect
  the string / change the string.

  But if there is at least 1 in the string.
  s = 01 or 10
  we can change the string from  1 --> 0 or 0 --> 1 , depending on the cases.

  So idea is ,
  Look for the one in both the s and target string.
*/

bool makeStringsEqual(string s, string target)
{
    if (s == target)
        return true;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (auto &it : s)
    {
        if (it == '0')
            cnt0++;
        else
            cnt1++;
    }
    for (auto &it : target)
    {
        if (it == '0')
            cnt2++;
        else
            cnt3++;
    }

    if ((cnt0 && !cnt1) || (cnt2 && !cnt3))
        return false;
    return true;
}

int main()
{
    return 0;
}