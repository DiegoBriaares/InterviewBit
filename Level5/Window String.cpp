string Solution::minWindow(string S, string T) {
    int in=0,fin=0,c=0,a=0,r=0;
    unordered_map<char,int>memo;
    for(int i=0;i<T.size();i++){
        if(memo.find(T[i])==memo.end()){
            memo[T[i]]=1;
        }
        else memo[T[i]]++;
    }
    for(int i=0;i<S.size();i++,fin++){
        if(memo.find(S[i])==memo.end())continue;
        memo[S[fin]]--;
        if(memo[S[fin]]>=0)c++;
        if(c==T.size()){
            while(memo.find(S[in])==memo.end()||memo[S[in]]<0){
                if(memo.find(S[in])!=memo.end())memo[S[in]]++;
                in++;
            }
            if(r==0||fin-in+1<r){
                r=fin-in+1;
                a=in;
            }
        }
    }
    return S.substr(a,r);
}
