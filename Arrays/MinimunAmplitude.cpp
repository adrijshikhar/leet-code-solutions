#include <bits/stdc++.h>
using namespace std;

/*
Given an Array A, find the minimum amplitude you can get after changing up to 3
elements. Amplitude is the range of the array (basically difference between
largest and smallest element).

Example 1:

Input: [-1, 3, -1, 8, 5 4]
Output: 2
Explanation: we can change -1, -1, 8 to 3, 4 or 5
Example 2:

Input: [10, 10, 3, 4, 10]
Output: 0
Explanation: change 3 and 4 to 10
*/

int minimunAmplitude(vector<int> &A) {
  sort(A.begin(), A.end());
  int start, end, n = A.size(), amp = A[n - 1] - A[0], k = 4, d;
  start = 3;
  end = n - 1;
  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  while (k--) {
    d = A[end] - A[start];
    amp = min(amp, d);
    start--;
    end--;
  }

  return amp;
}

int main() {
  vector<int> v1{
      1, 1, 3, 5, 8, 8,
  };
  int v2 = minimunAmplitude(v1);
  cout << v2 << " ";

  return 0;
}
