#include<bits/stdc++.h>
using namespace std;

int longestConsecutive(const vector<int> &A) {

    int l=A.size();
    vector<int> a(A);
    if(l==1)
    return l;
    // int mx =*max_element(a.begin(),a.end());
    // if(mx<0)
    // mx=mx*-1;
    // vector<int> h(mx,0);
    // for (auto i=0;i<a.size();i++)
    // {
    //     if(a[i]<0)
    //     a[i]=a[i]*-1;
    //     if(h[a[i]]==0)
    //     h[a[i]]+=1;
    // }
 
    // int c=0,m=INT_MIN;
    // for(auto x=1;x<h.size();x++)
    // {
    //     if(x==1)
    //     {
    //         c+=1;
    //     }
    //     else
    //     c=0;
    //     m=max(m,c);
    // }
    // return m;
    
    map <int,int> m;
    for(auto x:A)
    {
        m[x]=1;
    }
    int c=1;
    auto m_t=m.begin();
    int ma=max(m_t->first,INT_MIN);
    for(auto i=(++m.begin());i!=m.end();i++)
    {
        cout<<"mt"<<m_t->first<<"\n";
        cout<<i->first<<"\n";
        if((i->first)-(m_t->first)==1)
        {
            c+=1;
            ma=max(c,ma);
            cout<<"count"<<c<<"\n";
        }
        else
        {
            c=1;
            cout<<"count"<<c<<"\n";

        }
        m_t++;
    }
    return ma;
}

int main()
{
    vector<int> A={ 97, 86, 67, 19, 107, 9, 8, 49, 23, 46, -4, 22, 72, 4, 57, 111, 20, 52, 99, 2, 113, 81, 7, 5, 21, 0, 47, 54, 76, 117, -2, 102, 34, 12, 103, 69, 36, 51, 105, -3, 33, 91, 37, 11, 48, 106, 109, 45, 58, 77, 104, 60, 75, 90, 3, 62, 16, 119, 85, 63, 87, 43, 74, 13, 95, 94, 56, 28, 55, 66, 92, 79, 27, 42, 70 };
    cout<<longestConsecutive(A)<<"\n";
    return 0;
}