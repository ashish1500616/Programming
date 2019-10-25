int Solution::divide(int A, int B)
{
    using ll = long long;
    int sign = ((A < 0 && B < 0) || (A > 0 && B > 0)) ? 1 : -1;

    if (A == INT_MIN && B == -1)
        return INT_MAX;
    else if (A == INT_MIN && B == 1)
        return -1 * INT_MIN;
    else if (A == INT_MAX && B == -1)
        return -1 * INT_MIN;
    else if (A == INT_MAX && B == 1)
        return INT_MAX;

    ll tA = abs(1LL * A);
    ll tB = abs(1LL * B);

    // Approach 1 : Subtracting divisor.
    // int q = 0;
    // while (tA >= tB)
    // {
    //     tA -= tB;
    //     q++;
    // }

    // Approach 2: using Bit manipulation.
    ll t = 0, q = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (t + (tB << i) <= tA)
        {
            t += (tB << i);
            q |= (1LL << i);
        }
    }
    return sign * q;
}

// Approach:
// quotient * divisor + remainder = dividend
// using Bit manipulation we will try to find quotient * divisor <= dividend
// Divisor is Given as Well as Dividend is given in the question we will try to find quotient.
// Since every number can be represented in the form of binary .
// We will start from 31 upto 0. Max integer can be 2^31.

// A= 19 B= 6
// Iteration 1:
//  T=0;
//  q=0;

//  we will check :  T + (divisor << i) <=dividend .

//                    (1<<2) = 1 * (2^2) .
//         Similarly  (n << x) = n * (2^x) ;

//                  0 + (6 << 31 ) <= 19 -------- False.

//                  .
//                  .
//                  .
//                  .
//                 Iterations untill we find a value which is a multiple of divisor and less than dividend .

//                 0 + (6 << 1) <= 19 -------- True .
//                 {
//                     T + = (6 << 1) , which is basically 12.
//                     q = q | (1 << i); where the value of i = 1, in this case.
//                     Here We are try to retain the bits after addition of which to temproray variable remains less than the dividend .

//                     Initially q=0;
//                     q = 0 or (1 << 1) ------- ( 1 << 1 means 1 * (2 ^ 1)  == 2 in binary its 0010. )
//                     Therefore q becomes 0000 or 0010  ==  0010 .
//                     /* code */
//                 }

//  Next Iteration

//               T=12
//               q=2
//               Divisor=6
//               Dividend =19.

//               T + ( 6 << 0 ) <= 19  ---- > 12 + 6 <= 19  ----------True .
//               {
//                    T+=(6<<0)  ------>12 + 6 = 18 .
//                    q= q or (1 << i) ----------> q = 2 or (1 << 0).
//                    In binary which equals  0010 or 0001 = 0011 .
//               }
//               q=3 .

// Loop breaks since i=-1