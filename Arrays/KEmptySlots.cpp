#include <bits/stdc++.h>
using namespace std;

/*
There is a garden with N slots. In each slot, there is a flower. The N flowers
will bloom one by one in N days. In each day, there will be exactly one flower
blooming and it will be in the status of blooming since then.

Given an array flowers consists of number from 1 to N. Each number in the array
represents the place where the flower will open in that day.

For example, flowers[i] = x means that the unique flower that blooms at day i
will be at position x, where i and x will be in the range from 1 to N.

Also given an integer k, you need to output in which day there exists two
flowers in the status of blooming, and also the number of flowers between them
is k and these flowers are not blooming.

If there isn't such day, output -1.

Example 1:
Input:
flowers: [1,3,2]
k: 1
Output: 2
Explanation: In the second day, the first and the third flower have become
blooming. Example 2: Input: flowers: [1,2,3] k: 1 Output: -1
*/

int kEmptySlots(vector<int> &flowers, int k) {
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
  int v2 = kEmptySlots(v1, k);
  cout << v2 << " ";

  return 0;
}
