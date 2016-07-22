#define MAX 1002
int memo[MAX][MAX];
string v;
bool ispa(int i,int j){
    while(i<=j){
        if(v[i]!=v[j])return false;
        i++;
        j--;
    }
    return true;
}
int dp(int in,int i){
    if(i==v.size()){
        if(!ispa(in,i-1))return (1<<30);
        else return 0;
    }
    if(memo[in][i])return memo[in][i];
    if(ispa(in,i)){
        return memo[in][i]=min(1+dp(i+1,i+1),dp(in,i+1));
    }
    else {
        return memo[in][i]=dp(in,i+1);
    }
}
int Solution::minCut(string A) {
    v=A;
    int r=(A.size()-1);
    memset(memo,0,sizeof(memo));
    return min(r,dp(0,0));
}
