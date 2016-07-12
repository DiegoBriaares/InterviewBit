vector<string>r;
bool check(string v){
    stack<int>pila;
    for(int i=0;i<v.size();i++){
        if(v[i]=='(')pila.push(0);
        else {
            if(pila.empty())return false;
            pila.pop();
        }
    }
    if(pila.empty())return true;
    return false;
}
void solve(int n,string v){
    if(n==0){
        if(check(v))r.push_back(v);
        return;
    }
    solve(n-1,v+'(');
    solve(n-1,v+')');
}
vector<string> Solution::generateParenthesis(int A) {
    r.clear();
    if(A==0)return r;
    solve(A*2,"");
    sort(r.begin(),r.end());
    return r;
}
