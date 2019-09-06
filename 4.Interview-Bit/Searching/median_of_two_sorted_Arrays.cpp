
// double findMedian(vector<int> A,vector<int> B)
// {
//     int n=A.size();
//     int m=B.size();
//     if(n>m)
//     {
//         findMedian(B,A);
//     }
//     else
//     {
//     int l=0;
//     int h=n;
//     int i=0;
//     while(l<=h)
//     {
//         int px=(l+h)>>1;
//         int py=((n+m+1)>>1)-px;

//         int maxLeftX=(px==0)? INT_MIN:A[px-1];
//         int minRightX=(px==n)? INT_MAX:A[px];

//         int maxLeftY=(py==0)? INT_MIN:B[py-1];
//         int minRightY=(py==m)? INT_MAX:B[py];

//         if(maxLeftX <= minRightY && maxLeftY<=minRightX)
//         {
//             if((n+m)&1)
//             {
//                 return max(maxLeftX,maxLeftY);
//             }
//             else
//             {
//                 return (double(max(maxLeftX,maxLeftY)+min(minRightX,minRightY))/2);
//             }
//         }
//         else if(maxLeftX>minRightY)
//         {
//             h=px-1;
//         }
//         else
//         {
//             l=px+1;
//         }
//     }
//     }
// }

// double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

//     double median=findMedian(A,B);
//     return median;

// }

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    int m = A.size(), n = B.size();

    if (m < n)
        return findMedianSortedArrays(B, A);

    int l = 0, h = 2 * n;

    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int mid1 = m + n - mid;

        double L1 = (mid1 == 0) ? INT_MIN : A[(mid1 - 1) / 2];
        double L2 = (mid == 0) ? INT_MIN : B[(mid - 1) / 2];
        double R1 = (mid1 == m * 2) ? INT_MAX : A[(mid1) / 2];
        double R2 = (mid == n * 2) ? INT_MAX : B[(mid) / 2];

        if (L1 > R2)
            l = mid + 1;
        else if (L2 > R1)
            h = mid - 1;
        else
            return (max(L1, L2) + min(R1, R2)) / 2;
    }
}
