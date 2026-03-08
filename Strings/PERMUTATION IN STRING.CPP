class Solution {
public:
    bool samefrequency(int frequency[], int windowfrequency[]) {
        for(int i = 0; i < 26; i++) {
            if(frequency[i] != windowfrequency[i])
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;

        int frequency[26] = {0};
        for(int i = 0; i < s1.length(); i++) {
            frequency[s1[i] - 'a']++;
        }

        for(int i = 0; i <= s2.length() - s1.length(); i++) {
            int windowfrequency[26] = {0};   // reset each window
            for(int j = 0; j < s1.length(); j++) {
                windowfrequency[s2[i + j] - 'a']++;
            }

            if(samefrequency(frequency, windowfrequency))
                return true;
        }

        return false;
    }
};
