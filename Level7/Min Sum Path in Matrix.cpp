vector<vector<int> > m;
int memo[1002][1002];
int dp(int i,int j){
    if(i==m.size()-1&&j==m[i].size()-1)return m[i][j];
    if(i>=m.size()||i<0||j<0||j>=m[i].size())return (1<<30);
    if(memo[i][j])return memo[i][j];
    return memo[i][j]=m[i][j]+min(dp(i+1,j),dp(i,j+1));
}
int Solution::minPathSum(vector<vector<int> > &A) {
    m=A;
    memset(memo,0,sizeof(memo));
    return dp(0,0);
}
