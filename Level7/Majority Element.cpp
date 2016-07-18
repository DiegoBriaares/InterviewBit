int Solution::majorityElement(const vector<int> &A) {
    map<int,int>memo;
    for(int i=0;i<A.size();i++){
        memo[A[i]]++;
    }
    int r=0;
    for(map<int,int>::iterator it=memo.begin();it!=memo.end();it++){
        if(it->second>(A.size()/2))r=max(it->first,r);
    }
    return r;
}
