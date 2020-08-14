#include <bits/stdc++.h>

using namespace std;
int uniqueSplitStrings(string A) {
  unordered_map<int, int> mp1, mp2;
  int n = A.size(), ans = 0;
  for (int i = 0; i < n; i++) {
    mp2[A[i]]++;
  }
  for (int i = 0; i < n; i++) {
    mp1[A[i]]++;
    mp2[A[i]]--;
    if (mp2[A[i]] == 0)
      mp2.erase(A[i]);
    if (mp1.size() == mp2.size())
      ans++;
  }

  return ans;
}

int main() {
  string v1 = "ababa";
  int v2 = uniqueSplitStrings(v1);
  cout << v2 << " ";

  return 0;
}
