class Solution {
public:
    
    bool binarysearch(vector<vector<int>>& matrix, int target, int l, int n)
    {
        int row = 0;
        int col = n - 1;

        while(row < l && col >= 0)
        {
            if(target == matrix[row][col])
            {
                return true;
            }

            if(target < matrix[row][col])
            {
                col--;
            }
            else
            {
                row++;
            }
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size();
        int l = matrix[0].size();

        return binarysearch(matrix, target, n, l);
    }
};