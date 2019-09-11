#define ll long long
bool isPossible(vector<int> &A, int B, int p)
{
    ll student = 1, cur_pages = 0;

    for (auto x : A)
    {
        if (cur_pages + x > p)
        {
            cur_pages = x;
            student++;
            if (student > B)
            {
                return false;
            }
        }
        else
        {
            cur_pages += x;
        }
    }
    return true;
}
int Solution::books(vector<int> &A, int B)
{

    int n = int(A.size());

    if (B > n)
    {
        return -1;
    }
    ll total_pages = accumulate(A.begin(), A.end(), 0);
    /*
   
   In any case a student has to read atleast one book.Since we have to minimize the maximum pages which can be read so therefore 
   so therefore minimum no of pages a student can read is Book with maximum no of pages.

   therefore our search space starts from [Book with Max pages , Total no of pages in Book.]
   */

    ll start = *max_element(A.begin(), A.end());
    ll end = total_pages;
    ll min_pages = -1;
    while (start <= end)
    {
        int mid = (end - start) / 2 + start;
        if (isPossible(A, B, mid))
        {
            // true
            min_pages = mid;
            end = mid - 1;
        }
        else
        {
            //false
            start = mid + 1;
        }
    }
    return min_pages;
}
