#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

// Brute Force Approach.
// O(N^2) , O(N).
int sumSubarray(vector<int> nums)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        int min_sub = INT_MAX;
        for (int j = i; j < nums.size(); j++)
        {
            min_sub = min(min_sub, nums[j]);
            res.push_back(min_sub);
        }
    }

    int sum = 0;
    return accumulate(res.begin(), res.end(), sum);
}

int sumSubarray_2(vector<int> arr)
{
    int n = arr.size();
    int MOD = 1e9 + 7;

    vector<int> left(n);
    vector<int> right(n);

    stack<int> st;
    left[0] = 1;

    st.push(0);
    for (int i = 1; i < n; i++)
    {
        while (!st.empty() and arr[st.top()] > arr[i])
        {
            st.pop();
        }

        if (st.empty())
        {
            left[i] = i + 1;
        }
        else
        {
            left[i] = i - st.top();
        }
        st.push(i);
    }

    while (st.size())
    {
        st.pop();
    }
    st.push(n - 1);
    right[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        while (!st.empty() and arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            right[i] = n - i;
        }
        else
        {
            right[i] = st.top() - i;
        }
        st.push(i);
    }
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        cout << left[i] << ":" << right[i] << endl;
    }

    // Contibution of each element would be a[i] * left[i] * right;
    for (int i = 0; i < n; i++)
    {
        long long prod = (left[i] * right[i]) % MOD;
        prod = (prod * arr[i]) % MOD;
        res = (res + prod) % MOD;
    }
    return (int)res % MOD;
}

int main()
{
    vector<int> nums = {3, 1, 2, 4};

    cout << sumSubarray(nums) << endl;
    cout << sumSubarray_2(nums) << endl;
    return 0;
}

/*
   Opitmized Approach:-
   In the brute force approach , we are focusin in the range first.
   Once we have a range , we look for the minimum element in the range.

   Generating ranges is time-consuming.

   What if instead of finding a range of a subarray and then checking
   for the min element.

  What if we selected the curr_element as min element and find out the count
  of the subarrays having this curr_element as the min element.

  Eg:-
  You have {0,3,4,5,2,3,4,1,4};
  You selected 2 from it as min element and the range you could find is
  from [1,6] , where in this range you will get all the subarrays have min
  element 2 ==> {3,4,5,2,3,4} ==> 12 subarrays are been generated in this
  range where the min element is 2.

  Now the problem is :-
  ***In the given range , find the count of subarrays which
  contain selected min element.
    element * count of subarrays where it is smallest.
  **.
  Monotonic stacks are used to calculate previous smaller elements and
  the next smaller element in linear time complexity.

  If we want to know next and previous larger elements , we
  can use a montonically decreasing stack.

  The reverse of this in monotonically increasing stack , which we
  will be needing.

  Montonially Increasing Stack.
  if the item at the top of the stack >= current item.
  We pop it off and push the curr element as the top element.

  As a new item gets added to the stack, older items are
  removed from the top if they are bigger.
  In other words, the items that are getting popped must be
  greater than or equal to the incoming element.
  We can also say that the incoming element must be the next smaller element
  of the item going off the stack.

  If the stack is not empty , the new stack top would contain
  the previous smaller item.
  Stack guarantees that the previous element has to be the previous smaller
  element.

  Previous smallest element ==> will always check for the element in stack.top ,if stack is not empty.
  Next smaller element ==> The incoming element which made the curr st.top() to be removed from the stack.
  by condition st.top() > nums[j].

  We have to make sure we consider strictly smaller elements on the left (previous smaller).
  At the same time , we consider smaller and equal elements on the right.
  This helps in ensuring that none of the ranges are counted twice when making
  calculations.

  Steps:-
  1] Solve it using brute force method.
  2] Now considering every element as the min element and find out the count
  of the subarrays where min element is present ,
  in which knowing the range is very important.
  Contribution to every element :- element * count of subarrays where it is smallest.
  3] For finding the range where each element is min element ,
  find the nearest smallest left and closest smallest element on the
  right less than itself.

  4] We use monotonic stack to find the range of every min element.
  5] For this we need to get two things for every min element:-
  ***Next smallest element to the left :-
  If yes , find the distance between A[i] and its NSE. i - st.top();
  If not , store i + 1 if no NSE on the left.

  ***Next smallest element to the right :-
  If yes , find the distance between A[i] and its NSE. ==> st.top() - i;
  If not , store n - i , if no NSE found on the right.

  Storing left[i] and right[i] , considering every element
  as the min element we actually get the count of all subarrays
  where is min element is present.
*/