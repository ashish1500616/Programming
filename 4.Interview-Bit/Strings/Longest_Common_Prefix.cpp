string Solution::longestCommonPrefix(vector<string> &A)
{
    int i = 0;
    int n = (int(A.size()));
    int j = 0;
    int mi = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        j = 0;
        while (A[i - 1][j] == A[i][j])
        {
            j++;
        }
        mi = min(mi, j);
    }
    return A[0].substr(0, mi);
}

// Approach
// Checking similar no of characters in Adjacent String and keeping a track of minimum no of characters which matched .
// TC - O( n * k), where k is the maximum similar no of characters.