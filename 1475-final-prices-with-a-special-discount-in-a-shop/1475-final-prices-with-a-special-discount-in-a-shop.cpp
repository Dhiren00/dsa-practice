class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans = prices; // Initialize with original prices
        stack<int> st;            // Stack to store indices
        
        for (int i = 0; i < n; i++) {
            // While stack is not empty AND the current price is less than or equal 
            // to the price of the item at the top of the stack
            while (!st.empty() && prices[st.top()] >= prices[i]) {
                int index_to_discount = st.top();
                st.pop();
                
                // Apply the discount
                ans[index_to_discount] = prices[index_to_discount] - prices[i];
            }
            
            // Push the current index onto the stack to wait for its discount
            st.push(i);
        }
        
        return ans;
    }
};