vector<int> Solution::dNums(vector<int> &A, int k) {
    int in=0,fin=k-1,r=0;
    vector<int>res;
    map<int,int>memo;
    for(int i=0;i<A.size();i++){
        if(i<k-1){
            if(memo[A[i]]<=0){
            	memo[A[i]]=1;
            	r++;
			}
            else memo[A[i]]++;
        }
        else {
            if(memo[A[i]]<=0)r++;
            memo[A[i]]++;
            res.push_back(r);
            if(memo[A[in]]==1)r--;
            memo[A[in]]--;
            in++;
        }
    }
    return res;
}
