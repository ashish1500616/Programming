vector<int> Solution::solve(int A, vector<int> &B)
{
    priority_queue<int> max_h;
    int n = B.size();
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        int x = B[i];
        if (max_h.size() < A)
        {
            max_h.push(x * -1);
            if (max_h.size() <= (A - 1))
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(max_h.top() * -1);
            }
        }
        else
        {
            int tp = max_h.top();
            if (tp > (x * -1))
            {
                max_h.pop();
                max_h.push((x * -1));
            }
            ans.push_back((max_h.top() * -1));
        }
    }
    return ans;
}
