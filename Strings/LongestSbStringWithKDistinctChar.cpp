#include <bits/stdc++.h>
using namespace std;
/*

Given a string, find the length of the longest substring T that contains at most
k distinct characters.
For example, Given s = “eceba” and k = 2,
T is "ece" which its length is 3.

*/
string lrsswk(string A, int k) {
  unordered_map<int, int> mp;
  string ans;
  int left = 0, right = 0, n = A.size();
  while (right < n) {
    mp[A[right]]++;
    while (k < mp.size()) {
      mp[A[left]]--;
      if (mp[A[left]] == 0)
        mp.erase(A[left]);
      left++;
    }

    right++;
  }
  for (int i = left; i <= right; i++) {
    ans += A[i];
  }
  return ans;
}

int main() {
  string v1 = "asda";
  int k = 3;
  string v2 = lrsswk(v1, k);
  cout << v2 << " ";

  return 0;
}
