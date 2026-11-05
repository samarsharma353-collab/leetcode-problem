class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void solve(int i, int remaining, vector<int>& candidates) {
        
        if (remaining == 0) {
            ans.push_back(path);
            return;
        }

        if (remaining < 0 || i == candidates.size()) {
            return;
        }

        
        path.push_back(candidates[i]);
        solve(i, remaining - candidates[i], candidates);
        path.pop_back();

        
        solve(i + 1, remaining, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, target, candidates);
        return ans;
    }
};