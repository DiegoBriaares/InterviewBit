int Solution::mice(vector<int> &A, vector<int> &B) {
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    int r=0;
    for(int i=0;i<A.size();i++){
        r=max(r,abs(A[i]-B[i]));
    }
    return r;
}
