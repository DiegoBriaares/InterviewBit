#define MAX 50002
struct node {
  bool fin;
  int sons[26];
};
node trie[MAX];
int m;
vector<string>r;
void add(string v){
    int pos=1;
    for(int i=0;i<v.size();i++){
        int l=v[i]-'a';
        if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
        pos=trie[pos].sons[l];
    }
    trie[pos].fin=true;
}
void solve(string v,string uso,int pos,int i){
    if(i==v.size()){
        r.push_back(uso);
        return;
    }
    while(i<v.size()){
        if(trie[pos].sons[v[i]-'a']){
            uso.push_back(v[i]);
            pos=trie[pos].sons[v[i]-'a'];
            if(trie[pos].fin){
                string uso2;
                if(i<v.size()-1)uso2=uso+' ';
                else uso2=uso;
                solve(v,uso2,1,i+1);
            }
        }
        else break;
        i++;
    }
}
vector<string> Solution::wordBreak(string A, vector<string> &B) {
    memset(trie,0,sizeof(trie));
    r.clear();
    m=1;
    for(int i=0;i<B.size();i++){
        add(B[i]);
    }
    solve(A,"",1,0);
    sort(r.begin(),r.end());
    return r;
}
