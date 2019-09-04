#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    set<int> s;
    int n,q;
    cin>>n>>q;
    int *arr =new int[q];
    for (int i=0;i<q;i++)
    {
        int v;
        cin>>v;
        arr[i]=v;
    }
    for(int j=0;j<q;j++)
    {
        s.insert(arr[j]);
        ll r=1;
        set<int>::iterator p=s.begin();
        for(set<int>::iterator it=++s.begin();it!=s.end();it++)
        {
            r+=*(p++)*1L+*(it)*1L;
        }
        r+=n*1L;
        cout<<r<<endl;
    }
}