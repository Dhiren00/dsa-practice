class Solution {
public:

    void getpermutation(vector<int>& nums, int index, vector<vector<int>>& ans)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);

            getpermutation(nums, index + 1, ans);

            swap(nums[index], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        getpermutation(nums, 0, ans);

        return ans;
    }
};