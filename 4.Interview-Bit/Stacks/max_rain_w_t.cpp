#include<bits/stdc++.h>
using namespace std;
vector<int> maxElemFromEitherSide(vector<int> A,int n=1)
{
    stack<int>s;
    int l=int(A.size());
    vector<int> v;
    if(n)
    {
        v.clear();
        v.push_back(A[0]);
        int m=A[0];
        for (int i=1;i<l;i++)
        {
            m=max(m,A[i]);
            v.push_back(m);
        }   
    }
    else
    {
        v.clear();
        int m=A[A.size()-1];
        v.push_back(A[A.size()-1]);
        for (int i=l-2;i>=0;i--)
        {
            m=max(m,A[i]);
            v.push_back(m);
        }   
    }
    return v;
}

int trap(const vector<int> &A) {
    vector<int> lm=maxElemFromEitherSide(A,1);
    vector<int> rm=maxElemFromEitherSide(A,0);
    long long ans=0;
    int l=int(A.size());
    for(int i=0;i<A.size();i++)
    {
        ans+=(min(lm[i],rm[l-i-1])-A[i]);
    }
    return ans;
}

int main()
{
vector<int> test ={0,1,0,2,1,0,1,3,2,1,2,1};
cout<<trap(test)<<"\n";
return 0;
}