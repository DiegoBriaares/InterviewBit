vector<vector<int> >m;
int memo[1002][1002];
int dp(int i,int j){
    if(i<0||i>=m.size()||j<0||j>=m[i].size())return (1<<30);
    if(i==m.size()-1)return m[i][j];
    if(memo[i][j])return memo[i][j];
    return memo[i][j]=m[i][j]+min(dp(i+1,j),dp(i+1,j+1));
}
int Solution::minimumTotal(vector<vector<int> > &A) {
    m=A;
    memset(memo,0,sizeof(memo));
    return dp(0,0);
}
