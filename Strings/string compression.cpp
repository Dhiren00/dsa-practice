class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;

        for (int i = 0; i < n; i++) {
            char current = chars[i];
            int count = 0;

            while (i < n && chars[i] == current) {
                count++;
                i++;
            }

            chars[index++] = current;

            if (count > 1) {
                string str = to_string(count);
                for (char dig : str) {
                    chars[index++] = dig;
                }
            }

            i--; // adjust because for-loop will increment i
        }

        return index;
    }
};
