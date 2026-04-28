class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> x(n);
        vector<int> y(n);
        
        int i = 0;

        for(; i < n; i++)
        {
            x[i] = nums[i];
        }

        for(i = n; i < 2*n; i++)
        {
            y[i-n] = nums[i];
        }

        vector<int> ans(2*n);
  
        for(int f = 0, l = 0, j = 1; f < n; j += 2, l += 2, f++)
        {
            ans[l] = x[f];
            ans[j] = y[f];
        }

        return ans;
    }
};