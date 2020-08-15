#include <bits/stdc++.h>
using namespace std;

/*
Write  a function that returns a largest contiguous subarray of length k from
all contiguous subarrays of length k
*/

vector<int> maxAvgSubArray(vector<int> &A, int m) {
  int l = 1, j = 0, n = A.size(), k = 0;
  vector<int> ans;

  while (l + m - 1 < n) {
    if (A[j] < A[l])
      j = l;
    else if (A[j] == A[l]) {
      k = j;
      for (int i = l; i < l + m; i++) {
        if (A[k] < A[l]) {
          j = l;
          break;
        }
        k++;
      }
    }
    l++;
  }
  for (int i = j; i < j + m; i++)
    ans.push_back(A[i]);

  return ans;
}

int main() {
  vector<int> v1{
      7, 1, 8, 6, 7, 3, 2,
  };
  int k = 3;
  vector<int> v2 = maxAvgSubArray(v1, k);
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
