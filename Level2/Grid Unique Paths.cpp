int memo[500][500];
int dp(int i,int j,int A,int B){
    if(i==A&&j==B)return 1;
    if(i>A||j>B)return 0;
    if(memo[i][j])return memo[i][j];
    return memo[i][j]=dp(i+1,j,A,B)+dp(i,j+1,A,B);
}
int Solution::uniquePaths(int A, int B) {
    memset(memo,0,sizeof(memo));
    A--;
    B--;
    return dp(0,0,A,B);
}
