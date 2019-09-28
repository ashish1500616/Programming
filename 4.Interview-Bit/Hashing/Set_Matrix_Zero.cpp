void Solution::setZeroes(vector<vector<int>> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int r = A.size();
    int c = A[0].size();
    unordered_set<int> ro;
    unordered_set<int> co;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i][j] == 0)
            {
                ro.insert(i);
                co.insert(j);
            }
        }
    }
    for (auto it : ro)
    {
        for (int i = 0; i < c; i++)
            A[it][i] = 0;
    }
    for (auto it : co)
    {
        for (int i = 0; i < r; i++)
            A[i][it] = 0;
    }
}
