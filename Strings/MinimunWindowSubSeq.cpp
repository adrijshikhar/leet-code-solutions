#include <bits/stdc++.h>

using namespace std;
string mws(string A, string B) {
  string ans;
  int m = B.size(), n = A.size();
  vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

  for (int i = 0; i <= n; i++)
    dp[0][i] = true;

  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] =
          B[i - 1] == A[j - 1] ? true : (dp[i - 1][j - 1] && dp[i][j - 1]);
    }
  }

  int i = m, j;

  for (j = n; j >= 1; j--)
    if (dp[i][j] != dp[i][j - 1])
      break;

  for (; j >= 1, i > 0; j--) {
    if (dp[i][j] != dp[i][j - 1])
      i--;

    ans += A[j - 1];
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  string v1 = "abcdebdde";
  string v3 = "bded";
  string v2 = mws(v1, v3);
  cout << v2 << " ";

  return 0;
}
