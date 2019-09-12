/*Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board*/

#define ll long long
#define mod 10000003
bool isPossible(ll c_painter, ll nou, vector<int> &c, ll posAns)
{
    ll p_c = 1;
    ll cur_sum = 0;
    for (auto x : c)
    {
        if (cur_sum + x > posAns)
        {
            cur_sum = (x);
            cur_sum %= mod;
            p_c++;
            if (p_c > c_painter)
            {
                return false;
            }
        }
        else
        {
            cur_sum += x;
            cur_sum %= mod;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C)
{

    int n = (int(C.size()));
    ll e = accumulate(C.begin(), C.end(), 0);
    ll s = *max_element(C.begin(), C.end());

    ll final_ans;

    while (s <= e)
    {
        int mid = (e - s) / 2 + s;
        if (isPossible(A, B, C, mid))
        {
            final_ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return (final_ans * B) % mod;
}
