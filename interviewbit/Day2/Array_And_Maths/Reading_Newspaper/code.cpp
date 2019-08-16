int Solution::solve(int A, vector<int>& B)
{
    int i=0;
    while(1)
    {
        i=i%7;
        A-=B[i];
        if(A<=0)
        break;
        i++;
    }
    i++;
 
 
    return i;
}