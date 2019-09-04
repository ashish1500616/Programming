int Solution::trap(const vector<int> &A) {
    assert(A.size() != 0);
    
    vector<int> l(A.size());
    vector<int> r(A.size());
    
    l[0] = A[0];
    for(int i = 1; i < A.size(); i++){
        l[i] = max(l[i-1], A[i]);
    }
    
    r[A.size()-1] = A[A.size()-1];
    for(int i = A.size()-2; i >= 0; i--){
        r[i] = max(r[i+1], A[i]);
    }
    
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++){
        ans = ans + min(l[i], r[i]) - A[i];
    }
    
    return ans;
}
