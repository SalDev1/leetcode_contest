#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
   Consider this problem to be the **combinations with repetitions**.

   Rephrase the problem:-
   Given an integer n, return the count of numbers of length n that consists only of
   digits 1 to 5 and all digits are non-decreasing.

   For example, given n = 2,
   we need to count: 11, 12, 13, 14, 15, 22, 23, 24, 25, 33, 34, 35, 44, 45, 55.

   In particular , we need to choose n digits from the pool of 5 digits with repetitions.
   Why combinations, but not permutations? Because the number needs to be sorted (the digits should be non-decreasing),
   so we need to only count "112", but not "121", "211".

   The easiest way to calculate the number of combinations with repetitions
   (n+m-1)!//(n!)((m-1)!) and apply n = 5 to it.
*/
int main()
{
    int n = 2;
    // cout << countVowelStrings(n) << endl;
    return 0;
}