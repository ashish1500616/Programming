int Solution::romanToInt(string A)
{
    map<char, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    int n = A.size();
    int ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i == n)
        {
            //Condition to handle the last element in the string.
            ans += m[A[i]];
        }
        else
        {
            int c_char = m[A[i]];
            int c_1_char = m[A[i + 1]];
            if (c_char >= c_1_char)
            {
                ans += c_char;
            }
            else
            {
                ans += (c_1_char - c_char);
                // We Increment Here as we now dont want to consider the the next element to the current index.
                // Ex - IV - ans+=(5-1)
                // If we don't increment 'i' here we will again consider 'V' to add to our ans.
                //  'IV' - ans+=(5-4) + (5) which is wrong.
                i++;
            }
        }
    }
    return ans;
}
