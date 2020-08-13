#include <bits/stdc++.h>

using namespace std;
int wiggleSort(vector<int> &flowers, int k) {
  int n = flowers.size(), j = 0, f = 0, ans = INT_MAX;

  vector<int> days(n + 1, 0);
  for (int i = 0; i < n; i++)
    days[flowers[i]] = i + 1;

  for (int i = 1; i <= n - k - 1; i++) {
    j = i;
    while (j <= i + k + 1) {
      if (days[i] < days[j] && days[j] < days[i + k + 1]) {
        f = 1;
        break;
      }
      j++;
    }
    if (f == 0)
      ans = min(ans, days[i + k + 1]);
  }
  return ans == INT_MAX ? -1 : ans;
}

int main() {
  vector<int> v1{
      1, 6, 3, 4, 5, 2,
  };
  int k = 1;
  int v2 = wiggleSort(v1, k);
  cout << v2 << " ";

  return 0;
}
