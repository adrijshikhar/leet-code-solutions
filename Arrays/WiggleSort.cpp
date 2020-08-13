#include <bits/stdc++.h>

using namespace std;
vector<int> wiggleSort(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) {
    if ((i % 2 == 0) == (nums[i] > nums[i + 1])) {
      swap(nums[i], nums[i + 1]);
    }
  }
  return nums;
}

int main() {
  vector<int> v1{
      3, 5, 2, 1, 6, 4, 7, 8,
  };
  vector<int> v2 = wiggleSort(v1);
  for (int i = 0; i < v2.size(); i++) {
    cout << v2[i] << " ";
  }

  return 0;
}
