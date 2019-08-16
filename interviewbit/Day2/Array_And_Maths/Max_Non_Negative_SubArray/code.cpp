vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ans,ca;
    long long cs=0,mi=INT_MIN,sz=int(A.size());
    for(int i=0;i<sz;i++)
    {
        if(A[i]<0)
        {
            cs=0;
            ca.clear();
        }
        else
        {
        cs+=1LL*A[i];
        ca.push_back(A[i]);
        if(cs>=mi)
        {
            if(cs>mi)
            ans=ca;
            else if(ans.size() < ca.size()&&mi==cs)
            ans=ca;
            mi=cs;
        }
        }
 
    }
    if(!ans.empty()){
        if(ans[0]<0)
            ans.clear();
    }
    return ans;
}