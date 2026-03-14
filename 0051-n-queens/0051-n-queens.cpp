class Solution {
public:

bool issafe(vector<string> &board,int row,int column,int n)
{
    // check row
    for(int i=0;i<n;i++)
    {
        if(board[row][i]=='Q')
        return false;
    }

    // check column
    for(int i=0;i<n;i++)
    {
        if(board[i][column]=='Q')
        return false;
    }

    // upper left diagonal
    for(int i=row,j=column;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q')
        return false;
    }

    // upper right diagonal
    for(int i=row,j=column;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]=='Q')
        return false;
    }

    return true;
}

void sortqueen(vector<string> &board,int row,int n,vector<vector<string>> &ans)
{
    if(row==n)
    {
        ans.push_back(board);
        return;
    }

    for(int j=0;j<n;j++)
    {
        if(issafe(board,row,j,n))
        {
            board[row][j]='Q';

            sortqueen(board,row+1,n,ans);

            board[row][j]='.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> ans;

    vector<string> board(n,string(n,'.'));

    sortqueen(board,0,n,ans);

    return ans;
}

};