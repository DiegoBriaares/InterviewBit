int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    int a=A[0],b=A[1];
    reverse(A.begin(),A.end());
    int r=1,many=0,res=(a*b)*A[0];
    for(int i=0;i<3;i++){
        r*=A[i];
    }
    res=max(res,r);
    return res;
}
