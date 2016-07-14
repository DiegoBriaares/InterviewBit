int memo[1001];
int dp(int x){
	if(x==1)return 1;
	if(memo[x])return memo[x];
	int s=0;
	for(int i=1;i<x;i++){
		s+=((dp(i))*dp(x-i));
	}
	return memo[x]=s;
}
int Solution::numTrees(int A) {
   memset(memo,0,sizeof(memo));
   return dp(A+1);
}
