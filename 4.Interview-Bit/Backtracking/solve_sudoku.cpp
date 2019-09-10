

bool FindUnassigned(vector<vector<char>> &A, int &r, int &c)
{
    for (r = 0; r < A.size(); r++)
    {
        for (c = 0; c < A[0].size(); c++)
        {
            if (A[r][c] == '.')
                return 1;
        }
    }
    return 0;
}

bool isSafe(vector<vector<char>> &A, int r, int c, int n)
{
    // check if row and column are unassigned
    bool ifUnassigned = (A[r][c] == '.') ? true : false;

    // check in row
    bool checkInRow = false;
    for (int j = 0; j < A[0].size(); j++)
    {
        if ((A[r][j] - '0') == n)
        {
            checkInRow = true;
            break;
        }
    }

    // check in column
    bool checkInColumn = false;
    for (int i = 0; i < A.size(); i++)
    {
        if ((A[i][c] - '0') == n)
        {
            checkInColumn = true;
            break;
        }
    }
    // check in box
    bool checkInBox = false;
    r = r - r % 3;
    c = c - c % 3;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((A[i + r][j + c] - '0') == n)
            {
                checkInBox = true;
                break;
            }
        }
    }
    return (ifUnassigned && !checkInRow && !checkInColumn && !checkInBox);
}

bool solve_sudoku(vector<vector<char>> &A)
{
    int r, c;

    if (!FindUnassigned(A, r, c))
        return true;

    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(A, r, c, num))
        {
            A[r][c] = num + '0';

            if (solve_sudoku(A))
            {
                return true;
            }

            A[r][c] = '.';
        }
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    solve_sudoku(A);
}
