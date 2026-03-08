class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;   // lowest price seen so far
        int maxProfit = 0;        // best profit so far

        for (int price : prices) {
            minPrice = min(minPrice, price);          // update minimum
            maxProfit = max(maxProfit, price - minPrice); // check profit
        }

        return maxProfit;
    }
};
