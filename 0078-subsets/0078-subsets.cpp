class Solution {
public:
    vector<int> curr;
    vector<vector<int>> res;

    void solve(vector<int>& nums, int i) {
        if (i == nums.size()) {
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(nums, i + 1);
        curr.pop_back();

       
        solve(nums, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums, 0);
        return res;
    }
};