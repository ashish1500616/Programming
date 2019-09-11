bool isSafe(vector<vector<string>> &board, int r, int c, int N)
{
    // Check That Particular Row.
    for (int j = 0; j < c; j++)
    {
        if (board[r][j] == "Q")
            return false;
    }

    // We wont check for  the columns bcoz we are filling the queen first time in the row and moving to the next column 
    // so in every scenario there can be only one queen in the column.
    // for(int i=0;i<r;i++)
    // {
    //     if(board[r][c]=="Q")
    //     return false;
    // }

    // Check Top Left Side Of The Diagonal
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == "Q")
            return false;
    }
    // Check Bottom Left Side Of the Diagonal
    for (int i = r, j = c; i < N && j >= 0; i++, j--)
    {
        if (board[i][j] == "Q")
            return false;
    }
    return true;
}

bool solveNqueen(vector<vector<string>> &board, vector<vector<string>> &tb, int col, int N)
{
    // when all the columns are filled and we are checking for the next column which is not present in the board.
    if (col == N)
    {
        vector<string> possibleBoard;
        for (auto x : tb)
        {
            string eachRow = "";
            for (auto y : x)
                eachRow += y;
            possibleBoard.push_back(eachRow);
        }
        board.push_back(possibleBoard);
        return false;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (isSafe(tb, i, col, N))
            {
                tb[i][col] = "Q";
                if (solveNqueen(board, tb, col + 1, N))
                {
                    return true;
                }
                tb[i][col] = ".";
            }
        }
    }
    return false;
}

vector<vector<string>> Solution::solveNQueens(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // 2d Board Configuration For testing.
    vector<vector<string>> t_b(A, vector<string>(A, "."));

    // 2d vector to contain the final answer.
    vector<vector<string>> boards;
    solveNqueen(boards, t_b, 0, A);
    return boards;
}
