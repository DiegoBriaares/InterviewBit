map<string,bool>mapa;
map<string,bool>memo;
map<string,int>DP;
bool ok;
string fin;
int dp(string v){
    if(v==fin){
        ok=true;
        return 0;
    }
    if(DP[v])return DP[v];
    int mini=(1<<30);
    for(int i=0;i<v.size();i++){
        char uso=v[i];
        for(int j='a';j<='z';j++){
            if(j!=uso){
            	v[i]=j;
            	if(mapa[v]&&!memo[v]||v==fin){
            		memo[v]=true;
            		mini=min(mini,1+dp(v));
            		memo[v]=false;
				}
			}
        }
        v[i]=uso;
    }
    return DP[v]=mini;
}
int Solution::ladderLength(string start, string end, vector<string> &dictV) {
    fin=end;
    ok=false;
    DP.clear();
    mapa.clear();
    memo.clear();
    for(int i=0;i<dictV.size();i++){
        mapa[dictV[i]]=true;
    }
    int r=1+dp(start);
    if(!ok)r=0;
    return r;
}
