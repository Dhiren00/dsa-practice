class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int stc = 0, str = 0;
        int endr = m - 1, endc = n - 1;
        vector<int> ans;

        while (str <= endr && stc <= endc) {
            // Traverse top row
            for (int i = stc; i <= endc; i++)
                ans.push_back(matrix[str][i]);

            // Traverse right column
            for (int i = str + 1; i <= endr; i++)
                ans.push_back(matrix[i][endc]);

            // Traverse bottom row (if not same as top)
            if (str < endr) {
                for (int i = endc - 1; i >= stc; i--)
                    ans.push_back(matrix[endr][i]);
            }

            // Traverse left column (if not same as right)
            if (stc < endc) {
                for (int i = endr - 1; i > str; i--)
                    ans.push_back(matrix[i][stc]);
            }

            // Shrink boundaries
            stc++; str++;
            endc--; endr--;
        }

        return ans;
    }
};
