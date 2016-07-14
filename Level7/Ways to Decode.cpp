string v;
int memo[1002];
int dp(int i){
    if(i==v.size())return 1;
    if(i>v.size()||v[i]=='0')return 0;
    if(memo[i])return memo[i];
    if(v[i]>='1')memo[i]+=dp(i+1);
    if(i+1<v.size()&&v[i]=='1')memo[i]+=dp(i+2);
    if(i+1<v.size()&&v[i]=='2'&&v[i+1]<='6')memo[i]+=dp(i+2);
    return memo[i];
}
int Solution::numDecodings(string A) {
    v=A;
    memset(memo,0,sizeof(memo));
    return dp(0);
}
