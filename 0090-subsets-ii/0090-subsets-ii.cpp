class Solution {
public:

void allsubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& subsets)
{
    if(i == nums.size())
    {
        subsets.push_back(ans);
        return;
    }

    // include element
    ans.push_back(nums[i]);
    allsubsets(nums, ans, i+1, subsets);

    // backtrack
    ans.pop_back();

    int index = i + 1;

    // skip duplicates
    while(index < nums.size() && nums[index] == nums[index-1])
    {
        index++;
    }

    // exclude
    allsubsets(nums, ans, index, subsets);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {

    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    vector<int> ans;

    allsubsets(nums, ans, 0, result);

    return result;
}
};