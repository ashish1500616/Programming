string Solution::solve(vector<int> &A)
{
    int r = 0;
    // Merge all the Numbers Into One Number
    for (auto x : A)
        r ^= x;
    // Yes If It Can be Divided Into Two Same Numbers.
    // Else OtherWise.
    return (r & 1) ? "No" : "Yes";
}
