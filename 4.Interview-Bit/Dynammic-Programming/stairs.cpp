int Solution::climbStairs(int A)
{
    if (A == 0)
        return
}
int Solution::climbStairs(int A)
{
    if (A == 0)
        return 0;
    if (A == 1)
        return 1;
    if (A == 2)
        return 2;
    return climbStairs(A - 1) + climbStairs(A - 2);
}
