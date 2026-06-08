class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stores indices
        int max_area = 0;
        
        for (int i = 0; i <= n; i++) {
            // Use 0 as a dummy height at the end (i == n) to flush out remaining bars in stack
            int current_height = (i == n) ? 0 : heights[i];
            
            // While current bar is shorter than the bar at stack top
            while (!st.empty() && heights[st.top()] > current_height) {
                int height = heights[st.top()]; // Height of the rectangle
                st.pop();
                
                // Calculate width
                int width;
                if (st.empty()) {
                    width = i; 
                } else {
                    width = i - st.top() - 1; 
                }
                
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        
        return max_area;
    }
};