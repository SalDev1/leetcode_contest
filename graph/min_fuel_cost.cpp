#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long ans = 0, s = 0;
int dfs(int i, int prev, vector<vector<int>> &graph, int people = 1)
{
    for (int &x : graph[i])
    {
        if (x == prev)
            continue;
        people += dfs(x, i, graph);
    }
    if (i != 0)
    {
        ans += (people + s - 1) / s;
    }
    return people;
}

long long minimumFuelCost(vector<vector<int>> &roads, int seats)
{
    int n = roads.size();
    vector<vector<int>> g(n + 1);
    s = seats;

    for (vector<int> &r : roads)
    {
        g[r[0]].push_back({r[1]});
        g[r[1]].push_back({r[0]});
    }
    dfs(0, 0, g);
    return ans;
}

/*
  Intitution :-
  We track the number of people that reach each node and divide it by number of seats by each car ,
  this will tells us number of cars required to take us to that node closer to the 0.

  Suppose you are coming to the nearest node with a car of 5 seats.
  and there are three nodes where every node bring one car of 3 people.

  So , at the nearest node you have
  1 car of your own + 3 cars from those three child nodes.
  So , in total you have 10 people at the nearest node.

  The best possible way to reach 0 , taking 10 people is using
  2 cars of 5 seats , 10/5 ==> 2 cars to reach the captial 0.
*/

int main()
{
    vector<vector<int>> roads = {{0, 1}, {0, 2}, {0, 3}};
    int seats = 5;

    cout << minimumFuelCost(roads, seats) << endl;
    return 0;
}