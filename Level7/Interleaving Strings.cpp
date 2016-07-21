string a,b,v;
bool dp(int in,int i,int j){
    if(in==v.size())return true;
    if(i==a.size()&&j==b.size())return false;
    bool uso=false;
    if(i<a.size()&&v[in]==a[i])uso=dp(in+1,i+1,j);
    if(uso)return true;
    if(j<b.size()&&v[in]==b[j])uso=dp(in+1,i,j+1);
    if(uso)return true;
    return false;
}
int Solution::isInterleave(string A, string B, string C) {
    a=A;
    b=B;
    v=C;
    return dp(0,0,0);
}
