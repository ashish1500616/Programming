#include<bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
int main()
{
    vector<int> a={1,2,3,-1,-2,-1,0,1,2,3};
    vector<int> dp(a.size(),1);
    int ans=0;
    for (int i=1;i<a.size();i++)
    {
        for (int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    ans=*max_element(all(dp));
    cout<<ans<<endl;

}