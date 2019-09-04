#include<bits/stdc++.h>
using namespace std;
int LCS(string A, string B,int i,int j){
    if(A[i]=='\0' || B[j]=='\0')
    return 0;
    if(A[i]==B[j])
    return (1+LCS(A,B,i+1,j+1));
    else
    return (max(LCS(A,B,i+1,j),LCS(A,B,i,j+1)));
}

int solve() {
    string A = "bebdeeedaddecebbbbbabebedc"; 
	string B = "abaaddaabbedeedeacbcdcaaed";
    int ans=LCS(A,B,0,0);
    return ans;
}
int main()
{
    cout<<solve()<<"\n";
    return 0;
}