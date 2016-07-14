int dp[10002];
int Solution::lis(const vector<int> &A) {
    memset(dp,0,sizeof(dp));
    int n=A.size();
    for(int i=n-1;i>=0;i--){
        dp[i]=1;
        for(int j=i+1;j<n;j++){
            if(A[j]>A[i])dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int r=0;
    for(int i=0;i<n;i++)r=max(r,dp[i]);
    return r;
}
