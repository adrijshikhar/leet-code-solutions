/*
A 2d grid map of m rows and n columns is initially filled with water. We may
perform an addLand operation which turns the water at position (row, col) into a
land. Given a list of positions to operate, count the number of islands after
each addLand operation. An island is surrounded by water and is formed by
connecting adjacent lands horizontally or vertically. You may assume all four
edges of the grid are all surrounded by water.

Example:

Given m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]].
Initially, the 2d grid grid is filled with water. (Assume 0 represents water and
1 represents land).

0 0 0
0 0 0
0 0 0
Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.

1 0 0
0 0 0   Number of islands = 1
0 0 0
Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.

1 1 0
0 0 0   Number of islands = 1
0 0 0
Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.

1 1 0
0 0 1   Number of islands = 2
0 0 0
Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.

1 1 0
0 0 1   Number of islands = 3
0 1 0
We return the result as an array: [1, 1, 2, 3]

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> noi(int m, int n, vector<vector<int>> &islands) {
  vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < islands.size(); i++) {
    dp[islands[i][0] + 1][islands[i][1] + 1] = 1;
  }

  int ic = 0;
  vector<int> ans;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (dp[i][j] == 1) {

        if (!dp[i - 1][j] && !dp[i][j - 1])
          ic++;
        ans.push_back(ic);
      }
    }
  }

  return ans;
}

int main(int argc, char const *argv[]) {
  int m = 3, n = 3;
  vector<vector<int>> i{
      {0, 0},
      {0, 1},
      {1, 2},
      {2, 1},
  };
  vector<int> v = noi(m, n, i);
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }

  return 0;
}
