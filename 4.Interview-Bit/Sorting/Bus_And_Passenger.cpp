#define pi int, int
vector<int> Solution::solve(vector<int> &A, string B)
{
    map<pi> mp;
    int j = 0;
    map<pi, greater<int>> maxp;
    vector<int> ans(B.size());
    for (int i = 1; i <= A.size(); i++)
    {
        mp.insert({A[i - 1], i});
    }
    for (int i = 0; i < B.size(); i++)
    {
        if (B[i] == '0')
        {
            ans[j++] = mp.begin()->second;
            maxp.insert({mp.begin()->first, mp.begin()->second});
            mp.erase(mp.begin());
        }
        else if (B[i] == '1')
        {
            ans[j++] = maxp.begin()->second;
            maxp.erase(maxp.begin());
        }
    }
    return ans;
}
//  Accepted Solution using min_heap and max_heap
// int n=int(A.size());
// int bn=B.size();
// vector<int> ans(bn);
// priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > min_h;
// for(int i=0;i<n;i++)
// {
//     min_h.push({A[i],i+1});
// }
// int j=0;
// priority_queue< pair<int,int> > max_h;
// for(int i=0;i<bn;i++)
// {
//     if(B[i]=='0')
//     {
//         ans[j++]=min_h.top().second;
//         max_h.push(min_h.top());
//         min_h.pop();
//     }
//     else if(B[i]=='1')
//     {
//         ans[j++]=max_h.top().second;
//         max_h.pop();
//     }
// }
// return ans;

//  Brute Force Time Complexity Exceeds.
// for(int i=0;i<n;i++)
// {
//     mp.insert({A[i],{i+1,2}});
// }
// int j=0;
// for(int i=0;i<bn;i++)
// {
//     if(B[i]=='0')
//     {
//         for(auto x=mp.begin();x!=mp.end();x++)
//         {
//             if(x->second.second==2)
//             {
//                  ans[j++]=x->second.first;
//                  x->second.second=1;
//                  break;
//             }
//         }
//     }
//     else if(B[i]=='1')
//     {
//         for(auto x=mp.rbegin();x!=mp.rend();x++)
//         {
//             if(x->second.second==1)
//             {
//                  // cout<<x->first << " "<< x->second.first << " "<< x->second.second<<" \n";
//                  ans[j++]=x->second.first;
//                  x->second.second=0;
//                  break;
//             }
//         }
//     }
// }