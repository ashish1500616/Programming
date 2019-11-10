vector<int> Solution::nextGreater(vector<int> &A)
{
    vector<int> ans(A.size(), -1);
    stack<int> s;
    s.push(A[0]);
    for (int i = 1; i < A.size(); i++)
    {
        if (s.empty())
        {
            s.push(A[i]);
            continue;
        }
        int c = 1;
        while ((s.empty() == false and s.top() < A[i]))
        {
            /*
            Pop Only If You Update The Next Greater .
            */
            if (ans[i - c] == -1)
            {
                ans[i - c] = A[i];
                s.pop();
            }
            ++c;
        }
        s.push(A[i]);
    }
    return ans;
}
