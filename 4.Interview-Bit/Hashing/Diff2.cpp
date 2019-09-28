
int Solution::diffPossible(const vector<int> &A, int B)
{

    // int n=A.size();
    // for(int i=0;i<n;i++)
    // for(int j=i+1;j<n;j++)
    // {
    //     if(A[j]-A[i]==B || A[i]-A[j]==B)
    //     return 1;
    // }
    // return 0;

    unordered_set<int> S;
    for (int i = 0; i < A.size(); i++)
    {
        int aj = A[i] - B;
        int ai = A[i] + B;
        if (S.find(aj) != S.end() || S.find(ai) != S.end())
            return 1;
        S.insert(A[i]);
    }
    return 0;
}
