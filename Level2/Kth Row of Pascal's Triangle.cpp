long long m[102][102];
bool ok=false;
void pascal(){
    if(ok)return;
    m[1][1]=1;
    m[2][1]=1;
    m[2][2]=1;
    for(int i=3;i<=100;i++){
        m[i][1]=1;
        m[i][i]=1;
        for(int j=2;j<i;j++){
            m[i][j]=m[i-1][j]+m[i-1][j-1];
        }
    }
    ok=true;
}
vector<int> Solution::getRow(int n) {
    pascal();
    n++;
    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(m[n][i]);
    }
    return v;
}
