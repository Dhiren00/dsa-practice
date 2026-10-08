class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(s.find(nums[i]) != s.end())
            {
                return true;
            }
            else
            {
                s.insert(nums[i]);
            }
        }

        return false;
    }
};