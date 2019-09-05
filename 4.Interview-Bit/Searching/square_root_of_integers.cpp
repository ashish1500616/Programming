#define ll long long
int Solution::sqrt(int A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ll s = 0, e = A, mid;
    ll ans = 0;
    while (s <= e)
    {
        mid = (s + e) / 2;
        ll square = mid * mid;
        if (square == A)
        {
            ans = mid;
            break;
        }
        else if (square < A)
        {
            s = mid + 1;
            ans = mid;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
