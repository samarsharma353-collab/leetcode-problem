class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, vector<int>& nums, int target,
               vector<int>& curr, int sum) {

        if (sum == target) {
            ans.push_back(curr);
            return;
        }

        if (sum > target || i >= nums.size()) {
            return;
        }

        // Pick
        curr.push_back(nums[i]);
        solve(i + 1, nums, target, curr, sum + nums[i]);
        curr.pop_back();

        // Not Pick (skip duplicates)
        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) {
            j++;
        }

        solve(j, nums, target, curr, sum);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> curr;
        solve(0, candidates, target, curr, 0);

        return ans;
    }
};