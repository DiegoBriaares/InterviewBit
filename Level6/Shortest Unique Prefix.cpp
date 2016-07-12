#define MAX 50002
struct node {
    int many;
    int sons[26];
};
node trie[MAX];
int m=1;
void add(string v){
    int pos=1;
    for(int i=0;i<v.size();i++){
        int l=(v[i]-'a');
        if(!trie[pos].sons[l])trie[pos].sons[l]=++m;
        pos=trie[pos].sons[l];
        trie[pos].many++;
    }
}
string query(string v){
    int pos=1;
    string r="";
    for(int i=0;i<v.size();i++){
        r+=(v[i]);
        int l=(v[i]-'a');
        pos=trie[pos].sons[l];
        if(trie[pos].many==1)return r;
    }
    return v;
}
vector<string> Solution::prefix(vector<string> &A) {
    memset(trie,0,sizeof(trie));
    for(int i=0;i<A.size();i++){
        add(A[i]);
    }
    vector<string>res;
    for(int i=0;i<A.size();i++){
        res.push_back(query(A[i]));
    }
    return res;
}
