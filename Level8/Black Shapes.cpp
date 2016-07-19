vector<string>v;
void dfs(int i,int j){
    if(i>=v.size()||i<0||j>=v[i].size()||j<0)return;
    if(v[i][j]!='X')return;
    v[i][j]='0';
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i-1,j);
    dfs(i,j-1);
}
int Solution::black(vector<string> &A) {
    v=A;
    int r=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]=='X')dfs(i,j),r++;
        }
    }
    return r;
}
