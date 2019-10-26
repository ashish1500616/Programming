int Solution::isValidSudoku(const vector<string> &A)
{
    vector<int> digits;
    for (int i = 1; i <= 9; i++)
    {
        digits.push_back(i);
    }
    vector<set<int>> r(9);
    vector<set<int>> c(9);
    vector<set<int>> b(9);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int digit = (A[i][j] - '0');
            if (A[i][j] == '.')
            {
                continue;
            }
            if (binary_search(digits.begin(), digits.end(), digit) == false)
            {
                return 0;
            }
            if (r[i].count(digit) != 0)
                return false;
            if (c[j].count(digit) != 0)
                return false;

            // box = (size of Grid ie 9 // parts ) * (Row Index // parts) + (Column Index // parts.)
            int box = 3 * int(i / 3) + int(j / 3);
            if (b[box].count(digit) != 0)
                return false;

            r[i].insert(digit);
            c[j].insert(digit);
            b[box].insert(digit);
        }
    }
    return 1;
}
