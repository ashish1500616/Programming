class Solution
{
public:
    int func(int m, vector<int> &A, int S)
    {
        int j = 0;
        int s = 0;
        while (j < A.size())
        {
            if (j < m)
                s += A[j];
            else
                s += (A[j] - A[j - m]);
            j++;
            if (j >= m - 1 && s >= S)
            {
                return 1;
            }
        }
        return 0;
    }
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int l = -1;
        int h = n;
        while (h - l > 1)
        {
            int m = (l + h) / 2;
            if (func(m, nums, s) == 1)
            {
                h = m;
            }
            else
            {
                l = m;
            }
        }
        if (h == n)
        {
            int sum = 0;
            for (auto x : nums)
            {
                sum += x;
            }
            if (sum < s)
            {
                return 0;
            }
        }
        return h;
    }
};