class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        
        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                int l = st.top();
                st.pop();
                
                // FIX: Calculate the distance between days, not the temperature difference
                int li = i - l; 
                ans[l] = li;
            }
            st.push(i);
        }
        return ans;
    }
};