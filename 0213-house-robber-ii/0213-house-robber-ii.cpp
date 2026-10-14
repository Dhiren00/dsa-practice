
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> ans(n, 0);
        vector<int> ans1(n, 0);

        ans[0] = nums[0];
        ans[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            ans[i] = max(ans[i - 1], ans[i - 2] + nums[i]);
        }

        ans1[1] = nums[1];
        ans1[2] = max(nums[1], nums[2]);

        for (int i = 3; i < n; i++) {
            ans1[i] = max(ans1[i - 1], ans1[i - 2] + nums[i]);
        }

        return max(ans[n - 2], ans1[n - 1]);
    }
};
