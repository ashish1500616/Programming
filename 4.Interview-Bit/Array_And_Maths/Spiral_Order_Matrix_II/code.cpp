vector<vector<int> > Solution::generateMatrix(int A) {
    vector< vector<int> > Ar(A,vector<int>(A,0));
    int n=1;
    int i=0,j=0;
    while(n<=(A*A))
    {
        while(j<A && Ar[i][j]==0){
            Ar[i][j++] = n++;
        }
        j--;
        i++;
        while(i<A  && Ar[i][j]==0){
            Ar[i++][j] = n++;
        }
        i--;
        j--;
        while(j>-1 && Ar[i][j]==0){
            Ar[i][j--] = n++;
        }
        j++;
        i--;
        while(i>-1 && Ar[i][j]==0){
            Ar[i--][j] = n++;
        }
        i++;j++;
    }
    return Ar;
}