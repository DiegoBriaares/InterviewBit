int memo[1002][1002][2];
vector<int>v;
int dp(int i,int j,int s){
    if(i>j)return 0;
    if(memo[i][j][s])return memo[i][j][s];
    if(!s){
        return memo[i][j][s]=max(v[j]+dp(i,j-1,1),v[i]+dp(i+1,j,1));
    }
    else {
        return memo[i][j][s]=min(dp(i,j-1,0),dp(i+1,j,0));
    }
}
int Solution::maxcoin(vector<int> &A) {
    memset(memo,0,sizeof(memo));
    v=A;
    return dp(0,A.size()-1,0);
}
