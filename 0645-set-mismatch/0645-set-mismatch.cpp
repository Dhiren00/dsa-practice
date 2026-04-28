class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int duplicate = -1, missing = -1;

        sort(nums.begin(), nums.end());

        // Find duplicate via adjacent comparison
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                duplicate = nums[i];
                break;
            }
        }

        // Find missing by checking which number in [1..n] is absent
        for (int i = 1; i <= n; i++) {
            // binary search since array is sorted
            if (!binary_search(nums.begin(), nums.end(), i)) {
                missing = i;
                break;
            }
        }

        return {duplicate, missing};
    }
};