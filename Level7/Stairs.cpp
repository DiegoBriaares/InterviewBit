int memo[1002];
int dp(int n){
    if(n==0)return 1;
    if(n<0)return 0;
    if(memo[n])return memo[n];
    return memo[n]=dp(n-1)+dp(n-2);
}
int Solution::climbStairs(int A) {
    memset(memo,0,sizeof(memo));
    return dp(A);
}
