class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> m;
        queue<pair<char, int>> h;

        for (int i = 0; i < s.size(); i++) {

            if (m[s[i]] == 0) {
                h.push({s[i], i});
            }

            m[s[i]]++;

            while (!h.empty() && m[h.front().first] > 1) {
                h.pop();
            }
        }

        if (h.empty()) {
            return -1;
        } else {
            return h.front().second;
        }
    }
};