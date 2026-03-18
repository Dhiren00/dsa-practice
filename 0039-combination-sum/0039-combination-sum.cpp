class Solution {
public:

void backtracking(vector<int>& candidates, int i, int target,
                  vector<int>& ans, vector<vector<int>>& ans1)
{
    if(target == 0)
    {
        ans1.push_back(ans);
        return;
    }

    if(target < 0 || i == candidates.size())
        return;

    // include (same index because reuse allowed)
    ans.push_back(candidates[i]);
    backtracking(candidates, i, target - candidates[i], ans, ans1);

    // backtrack
    ans.pop_back();

    // exclude
    backtracking(candidates, i + 1, target, ans, ans1);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int> ans;
    vector<vector<int>> ans1;

    backtracking(candidates, 0, target, ans, ans1);

    return ans1;
}
};