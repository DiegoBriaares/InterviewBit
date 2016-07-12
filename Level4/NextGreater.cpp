vector<int> Solution::nextGreater(vector<int> &A) {
    stack<int>pila;
    pila.push(0);
    vector<int>r;
    r.push_back(-1);
    for(int i=1;i<A.size();i++){
        r.push_back(-1);
        int j=A[i];
        while(!pila.empty()&&j>A[pila.top()]){
            r[pila.top()]=j;
            pila.pop();
        }
        pila.push(i);
    }
    return r;
}
