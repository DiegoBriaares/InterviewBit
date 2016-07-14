vector<vector<int> >m;
int memo[2][100002];
int n;
int dp(int i,int j){
    if(j>=n)return 0;
    if(memo[i][j])return memo[i][j];
    if(i==0){
        return memo[i][j]=max(m[i][j]+dp(i,j+2),max(m[i][j]+dp(i+1,j+2),dp(i,j+1)));
    }
    else {
        return memo[i][j]=max(m[i][j]+dp(i,j+2),max(m[i][j]+dp(i-1,j+2),dp(i,j+1)));
    }
}
int Solution::adjacent(vector<vector<int> > &A) {
    m.clear();
    n=A[0].size();
    memset(memo,0,sizeof(memo));
    m.push_back(A[0]);
    m.push_back(A[1]);
    return max(dp(0,0),dp(1,0));
}

