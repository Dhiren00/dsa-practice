class Solution {
public:

bool issafe(vector<vector<char>>& board,int row,int clo,char k)
{
    for(int i=0;i<9;i++)
    {
        if(board[row][i]==k)
            return false;
    }

    for(int i=0;i<9;i++)
    {
        if(board[i][clo]==k)
            return false;
    }

    int startRow=(row/3)*3;
    int startCol=(clo/3)*3;

    for(int i=startRow;i<startRow+3;i++)
    {
        for(int j=startCol;j<startCol+3;j++)
        {
            if(board[i][j]==k)
                return false;
        }
    }

    return true;
}

bool place(vector<vector<char>>& board,int row,int clo)
{
    if(row==9)
        return true;

    int nextrow=row;
    int nextcol=clo+1;

    if(nextcol==9)
    {
        nextrow=row+1;
        nextcol=0;
    }

    if(board[row][clo] != '.')
        return place(board,nextrow,nextcol);

    for(char i='1'; i<='9'; i++)
    {
        if(issafe(board,row,clo,i))
        {
            board[row][clo]=i;

            if(place(board,nextrow,nextcol))
                return true;

            board[row][clo]='.';
        }
    }

    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    place(board,0,0);
}

};