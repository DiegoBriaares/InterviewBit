struct solve {
  int i,j,d;
  solve(int x,int y,int z):i(x),j(y),d(z){}
};
int p=2,q=1;
int dx[]={-p,-q,q,p,p,q,-q,-p};
int dy[]={q,p,p,q,-q,-p,-p,-q};
bool memo[1002][1002];
int Solution::knight(int N, int M, int x1, int y1, int x2, int y2) {
    memset(memo,false,sizeof(memo));
    queue<solve>cola;
    solve in(x1,y1,0);
    cola.push(in);
    while(!cola.empty()){
        solve now=cola.front();
        cola.pop();
        if(now.i==x2&&now.j==y2){
            return now.d;
        }
        if(memo[now.i][now.j])continue;
        memo[now.i][now.j]=true;
        for(int i=0;i<8;i++){
            int x=now.i+dx[i];
            int y=now.j+dy[i];
            if(x>0&&x<=N&&y>0&&y<=M){
                solve r(x,y,now.d+1);
                cola.push(r);
            }
        }
    }
    return -1;
}
