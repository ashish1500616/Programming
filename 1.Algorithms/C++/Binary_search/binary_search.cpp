#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> A={1,2,3,4,5};
    int search=10;
    int h=A.size()-1; // Including the search space .
    int l=0;
    while(l<=h)
    {
        int mid=l+((h-l)>>1);
        if(A[mid]==search)
        {
            cout<<"Found"<<"\n";
        }
        else if(A[mid]<search)
        {
            l=mid+1;
        }
        else
        {
            h=mid-1;
        }
    }
    cout<<"Not Found\n";
    return 0;
}