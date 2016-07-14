long long memo[100002][2];
vector<int>v;
int dp(int i,int s){
    if(i==v.size())return 0;
    if(memo[i][s])return memo[i][s];
    if(s==0){
        return memo[i][s]=max(dp(i+1,0),dp(i+1,1)-v[i]);
    }
    else return memo[i][s]=max(dp(i+1,0)+v[i],dp(i+1,1));
}
int Solution::maxProfit(const vector<int> &A) {
    if(A.size()==0)return 0;
    v=A;
    memset(memo,0,sizeof(memo));
    return dp(0,0);
}
