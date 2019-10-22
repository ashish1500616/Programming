int Solution::solve(string A, int B)
{
    vector<int> f(26, 0);
    for (auto x : A)
    {
        f[x - 'A'] += 1;
    }
    int mx = *max_element(f.begin(), f.end());
    int tf = accumulate(f.begin(), f.end(), 0);
    int samMaxVal = 0;
    for (auto x : f)
    {
        if (x == mx)
            ++samMaxVal;
    }
    // Formula for ans fails in when value of k is small and No of different task is more.

    int ans = (mx - 1) * (B + 1) + samMaxVal;
    // case when the above ans fails the ans equals to the total frequency of all the different tasks.
    return (ans > tf) ? ans : tf;
}

// int Solution::solve(string A, int B) {
//     map<char,int> mp;
//     for(auto x: A)
//         if(mp.count(x)==0)
//             mp.insert({x,1});
//         else
//             mp[x]+=1;

//     priority_queue<pair<int,pair<char,int> > > pq;
//     for(auto x:mp)
//     {
//         pq.push({x.second,{x.first,-1}});
//     }
//     int in=0;
//     vector< pair<int,pair<char,int> > > temp;
//     while(!pq.empty())
//     {
//         // cout<<in<<"\n";
//         while(pq.top().second.second != -1 && pq.top().second.second >= in )
//         {
//             temp.push_back(pq.top());
//             pq.pop();
//         }
//         auto tp=pq.top();
//         // cout<<tp.first <<" "<<tp.second.first <<" "<<tp.second.second<<"\n";
//         pq.pop();
//         tp.first-=1;
//         tp.second.second=in+B;
//         if(tp.first!=0)
//         pq.push(tp);
//         ++in;
//         for(auto x: temp)
//         {
//             pq.push(x);
//         }
//         temp.clear();
//     }
//     return in+1;
// }
