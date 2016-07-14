vector<vector<int> > v;
int memo[102][102];
int n,c;
bool ok;
int dp(int i,int j){
    if(i==0&&j==0&&v[i][j]==1)return 0;
    if(i==(n-1)&&j==(c-1)){
    	ok=true;
		return 1;
	}
    if(i>=n||j>=c)return 0;
    if(memo[i][j])return memo[i][j];
    memo[i][j]=0;
    if(i+1<n&&v[i+1][j]==0){
        memo[i][j]+=dp(i+1,j);
    }
    if(j+1<c&&v[i][j+1]==0){
        memo[i][j]+=dp(i,j+1);
    }
    return memo[i][j];
}
int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
   memset(memo,0,sizeof(memo));
   v.clear();
   for(int i=0;i<A.size();i++)v.push_back(A[i]);
   ok=false;
   n=A.size();
   c=A[0].size();
   int r=dp(0,0);
   if(!ok)r=0;
   return r;
}
