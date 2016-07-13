int Solution::atoi(const string &A) {
    long long r=0,uso=1;
    bool ok=false;
    stack<char>pila;
    for(int i=0;i<A.size();i++){
        if(A[i]>=48&&A[i]<=58)pila.push(A[i]);
        if(A[i]==' '&&!pila.empty()||A[i]==' '&&ok)break;
        if(pila.empty()&&A[i]=='-'){
        	uso=-1;
        	ok=true;
        	continue;
		}
		if(pila.empty()&&A[i]=='+'){
        	ok=true;
        	continue;
		}
		if(!(A[i]>=48&&A[i]<=58)&&A[i]!=' ')break;
    }
    for(long long i=1;!pila.empty();i*=10){
        r+=(long long)((pila.top()-'0')*(i));
        if(r>=INT_MAX&&uso==1)return INT_MAX;
        if(r>=INT_MAX&&uso==-1)return INT_MIN;
        pila.pop();
    }
    r*=uso;
    return r;
}
