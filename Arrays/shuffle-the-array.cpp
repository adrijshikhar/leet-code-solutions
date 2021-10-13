class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int temp = n;
        vector<int> res;
        for(int i=0;i<n;i++) {
            res.push_back(nums[i]);
            res.push_back(nums[temp]);
            temp++;
        }
        return res;
    }
};
