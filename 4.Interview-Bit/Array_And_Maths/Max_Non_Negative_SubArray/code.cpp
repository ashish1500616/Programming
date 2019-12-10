vector<int> Solution::maxset(vector<int> &A)
{
    vector<int> ans, ca;
    long long cs = 0, mi = INT_MIN, sz = int(A.size());
    for (int i = 0; i < sz; i++)
    {
        if (A[i] < 0)
        {
            cs = 0;
            ca.clear();
        }
        else
        {
            cs += 1LL * A[i];
            ca.push_back(A[i]);
            if (cs >= mi)
            {
                if (cs > mi)
                    ans = ca;
                else if (ans.size() < ca.size() && mi == cs)
                    ans = ca;
                mi = cs;
            }
        }
    }
    if (!ans.empty())
    {
        if (ans[0] < 0)
            ans.clear();
    }
    return ans;
}

#define ll long long
vector<int> Solution::maxset(vector<int> &A) {
    int n=A.size();
    int msl=-1;
    int msr=-1;
    int csl=0;
    int csr=0;
    ll ms=0;
    ll cs=0;
    while(csr<n)
    {
        // Case  : When Value is negative we will just skip the value and increment the counter .
        if(A[csr]<0)
        {
            csl=csr+1;
            cs=0;
            csr++;
            continue;
        }
        // Adding Sum to current sum.
        cs+=(1LL*A[csr]);
        // If current sum > max sum change the left and right pointer for the max sum .
        if(cs > ms)
        {
            ms=cs;
            msl=csl;
            msr=csr+1;
        }
        // if current sum and max sum is equal in value .
        else if(cs==ms)
        {
            // Check If the number of elements in current sum is more than the number of elements in max sum .
            if( (csr-csl+1) > (msr-msl) )
            {
                msl=csl;
                msr=csr+1;
            }
        }
        // Increment the pointer. 
        csr+=1;
    }
    vector<int> ans;
    // Note  : maintaining max_sum_right index + 1 . 
    for(int i=msl;i<msr;i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}
I