int memo[1000002];
int Solution::longestValidParentheses(string A) {
    memset(memo,0,sizeof(memo));
    stack<int>pila;
    int r=0;
    for(int i=0;i<A.size();i++){
        if(A[i]=='(')pila.push(i);
        else if(!pila.empty()) {
            int dist=(i-pila.top())+1;
            memo[i]=dist;
            memo[i]+=memo[i-dist];
            r=max(r,memo[i]);
            pila.pop();
        }
    }
    while(!pila.empty())pila.pop();
    return r;
}
