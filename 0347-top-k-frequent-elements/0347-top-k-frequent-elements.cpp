class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        vector<int> ans;

        while(k > 0) {
            int m = 0;
            int ml = 0;

            for(auto x : mp) {
                if(x.second > m) {
                    ml = x.first;
                    m = x.second;
                }
            }

            ans.push_back(ml);
            mp[ml] = 0;

            k--;
        }

        return ans;
    }
};