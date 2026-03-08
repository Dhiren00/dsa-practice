class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        int count = 0;
        unordered_map<int,int> m;
        int sum = 0;

        // Build prefix sums
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            prefix[i] = sum;
        }

        // Count subarrays directly starting from index 0
        for(int i = 0; i < n; i++) {
            if(prefix[i] == k) {
                count++;
            }
        }

        // Use hashmap to count subarrays ending at i
        for(int i = 0; i < n; i++) {
            int need = prefix[i] - k;   // we want prefix[j] = prefix[i] - k
            if(m.find(need) != m.end()) {
                count += m[need];
            }
            m[prefix[i]]++;
        }

        return count;
    }
};
