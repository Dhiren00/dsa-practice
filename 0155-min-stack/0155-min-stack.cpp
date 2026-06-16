class MinStack {
public:
    // Storing {current_value, minimum_so_far}
    stack<pair<int, int>> st;
     
    MinStack() {
        // No need to redeclare 'st' here; it is already initialized.
    }
    
    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } 
        else { 
            // Added the missing dot: st.top().second
            if (value < st.top().second) {
                st.push({value, value});
            } 
            else {
                st.push({value, st.top().second});
            }
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop();
        }
    }
    
    int top() {
        // Return just the actual value (the first element of the pair)
        return st.top().first;
    }
    
    int getMin() {
        // Return the minimum up to this point (the second element of the pair)
        return st.top().second;
    }
};