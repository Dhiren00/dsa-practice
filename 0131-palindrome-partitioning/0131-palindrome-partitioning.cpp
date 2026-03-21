class Solution {
public:
    // Helper function to check if a string is a palindrome
    bool isPalin(string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    // Recursive function to generate all partitions
    void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans) {
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (isPalin(part)) {
                partitions.push_back(part);
                getAllParts(s.substr(i + 1), partitions, ans); // ✅ Correct name
                partitions.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(s, partitions, ans);
        return ans;
    }
};