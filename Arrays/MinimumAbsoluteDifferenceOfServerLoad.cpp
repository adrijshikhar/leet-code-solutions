#include <bits/stdc++.h>
using namespace std;

/*
There are some processes that need to be executed. Amount of a load that process
causes on a server that runs it, is being represented by a single integer. Total
load caused on a server is the sum of the loads of all the processes that run on
that server. You have at your disposal two servers, on which mentioned processes
can be run. Your goal is to distribute given processes between those two servers
in the way that, absolute difference of their loads will be minimized.

Given an array of n integers, of which represents loads caused by successive
processes, return the minimum absolute difference of server loads.

Example 1:

Input: [1, 2, 3, 4, 5]
Output: 1
Explanation:
We can distribute the processes with loads [1, 2, 4] to the first server and [3,
5] to the second one, so that their total loads will be 7 and 8, respectively,
and the difference of their loads will be equal to 1.
*/

int minAbsload(vector<int> &A) {
  sort(A.begin(), A.end());
  int ans, s1 = 0, s2 = 0, n = A.size(), d1, d2;
  s1 = A[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    d1 = abs(s1 + A[i] - s2);
    d2 = abs(s1 - A[i] - s2);
    if (d1 < d2)
      s1 += A[i];
    else
      s2 += A[i];
  }
  ans = abs(s1 - s2);
  return ans;
}

int main() {
  vector<int> v1{1, 2, 3, 4, 6};
  int v2 = minAbsload(v1);
  cout << v2 << " ";

  return 0;
}
