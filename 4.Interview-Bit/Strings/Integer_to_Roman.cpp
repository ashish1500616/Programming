string Solution::intToRoman(int A)
{
    vector<int> N = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    vector<string> S = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int i = N.size() - 1;
    string ans = "";
    while (A)
    {
        int quotient = A / N[i];
        A %= N[i];
        while (quotient--)
        {
            ans += S[i];
        }
        i--;
    }
    return ans;
}
