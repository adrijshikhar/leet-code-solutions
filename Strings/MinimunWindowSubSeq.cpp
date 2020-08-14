#include <bits/stdc++.h>
using namespace std;

/*
Given strings S and T, find the minimum (contiguous) substring W of S, so that T
is a subsequence of W.

If there is no such window in S that covers all characters in T, return the
empty string "". If there are multiple such minimum-length windows, return the
one with the left-most starting index.

Example 1:
Input:
S = "abcdebdde", T = "bde"
Output: "bcde"
Explanation:
"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur
in order.
*/

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
