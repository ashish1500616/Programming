vector<int> Solution::solve(vector<int> &A)
{
    vector<int> ans;
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n = A.size();
    int med = A[0];
    max_heap.push(med);
    ans.push_back(med);
    for (int i = 1; i < n; i++)
    {
        int x = A[i];
        if (max_heap.size() > min_heap.size())
        {
            if (x < med)
            {
                min_heap.push(max_heap.top());
                max_heap.pop();
                max_heap.push(x);
            }
            else
            {
                min_heap.push(x);
            }
            med = (max_heap.top());
        }
        else if (max_heap.size() < min_heap.size())
        {
            if (x > med)
            {
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(x);
            }
            else
            {
                max_heap.push(x);
            }
            med = (max_heap.top());
        }
        else
        {
            if (x < med)
            {
                max_heap.push(x);
                med = max_heap.top();
            }
            else
            {
                min_heap.push(x);
                med = min_heap.top();
            }
        }
        ans.push_back(med);
    }
    return ans;
}
