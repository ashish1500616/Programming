string Solution::solve(string A, int B)
{
    vector<int> fa(26, 0);
    for (int i = 0; i < A.size(); i++)
    {
        fa[A[i] - 'a'] += 1;
    }

    B %= 26; // [0-25]

    string ans = "";
    for (int i = 0; i < A.size(); i++)
    {
        if (fa[A[i] - 'a'] & 1)
        {
            int x = ((A[i] - 'a') - B + (26)) % 26; //  0 - 25 + 26
            ans += char(x + 'a');
        }
        else
        {
            int x = (A[i] - 'a' + B) % 26; //  25 + 25
            ans += char(x + 'a');
        }
    }
    return ans;
}

// 0 1 2 3 4 5 6 7 8 9 10 11
// 0 1 2 3 0 1 2 3 0 1  2  3

// (a+b)%m = (a%m + b%m) % m

// a>b : a%m - b%m is -ve
// (a-b)%m = ((a%m - b%m) + m) %m

// (a*b)%m = (a%m * b%m) % m

// (a/b)%m = (a%m * mulpliplicative_inverse(b)%m) % m

// 0-25 = -25 we should add 25

// B=25
// 'a' -> 'b'

// -25 == 1('b')

// -25+26 = 1
