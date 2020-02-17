int Solution::solve(string A)
{
    int n = A.size();
    long a = 0;
    int i = 0;
    for (auto x : A)
    {
        i++;
        if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
        {
            a += n - i + 1;
            a %= 10003;
        }
    }
    return a;
}
