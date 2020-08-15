#include <bits/stdc++.h>
using namespace std;

/*

Given an array consisting of n integers, find the contiguous subarray whose
length is greater than or equal to k that has the maximum average value. And you
need to output the maximum average value.

Example 1:
Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation:
when length is 5, maximum average value is 10.8,
when length is 6, maximum average value is 9.16667.
Thus return 12.75.
Note:
1 <= k <= n <= 10,000.
Elements of the given array will be in range [-10,000, 10,000].
The answer with the calculation error less than 10-5 will be accepted.
*/

bool canFind(vector<int> nums, int k, double target) {
  double leftSum = 0;
  double rightSum = 0;
  double minLeftSum = 0;

  for (int i = 1; i <= nums.size(); i++) {
    rightSum += nums[i - 1] - target;
    if (i >= k) {
      leftSum += i > k ? nums[i - k - 1] - target : 0;

      minLeftSum = min(leftSum, minLeftSum);

      if (rightSum - minLeftSum >= 0) {
        return true;
      }
    }
  }
  return false;
}

double maxAvgSubArray(vector<int> &A, int k) {
  if (A.size() == 0 || k <= 0 || k > A.size()) {
    return 0;
  }

  double lo = A[0];
  double hi = A[0];
  for (int i = 0; i < A.size(); i++) {
    lo = min(lo, (double)A[i]);
    hi = max(hi, (double)A[i]);
  }

  while (lo + 1e-5 < hi) {
    double mid = lo + (hi - lo) / 2;
    if (canFind(A, k, mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

int main() {
  vector<int> v1{
      1, 12, -5, -6, 50, 3,
  };
  int k = 4;
  double v2 = maxAvgSubArray(v1, k);
  cout << v2 << " ";

  return 0;
}
