class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> arr;
        int j = 0; // pointer for target
        
        for(int i = 1; i <= n; i++)
        {
            if(j < target.size() && target[j] == i)
            {
                arr.push_back("Push");
                j++;
            }
            else
            {
                arr.push_back("Push");
                arr.push_back("Pop");
            }
            
            if(j == target.size()) break; // stop early
        }
        
        return arr;
    }
};